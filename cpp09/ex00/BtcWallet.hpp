/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BtcWallet.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 10:31:30 by bamrouch          #+#    #+#             */
/*   Updated: 2023/12/14 12:06:57 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "CsvHash.hpp"
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
        BtcWallet(const string &path, CsvHash &data);
        BtcWallet(const BtcWallet &cpy_btc);
        BtcWallet &operator=(const BtcWallet &eq_btc);
        void    handleLine(const string &line);
        ~BtcWallet();
};
