/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 17:31:43 by bamrouch          #+#    #+#             */
/*   Updated: 2023/11/06 18:26:50 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main()
{
    DiamondTrap three("three");
    DiamondTrap uno(three);
    
    three.attack("clampi");
    three.beRepaired(10);
    three.takeDamage(10);
    three.guardGate();
    three.highFivesGuys();
    three.whoAmI();

    size_t i = 1;
    while (++i< 50)
    {
        three.attack("rusty");
    }
    three.attack("dusty");
    three.beRepaired(4);
}