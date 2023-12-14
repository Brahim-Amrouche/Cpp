/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BtcWallet.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 10:34:57 by bamrouch          #+#    #+#             */
/*   Updated: 2023/12/14 15:01:47 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BtcWallet.hpp"

BtcWallet::BtcWalletExcept::BtcWalletExcept(BTCWALLET_ERR err_c, string info): code(err_c), info_data("Error: ")
{
    switch(code)
    {
        case (BTCWALLET_ERR::WRONG_FILE):
            info_data += "could could not open file.";
            break;
        case (BTCWALLET_ERR::WRONG_FILE_FORMAT):
            info_data += "wrong file format";
            info_data += info;
            break;
        case (BTCWALLET_ERR::BAD_DATE):
            info_data += "bad input =>";
            info_data += info;
            break;
        case (BTCWALLET_ERR::NEGATIVE_COUNT):
            info_data += "not a positive number.";
            break;
        case (BTCWALLET_ERR::GREAT_COUNT):
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

BtcWallet::BtcWalletExcept::~BtcWalletExcept()
{};


BtcWallet::BtcWallet(const string &path, CsvHash &data):csv_data(data)
{
    ifs.open(path, std::ios::in);
    if (!ifs.is_open())
        throw BtcWallet::BtcWalletExcept(BTCWALLET_ERR::WRONG_FILE, "");
    string buff;
    std::getline(ifs, buff);
    if (buff != INPUT_HEADER)
        throw BtcWallet::BtcWalletExcept(BTCWALLET_ERR::WRONG_FILE_FORMAT, ": invalid header");
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
    return (*this);
}

double parse_value(const string &s_value)
{
    if (s_value.size() == 0)
        throw BtcWallet::BtcWalletExcept(BTCWALLET_ERR::WRONG_FILE_FORMAT, ": no value supplied");
    size_t i = -1;
    bool point_set = false;
    while (++i < s_value.size())
    {
        if (std::isdigit(s_value[i]))
            continue;
        else if (s_value[i] == '.' && !point_set)
            point_set = true;
        else if (s_value[i] == '-')
            throw BtcWallet::BtcWalletExcept(BTCWALLET_ERR::NEGATIVE_COUNT,"");
        else
            throw BtcWallet::BtcWalletExcept(BTCWALLET_ERR::WRONG_FILE_FORMAT, ": wrong value format");
    }
    const char *start = s_value.c_str();
    char *end;
    double v_value = std::strtod(start, &end);
    if (start == end || v_value < 0 || v_value > 1000)
        throw BtcWallet::BtcWalletExcept(BTCWALLET_ERR::GREAT_COUNT, "");
    return v_value;
}

void BtcWallet::handleLine(const string &line)
{
    size_t first_space = line.find_first_of(' ');
    if (first_space == string::npos || line[first_space + 1] != '|'
        || line[first_space + 2] != ' ')
        throw BtcWallet::BtcWalletExcept(BTCWALLET_ERR::WRONG_FILE_FORMAT, ": invalid line formating");
    string date = line.substr(0, first_space);
    if (date.size() == 0)
        throw BtcWallet::BtcWalletExcept(BTCWALLET_ERR::WRONG_FILE_FORMAT, ": no date supplied");
    double price = -1, value = -1;
    try
    {
        price = csv_data.getPrice(date);
    }
    catch (const CsvHash::WrongCsvFormat &e)
    {
        
        if (e.err_c == CSV_ERRORS::INVALID_PRICE)
            cout << "Error: no valid date price found" << endl;
        else if (e.err_c == CSV_ERRORS::INVALID_DATE)
            throw BtcWallet::BtcWalletExcept(BTCWALLET_ERR::BAD_DATE, date);
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