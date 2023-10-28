/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 23:22:56 by bamrouch          #+#    #+#             */
/*   Updated: 2023/10/28 20:41:18 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "iostream"
#include "string"

using std::string;
using std::cout;
using std::cerr;
using std::endl;

class Zombie
{
    private :
        string name;
    public :
        Zombie(void);
        Zombie(string name);
        Zombie(const Zombie *zombie);
        Zombie &operator=(const Zombie *zombie);
        ~Zombie(void);
        void    announce(void);
        Zombie  *newZombie(string name);
        void    randomChump(string name);
};
