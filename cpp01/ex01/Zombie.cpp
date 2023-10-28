/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 23:22:20 by bamrouch          #+#    #+#             */
/*   Updated: 2023/10/28 20:39:19 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie():name("")
{}

Zombie::Zombie(std::string z_name)
{
    name = z_name;
}

Zombie::Zombie(const Zombie *zombie)
{
    name = zombie->name;
}

Zombie &Zombie::operator=(const Zombie *zombie)
{
    this->name = zombie->name;
    return *this;
}

Zombie::~Zombie(void)
{
    std::cout << name << ":" << "Gguhhhhh..." << std::endl;
}

void Zombie::announce(void)
{
    std::cout << name << ":" << "BraiiiiiiinnnzzzZ..." << std::endl;
}

