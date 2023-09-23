/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 16:54:17 by bamrouch          #+#    #+#             */
/*   Updated: 2023/09/23 17:02:40 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
    ScavTrap one("one");

    one.attack("jonas");
    one.beRepaired(10);
    one.takeDamage(3);
    one.guardGate();

    size_t i= 1;
    while (++i < 50)
    {
        one.attack("rusty");
    }   
    one.attack("dusty");
    one.beRepaired(10);
}