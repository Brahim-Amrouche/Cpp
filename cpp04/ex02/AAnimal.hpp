/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 20:14:57 by bamrouch          #+#    #+#             */
/*   Updated: 2023/11/10 12:23:31 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "iostream"
#include "string"

using std::string;
using std::cout;
using std::endl;

class AAnimal
{
    protected:
        string type; 
        AAnimal();
        AAnimal(string new_type);
        AAnimal(const AAnimal &cpy_animal);
    public:
        virtual AAnimal &operator=(const AAnimal &eq_animal);
        string  getType(void) const;
        void    setType(string new_type);
        virtual void makeSound() const = 0;
        virtual ~AAnimal();
};

