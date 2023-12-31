/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 23:08:44 by bamrouch          #+#    #+#             */
/*   Updated: 2023/09/10 23:12:57 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *Zombie::newZombie(string name)
{
    Zombie *ptr;

    ptr = new Zombie(name);
    if (!ptr)
        cerr << "couldn't allocate for a new zombie" << endl;
    return (ptr);
}
