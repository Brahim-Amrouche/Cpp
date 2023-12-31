/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 14:20:39 by bamrouch          #+#    #+#             */
/*   Updated: 2023/10/28 20:41:41 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie():name("")
{};

Zombie::Zombie(string z_name)
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
    cout << name << ":" << "Gguhhhhh..." << endl;
}

void Zombie::announce(void)
{
    cout << name << ":" << "BraiiiiiiinnnzzzZ..." << endl;
}
