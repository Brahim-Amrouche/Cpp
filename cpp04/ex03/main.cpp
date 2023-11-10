/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 15:08:14 by bamrouch          #+#    #+#             */
/*   Updated: 2023/11/10 12:28:14 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

// int main()
// {
//     IMateriaSource* src = new MateriaSource();
//     AMateria *added_ice = new Ice();
//     AMateria *added_cure = new Cure();
//     src->learnMateria(added_ice);
//     src->learnMateria(added_ice);
//     src->learnMateria(added_ice);
//     src->learnMateria(added_ice);
//     src->learnMateria(added_cure);
//     ICharacter* me = new Character("me");
//     *me = *me;
//     AMateria* tmp;
//     tmp = src->createMateria("ice");
//     me->equip(tmp);
//     delete tmp;
//     ICharacter* bob = new Character("bob");
//     src->learnMateria(added_ice);
//     src->learnMateria(added_cure);
//     src->learnMateria(added_ice);
//     me->equip(src->createMateria("cure"));
//     me->equip(src->createMateria("cure"));
//     me->equip(src->createMateria("cure"));
//     me->equip(src->createMateria("ice"));
//     me->use(0, *bob);
//     me->equip(src->createMateria("afsdfsdfsd"));
//     me->use(1, *bob);
// }

int main()
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Cure());
    src->learnMateria(new Ice());
    ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    me->equip(tmp);
    me->equip(tmp);
    me->equip(src->createMateria("ice"));
    me->equip(src->createMateria("cure"));
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    // me->unequip(0);
    // me->unequip(1);
    me->equip(src->createMateria("cure"));
    me->equip(src->createMateria("cure"));
    me->use(0, *bob);
    me->use(1, *bob);
    me->use(2, *bob);
    me->use(3, *bob);
    delete bob;
    delete me;
    delete src;
    return 0;
}