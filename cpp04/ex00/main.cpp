/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 20:12:32 by bamrouch          #+#    #+#             */
/*   Updated: 2023/11/08 20:12:35 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    cout << j->getType() << " " << endl;
    cout << i->getType() << " " << endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();

    const   WrongAnimal *non_meta =  new WrongAnimal();
    const   WrongAnimal *non_cat = new WrongCat();

    cout << non_meta->getType() << " " << endl;
    cout << non_cat->getType() << " " << endl;
    
    non_meta->makeSound();
    non_cat->makeSound();
    
    delete meta;
    delete i;
    delete j;
    delete non_meta;
    delete non_cat;
}
