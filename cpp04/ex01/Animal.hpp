/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 20:13:35 by bamrouch          #+#    #+#             */
/*   Updated: 2023/11/08 20:13:37 by bamrouch         ###   ########.fr       */
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
        string type; 
    public:
        Animal();
        Animal(string new_type);
        Animal(const Animal &cpy_animal);
        Animal  &operator=(const Animal &eq_animal);
        string  getType(void) const;
        virtual void makeSound() const;
        virtual ~Animal();
};

