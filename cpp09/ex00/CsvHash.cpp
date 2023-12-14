/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CsvHash.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 10:35:43 by bamrouch          #+#    #+#             */
/*   Updated: 2023/12/14 13:35:07 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CsvHash.hpp"

const char *CsvHash::FileOpenFailed::what() const throw()
{
    return "Coulndn't Open `data.csv` file";
}

CsvHash::WrongCsvFormat::WrongCsvFormat(const int new_err): err_c(new_err)
{}

const char *CsvHash::WrongCsvFormat::what() const throw()
{
    switch (err_c)
    {
        case CSV_ERRORS::WRONG_HEADER:
            return "Wrong header in data file";
        case CSV_ERRORS::EMPTY_DATA:
            return "Empty Csv data";
        case CSV_ERRORS::BAD_CSV_FORMAT:
            return "Bad Csv Format";
        case CSV_ERRORS::INVALID_DATE:
            return "Invalid date format";
        case CSV_ERRORS::INVALID_PRICE:
            return "Invalid price";
        case CSV_ERRORS::DUPLICATE_DATE:
            return "Duplicated Date key";
        default:
            return "Undefined Error";
    }
}

CsvHash::CsvHash()
{
    ifs.open("data.csv", std::ios::in);
    if (!ifs.is_open())
        throw CsvHash::FileOpenFailed();
    string buff;
    std::getline(ifs, buff);
    if (buff != CSV_HEADER)
        throw CsvHash::WrongCsvFormat(CSV_ERRORS::WRONG_HEADER);
    while (std::getline(ifs, buff))
        hashPrices(buff);
    if (date_prices.empty())
        throw CsvHash::WrongCsvFormat(CSV_ERRORS::EMPTY_DATA);
}

int    str_to_int(string &str)
{
    size_t i = -1;
    while (str[++i])
    {
        if (!std::isdigit(str[i]) && i < 10)
            return -1;
    }

    char *end;
    long n = std::strtol(str.c_str(), &end, 10);
    if (n > INT_MAX || n <= 0)
        return -1;
    return n;
}

bool validate_day(const int &year,const int &month,const int &day)
{
    if (day <= 0)
        throw CsvHash::WrongCsvFormat(CSV_ERRORS::INVALID_DATE);
    if ((month == 1 || month == 3 || month == 5 
    || month == 7 || month == 8 || month == 10 || month == 12) && day > 31)
        throw CsvHash::WrongCsvFormat(CSV_ERRORS::INVALID_DATE);
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        throw CsvHash::WrongCsvFormat(CSV_ERRORS::INVALID_DATE);
    if (month == 2 && ((year % 4 && day > 29) || day > 28))
        throw CsvHash::WrongCsvFormat(CSV_ERRORS::INVALID_DATE);
}

void parse_date(string &date)
{
    string s_year, s_month, s_day;
    int v_year, v_month, v_day;
    size_t first_minus, second_minus;
    if ((first_minus = date.find_first_of('-')) == string::npos)
        throw CsvHash::WrongCsvFormat(CSV_ERRORS::INVALID_DATE);
    s_year = date.substr(0, first_minus);
    if (s_year.size() == 0 || (v_year = str_is_int(s_year)) <= 0)
        throw CsvHash::WrongCsvFormat(CSV_ERRORS::INVALID_DATE);
    if ((second_minus = date.find_first_of('-', first_minus + 1)) == string::npos
        || second_minus - first_minus != 3)
        throw CsvHash::WrongCsvFormat(CSV_ERRORS::INVALID_DATE);
    s_month = date.substr(first_minus + 1, 2);
    if (s_month.size() < 2 || (v_month = str_is_int(s_month)) <= 0)
        throw CsvHash::WrongCsvFormat(CSV_ERRORS::INVALID_DATE);
    if (v_month < 1 || v_month > 12)
        throw CsvHash::WrongCsvFormat(CSV_ERRORS::INVALID_DATE);
    s_day = date.substr(second_minus + 1, 2);
    if (s_day.size() < 2 || (v_day = str_is_int(s_day)) <= 0)
        throw CsvHash::WrongCsvFormat(CSV_ERRORS::INVALID_DATE);
    validate_day(v_year, v_month, v_day);
    if (date.size() > second_minus + 2)
        throw CsvHash::WrongCsvFormat(CSV_ERRORS::INVALID_DATE);
}

double  parse_price(string &s_price)
{
    if (s_price.size() == 0)
        throw CsvHash::WrongCsvFormat(CSV_ERRORS::INVALID_PRICE);
    size_t i = -1;
    bool  point_set = false;
    while (++i < s_price.size())
    {
        if (std::isdigit(s_price[i]))
            continue;
        else if (s_price[i] == '.' && !point_set)
            point_set = true;
        else
            throw CsvHash::WrongCsvFormat(CSV_ERRORS::INVALID_PRICE);
    }
    const char *start = s_price.c_str();
    char *end;
    double v_price = std::strtod(start, &end);
    if (start == end || v_price < 0)
        throw CsvHash::WrongCsvFormat(CSV_ERRORS::INVALID_PRICE);
    return v_price;
}

void    CsvHash::hashPrices(string &row)
{
    size_t comma_pos;
    if ((comma_pos = row.find_first_of(',')) == string::npos)
        throw CsvHash::WrongCsvFormat(CSV_ERRORS::BAD_CSV_FORMAT);
    string date = row.substr(0, comma_pos);
    parse_date(date);
    string price = row.substr(comma_pos + 1);
    double val = parse_price(price);
    if (date_prices.find(date) != date_prices.end())
        throw CsvHash::WrongCsvFormat(CSV_ERRORS::DUPLICATE_DATE);
    date_prices.insert(date, price);
}

double    CsvHash::getPrice(string &date)
{
    parse_date(date);
    if (date_prices.find(date) != date_prices.end())
        return date_prices[date];
    map<string, double>::iterator prev = date_prices.lower_bound(date);
    if (prev != date_prices.end())
        return prev->second;
    else
        throw CsvHash::WrongCsvFormat(CSV_ERRORS::INVALID_PRICE);
}

CsvHash::CsvHash(const CsvHash &cpy_csv)
{
}

CsvHash &CsvHash::operator=(const CsvHash &eq_csv)
{
    return (*this);
}

CsvHash::~CsvHash()
{};
