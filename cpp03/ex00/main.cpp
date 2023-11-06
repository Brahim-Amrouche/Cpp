/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 13:20:03 by bamrouch          #+#    #+#             */
/*   Updated: 2023/11/06 16:58:06 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    ClapTrap    default_clapi("bomba");
    ClapTrap    clapi("real clapi");

    default_clapi.attack("real clapi");
    // default_clapi.beRepaired(10);
    default_clapi.takeDamage(10);
    default_clapi.takeDamage(100);
    default_clapi.takeDamage(1000);
    
    size_t i = -1;
    while (++i < 10)
    {
        clapi.attack("someone");
    }
    clapi.attack("different");
    clapi.beRepaired(10);
    clapi.takeDamage(10);
}

