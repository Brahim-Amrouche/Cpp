/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 20:12:56 by bamrouch          #+#    #+#             */
/*   Updated: 2023/11/08 20:12:59 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "iostream"
#include "string"

using std::string;
using std::cout;
using std::endl;

class WrongAnimal
{
    protected:
        string type;
    public:
        WrongAnimal();
        WrongAnimal(string new_type);
        WrongAnimal(const WrongAnimal &cpy_animal);
        WrongAnimal &operator=(const WrongAnimal &eq_animal);
        string      getType(void) const;
        void        makeSound(void) const;
        virtual ~WrongAnimal();
};
