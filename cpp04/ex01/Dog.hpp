/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:14:39 by bamrouch          #+#    #+#             */
/*   Updated: 2023/09/24 12:32:52 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma  once
#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal
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
