/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 23:22:41 by bamrouch          #+#    #+#             */
/*   Updated: 2023/10/28 20:38:58 by bamrouch         ###   ########.fr       */
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
        Zombie(void);
        Zombie(std::string name);
        Zombie(const Zombie *zombie);
        Zombie &operator=(const Zombie *zombie);
        ~Zombie(void);
        void    announce(void);
        Zombie  *zombieHorde(int N, std::string name);
};
