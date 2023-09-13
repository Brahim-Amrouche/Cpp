/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 23:22:20 by bamrouch          #+#    #+#             */
/*   Updated: 2023/09/10 23:29:52 by bamrouch         ###   ########.fr       */
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

Zombie  *zombieHorde(int N, std::string name)
{

}
