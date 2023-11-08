/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 20:14:05 by bamrouch          #+#    #+#             */
/*   Updated: 2023/11/08 20:14:08 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
    private:
        Brain   *brain;
    public:
        Cat();
        Cat(const Cat &cpy_cat);
        Cat &operator=(const Cat &eq_cat);
        virtual void    makeSound(void) const;
        virtual ~Cat();
};






