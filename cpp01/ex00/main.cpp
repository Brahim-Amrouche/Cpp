/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 13:40:39 by bamrouch          #+#    #+#             */
/*   Updated: 2023/09/08 13:40:39 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Zombie.hpp"

int main ()
{
    Zombie x = Zombie();
    Zombie *y = x.newZombie("Walker");
    if (y)
    {
        y->announce();
        delete y;
    }
    x.randomChump("Fliper");
}