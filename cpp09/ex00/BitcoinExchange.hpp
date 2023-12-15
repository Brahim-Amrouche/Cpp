/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 12:58:16 by bamrouch          #+#    #+#             */
/*   Updated: 2023/12/15 16:23:24 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <ostream>
#include <fstream>
#include <string>
#include <map>
#include <exception>
#include <limits.h>
#include <utility>

using std::ifstream;
using std::string;
using std::map;
using std::exception;
using std::cout;
using std::endl;

// CSV_HASH
#define DATA_FILE "data.csv"
#define CSV_HEADER "date,exchange_rate"
enum CSV_ERRORS
{
    WRONG_HEADER,
    EMPTY_DATA,
    BAD_CSV_FORMAT,
    INVALID_DATE,
    INVALID_PRICE,
    DUPLICATE_DATE,
};

int     str_is_int(string &str);
void    parse_date(string &date);

class CsvHash
{
    private:
        ifstream ifs;
        map<string, double>    date_prices;
    public:
        class FileOpenFailed : public exception
        {
            public:
                const char *what() const throw();
        };
        class WrongCsvFormat : public exception
        {
            public:
                int err_c;
                WrongCsvFormat(const int new_err);
                const char *what() const throw();
                ~WrongCsvFormat() throw();         
        };
        CsvHash();
        CsvHash(const CsvHash &cpy_csv);
        CsvHash &operator=(const CsvHash &eq_csv);
        void hashPrices(string &row);
        double getPrice(string &date);
        ~CsvHash();
};

// BtcWallet
#define INPUT_HEADER "date | value"

enum BTCWALLET_ERR
{
    WRONG_FILE,
    WRONG_FILE_FORMAT,
    BAD_DATE,
    NEGATIVE_COUNT,
    GREAT_COUNT,
};

class BtcWallet
{
    private:
        CsvHash &csv_data;
        ifstream ifs;
    public:
        class BtcWalletExcept : public exception
        {
            private:
                BTCWALLET_ERR code;
                string        info_data;
            public:
                BtcWalletExcept(BTCWALLET_ERR err_c, string info);
                const char *what() const throw();
                ~BtcWalletExcept() throw();
        };
        BtcWallet();
        BtcWallet(const string &path, CsvHash &data);
        BtcWallet(const BtcWallet &cpy_btc);
        BtcWallet &operator=(const BtcWallet &eq_btc);
        void    handleLine(const string &line);
        ~BtcWallet();
};


