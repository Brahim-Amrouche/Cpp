/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:16:13 by bamrouch          #+#    #+#             */
/*   Updated: 2023/10/28 21:36:03 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
    Harl harl = Harl();
    harl.complain("DEBUG");
    cout << "Debug ended" << endl;
    harl.complain("INFO");
    cout << "Info ended" << endl;
    harl.complain("WARNING");
    cout << "WARNING ended" << endl; 
    harl.complain("ERROR");
    cout << "ERROR ended" << endl;
    harl.complain("FIFI");
    harl.complain("KIKI");
}
