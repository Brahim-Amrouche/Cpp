/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 11:22:04 by bamrouch          #+#    #+#             */
/*   Updated: 2023/09/20 11:40:49 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#define hordeCount 10
int main()
{
    Zombie starter= Zombie();

    Zombie *horde = starter.zombieHorde(hordeCount, "Jorge");
    if (horde)
    {
        size_t i= -1;
        while (++i < hordeCount)
            horde[i].announce();
        delete[] horde;
    }
}
