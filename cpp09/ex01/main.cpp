/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:53:27 by bamrouch          #+#    #+#             */
/*   Updated: 2023/12/16 10:54:55 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"


int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        cout << "Error: Wrong Arguments" << endl;
        return (1);
    }
    try{
        Rpn executer(argv[1]);
    }
    catch (const Rpn::RpnException &e)
    {
        cout << e.what() << endl;
        return (1);
    }
    return (0);
}