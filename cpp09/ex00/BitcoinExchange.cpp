/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 12:58:41 by bamrouch          #+#    #+#             */
/*   Updated: 2023/12/24 18:49:19by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// CsvHash

const char *CsvHash::FileOpenFailed::what() const throw()
{
    return "Coulndn't Open `data.csv` file";
}

CsvHash::WrongCsvFormat::WrongCsvFormat(const int new_err): err_c(new_err)
{}

CsvHash::WrongCsvFormat::~WrongCsvFormat() throw()
{}

const char *CsvHash::WrongCsvFormat::what() const throw()
{
    switch (err_c)
    {
        case WRONG_HEADER:
            return "Wrong header in data file";
        case EMPTY_DATA:
            return "Empty Csv data";
        case BAD_CSV_FORMAT:
            return "Bad Csv Format";
        case INVALID_DATE:
            return "Invalid date format";
        case INVALID_PRICE:
            return "Invalid price";
        case DUPLICATE_DATE:
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
        throw CsvHash::WrongCsvFormat(WRONG_HEADER);
    while (std::getline(ifs, buff))
        hashPrices(buff);
    if (date_prices.empty())
        throw CsvHash::WrongCsvFormat(EMPTY_DATA);
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

void validate_day(const int &year,const int &month,const int &day)
{
    if (day <= 0)
        throw CsvHash::WrongCsvFormat(INVALID_DATE);
    if ((month == 1 || month == 3 || month == 5 
    || month == 7 || month == 8 || month == 10 || month == 12) && day > 31)
        throw CsvHash::WrongCsvFormat(INVALID_DATE);
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        throw CsvHash::WrongCsvFormat(INVALID_DATE);
    if (month == 2 && ((year % 4 && day > 29) || day > 28))
        throw CsvHash::WrongCsvFormat(INVALID_DATE);
}

void parse_date(string &date)
{
    string s_year, s_month, s_day;
    int v_year, v_month, v_day;
    size_t first_minus, second_minus;
    if ((first_minus = date.find_first_of('-')) == string::npos)
        throw CsvHash::WrongCsvFormat(INVALID_DATE);
    s_year = date.substr(0, first_minus);
    if (s_year.size() == 0 || (v_year = str_to_int(s_year)) <= 0)
        throw CsvHash::WrongCsvFormat(INVALID_DATE);
    if ((second_minus = date.find_first_of('-', first_minus + 1)) == string::npos
        || second_minus - first_minus != 3)
        throw CsvHash::WrongCsvFormat(INVALID_DATE);
    s_month = date.substr(first_minus + 1, 2);
    if (s_month.size() < 2 || (v_month = str_to_int(s_month)) <= 0)
        throw CsvHash::WrongCsvFormat(INVALID_DATE);
    if (v_month < 1 || v_month > 12)
        throw CsvHash::WrongCsvFormat(INVALID_DATE);
    s_day = date.substr(second_minus + 1, 2);
    if (s_day.size() < 2 || (v_day = str_to_int(s_day)) <= 0)
        throw CsvHash::WrongCsvFormat(INVALID_DATE);
    validate_day(v_year, v_month, v_day);
    if (date.size() > second_minus + 2)
        throw CsvHash::WrongCsvFormat(INVALID_DATE);
}

double  parse_price(string &s_price)
{
    if (s_price.size() == 0)
        throw CsvHash::WrongCsvFormat(INVALID_PRICE);
    size_t i = -1;
    bool  point_set = false;
    while (++i < s_price.size())
    {
        if (std::isdigit(s_price[i]))
            continue;
        else if (s_price[i] == '.' && !point_set)
            point_set = true;
        else
            throw CsvHash::WrongCsvFormat(INVALID_PRICE);
    }
    const char *start = s_price.c_str();
    char *end;
    double v_price = std::strtod(start, &end);
    if (start == end || v_price < 0)
        throw CsvHash::WrongCsvFormat(INVALID_PRICE);
    return v_price;
}

void    CsvHash::hashPrices(string &row)
{
    size_t comma_pos;
    if ((comma_pos = row.find_first_of(',')) == string::npos)
        throw CsvHash::WrongCsvFormat(BAD_CSV_FORMAT);
    string date = row.substr(0, comma_pos);
    parse_date(date);
    string price = row.substr(comma_pos + 1);
    double val = parse_price(price);
    if (date_prices.find(date) != date_prices.end())
        throw CsvHash::WrongCsvFormat(DUPLICATE_DATE);
    date_prices.insert(std::pair<string, double>(date, val));
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
        throw CsvHash::WrongCsvFormat(INVALID_PRICE);
}

CsvHash::CsvHash(const CsvHash &cpy_csv)
{
    (void) cpy_csv;
}

CsvHash &CsvHash::operator=(const CsvHash &eq_csv)
{
    (void) eq_csv;
    return (*this);
}

CsvHash::~CsvHash()
{};

// BtcWallet
BtcWallet::BtcWalletExcept::BtcWalletExcept(BTCWALLET_ERR err_c, string info): code(err_c), info_data("Error: ")
{
    switch(code)
    {
        case (WRONG_FILE):
            info_data += "could not open file.";
            break;
        case (WRONG_FILE_FORMAT):
            info_data += "wrong file format";
            info_data += info;
            break;
        case (BAD_DATE):
            info_data += "bad input =>";
            info_data += info;
            break;
        case (NEGATIVE_COUNT):
            info_data += "not a positive number.";
            break;
        case (GREAT_COUNT):
            info_data += "too large a number.";
            break;
        default:
            info_data += "unknown error";
    }
};

const char *BtcWallet::BtcWalletExcept::what() const throw()
{
    return info_data.c_str();
}

BtcWallet::BtcWalletExcept::~BtcWalletExcept() throw()
{};


BtcWallet::BtcWallet()
{};

BtcWallet::BtcWallet(const string &path, CsvHash &data):csv_data(&data)
{
    ifs.open(path.c_str(), std::ios::in);
    if (!ifs.is_open())
        throw BtcWallet::BtcWalletExcept(WRONG_FILE, "");
    string buff;
    std::getline(ifs, buff);
    if (buff != INPUT_HEADER)
        throw BtcWallet::BtcWalletExcept(WRONG_FILE_FORMAT, ": invalid header");
    while (std::getline(ifs, buff))
    {
        try
        {
            handleLine(buff);
        }
        catch (const BtcWallet::BtcWalletExcept &e)
        {
            cout << e.what() << endl;
        }
    }
}

BtcWallet::BtcWallet(const BtcWallet &cpy_btc):csv_data(cpy_btc.csv_data)
{}

BtcWallet &BtcWallet::operator=(const BtcWallet &eq_btc)
{
    (void) eq_btc;
    return (*this);
}

double parse_value(const string &s_value)
{
    if (s_value.size() == 0)
        throw BtcWallet::BtcWalletExcept(WRONG_FILE_FORMAT, ": no value supplied");
    size_t i = -1;
    bool point_set = false;
    while (++i < s_value.size())
    {
        if (std::isdigit(s_value[i]))
            continue;
        else if (s_value[i] == '.' && !point_set)
            point_set = true;
        else if (s_value[i] == '-')
            throw BtcWallet::BtcWalletExcept(NEGATIVE_COUNT,"");
        else
            throw BtcWallet::BtcWalletExcept(WRONG_FILE_FORMAT, ": wrong value format");
    }
    const char *start = s_value.c_str();
    char *end;
    double v_value = std::strtod(start, &end);
    if (start == end || v_value < 0 || v_value > 1000)
        throw BtcWallet::BtcWalletExcept(GREAT_COUNT, "");
    return v_value;
}

void BtcWallet::handleLine(const string &line)
{
    size_t first_space = line.find_first_of(' ');
    if (first_space == string::npos || line[first_space + 1] != '|'
        || line[first_space + 2] != ' ')
        throw BtcWallet::BtcWalletExcept(WRONG_FILE_FORMAT, ": invalid line formating");
    string date = line.substr(0, first_space);
    if (date.size() == 0)
        throw BtcWallet::BtcWalletExcept(WRONG_FILE_FORMAT, ": no date supplied");
    double price = -1, value = -1;
    try
    {
        price = csv_data->getPrice(date);
    }
    catch (const CsvHash::WrongCsvFormat &e)
    {       
        if (e.err_c == INVALID_PRICE)
            cout << "Error: no valid date price found" << endl;
        else if (e.err_c == INVALID_DATE)
            throw BtcWallet::BtcWalletExcept(BAD_DATE, date);
        return;
    }
    string s_value = line.substr(first_space + 2);
    try
    {
        value = parse_value(s_value);
    }
    catch(const BtcWallet::BtcWalletExcept& e)
    {
        std::cout << e.what() << endl;
        return;
    }
    cout << date << "=>" << s_value << " = " << value * price << endl;
}

BtcWallet::~BtcWallet()
{}

