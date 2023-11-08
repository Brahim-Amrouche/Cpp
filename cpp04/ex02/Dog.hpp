/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 20:16:30 by bamrouch          #+#    #+#             */
/*   Updated: 2023/11/08 20:16:32 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma  once
#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog: public AAnimal
{
    private:
        Brain   *brain;
    public:
        Dog();
        Dog(const Dog &eq_dog);
        Dog &operator=(const Dog &eq_dog);
        void    makeSound(void) const;
        ~Dog();
};
