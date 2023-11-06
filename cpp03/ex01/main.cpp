/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 16:54:17 by bamrouch          #+#    #+#             */
/*   Updated: 2023/11/06 19:19:38 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
    ScavTrap one("one");

    one.attack("jonas");
    one.beRepaired(10);
    one.takeDamage(100);
    // one.takeDamage(100);
    // one.takeDamage(100);
    one.guardGate();

    size_t i= 2;
    while (++i < 50)
    {
        one.attack("rusty");
    }   
    one.attack("dusty");
    one.beRepaired(10);
    one.takeDamage(10);
    one.guardGate();
}