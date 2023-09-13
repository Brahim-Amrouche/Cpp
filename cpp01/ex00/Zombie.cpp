/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 14:20:39 by bamrouch          #+#    #+#             */
/*   Updated: 2023/09/08 15:36:40 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

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
