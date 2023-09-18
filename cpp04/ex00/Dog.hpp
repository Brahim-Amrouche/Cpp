/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:14:39 by bamrouch          #+#    #+#             */
/*   Updated: 2023/09/18 15:10:40 by bamrouch         ###   ########.fr       */
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
        void    makeSound(void);
        ~Dog();
};
