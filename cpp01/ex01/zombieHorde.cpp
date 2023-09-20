/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 23:30:22 by bamrouch          #+#    #+#             */
/*   Updated: 2023/09/20 11:38:55 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *Zombie::zombieHorde(int N, std::string name)
{
    if (N <= 0)
        std::cerr << "not a valid number for a zombie horde" << std::endl;
    
    Zombie *zombies = new Zombie[N];
    if (!zombies)
    {
        std::cerr << "couldn't allocate zombies" << std::endl;    
        return  zombies;
    }
    Zombie  cpy_zombie = Zombie(name);
    for (int i = 0; i < N; i++)
        zombies[i] = cpy_zombie;
    return (zombies);
}

