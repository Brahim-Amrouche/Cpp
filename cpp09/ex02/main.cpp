/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 17:52:56 by bamrouch          #+#    #+#             */
/*   Updated: 2023/12/16 18:51:36 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char *argv[])
{
    if (argc < 2)
        cout << "Error: No input given" << endl;
    try
    {
        PmergeMe merger(argc, argv);
    }
    catch (const PmergeMe::PmergeMeExcept &e)
    {
        cout << e.what() << endl;
    }
}