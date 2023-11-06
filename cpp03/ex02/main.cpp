/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 17:15:04 by bamrouch          #+#    #+#             */
/*   Updated: 2023/11/06 17:37:00 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
    FragTrap two("two");

    two.attack("clampi");
    two.beRepaired(10);
    two.takeDamage(10);
    // two.takeDamage(100);
    // two.takeDamage(100);
    two.highFivesGuys();

    size_t i = 2;
    while (++i < 100)
    {
        two.attack("rusty");
    }
    two.attack("dusty");
    two.beRepaired(5);
    two.takeDamage(100);
    two.highFivesGuys();
}