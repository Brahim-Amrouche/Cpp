/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 23:22:41 by bamrouch          #+#    #+#             */
/*   Updated: 2023/09/20 11:49:27 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "iostream"
#include "string"

class Zombie
{
    private :
        std::string name;
    public :
        Zombie(void):name(""){};
        Zombie(std::string name);
        Zombie(const Zombie *zombie);
        Zombie &operator=(const Zombie *zombie);
        ~Zombie(void);
        void    announce(void);
        Zombie  *zombieHorde(int N, std::string name);
};
