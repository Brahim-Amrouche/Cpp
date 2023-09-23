/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 17:15:04 by bamrouch          #+#    #+#             */
/*   Updated: 2023/09/23 17:24:17 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
    FragTrap two("two");

    two.attack("clampi");
    two.beRepaired(10);
    two.takeDamage(10);
    two.highFivesGuys();

    size_t i = 1;
    while (++i < 100)
    {
        two.attack("rusty");
    }
    two.attack("dusty");
    two.beRepaired(5);
}