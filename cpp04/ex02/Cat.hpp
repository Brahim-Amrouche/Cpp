/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 20:16:13 by bamrouch          #+#    #+#             */
/*   Updated: 2023/11/08 20:16:16 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
    private:
        Brain   *brain;
    public:
        Cat();
        Cat(const Cat &cpy_cat);
        Cat &operator=(const Cat &eq_cat);
        void    makeSound(void) const;
        ~Cat();
};






