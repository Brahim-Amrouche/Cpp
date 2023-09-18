/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 14:34:53 by bamrouch          #+#    #+#             */
/*   Updated: 2023/09/18 15:35:16 by bamrouch         ###   ########.fr       */
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
        string      getType(void);
        virtual void        makeSound(void);
        ~WrongAnimal();
};
