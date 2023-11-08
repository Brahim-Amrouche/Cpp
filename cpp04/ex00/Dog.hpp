/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 20:12:25 by bamrouch          #+#    #+#             */
/*   Updated: 2023/11/08 20:12:27 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma  once
#include "Animal.hpp"

class Dog: public Animal
{
    public:
        Dog();
        Dog(const Dog &eq_dog);
        Dog &operator=(const Dog &eq_dog);
        virtual void    makeSound(void) const;
        virtual ~Dog();
};
