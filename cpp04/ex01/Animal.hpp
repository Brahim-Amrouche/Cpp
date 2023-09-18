/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 10:53:14 by bamrouch          #+#    #+#             */
/*   Updated: 2023/09/18 15:24:24 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "iostream"
#include "string"

using std::string;
using std::cout;
using std::endl;

class Animal
{
    protected:
        string type = "evolving"; 
    public:
        Animal();
        Animal(string new_type);
        Animal(const Animal &cpy_animal);
        Animal  &operator=(const Animal &eq_animal);
        string  getType(void);
        virtual void makeSound();
        ~Animal();
};

