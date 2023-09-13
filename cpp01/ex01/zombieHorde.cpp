/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 23:30:22 by bamrouch          #+#    #+#             */
/*   Updated: 2023/09/10 23:54:58 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *Zombie::zombieHorde(int N, std::string name)
{
    if (N <= 0)
        std::cerr << "not a valid number for a zombie horde" << std::endl;
    Zombie *zombies = new Zombie[N];
    
    if (!zombies)
        std::cerr << "couldn't allocate zombies" << std::endl;    
    for (int i = 0; i < N; i++)
        zombies[i] = Zombie(name);
    return (zombies);
}

