/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 10:53:14 by bamrouch          #+#    #+#             */
/*   Updated: 2023/09/24 14:48:18 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "iostream"
#include "string"

using std::string;
using std::cout;
using std::endl;

class AbstractAnimal
{
    protected:
        string type; 
        AbstractAnimal();
        AbstractAnimal(string new_type);
        AbstractAnimal(const AbstractAnimal &cpy_animal);
    public:
        virtual AbstractAnimal &operator=(const AbstractAnimal &eq_animal);
        string  getType(void) const;
        void    setType(string new_type);
        virtual void makeSound() const;
        virtual ~AbstractAnimal();
};

