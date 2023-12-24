/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:03:55 by bamrouch          #+#    #+#             */
/*   Updated: 2023/12/24 19:35:31 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        cout << "Error: Wrong arguments given" << endl;
        return (1);
    }
    try
    {
        CsvHash csv_data;
        BtcWallet btc_wallet(argv[1], csv_data);
        return (0);
    }
    catch (const CsvHash::FileOpenFailed &e)
    {
        cout << e.what() << endl;
    }
    catch (const CsvHash::WrongCsvFormat &e)
    {
        cout << e.what() << endl;
    }
    catch (const BtcWallet::BtcWalletExcept &e)
    {
        cout << e.what() << endl;
    }
    return (1);
}