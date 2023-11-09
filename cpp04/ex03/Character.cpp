/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 12:23:49 by bamrouch          #+#    #+#             */
/*   Updated: 2023/11/09 21:37:42 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character():name(""), floor_materias(NULL)
{
    size_t i = -1;

    while (++i < 4)
        inventory[i] = NULL;
}

Character::Character(string const &new_name):name(new_name), floor_materias(NULL)
{
    size_t i = -1;

    while (++i < 4)
        inventory[i] = NULL;
};

Character::Character(const Character &cpy_character):name(cpy_character.name)
{
    size_t i = -1;
    AMateria    *deep_cpy_materias = NULL;

    while (++i < 4)
    {
        deep_cpy_materias = NULL;
        if (cpy_character.inventory[i])
            deep_cpy_materias = cpy_character.inventory[i]->clone();
        inventory[i] = deep_cpy_materias;
    }
}

Character   &Character::operator=(const Character &eq_character)
{
    if (this == &eq_character)
        return (*this);
    size_t i = -1;
    AMateria    *deep_cpy_materias = NULL;

    name = eq_character.name;
    while (++i < 4)
    {
        deep_cpy_materias = NULL;
        if (eq_character.inventory[i])
            deep_cpy_materias = eq_character.inventory[i]->clone();
        if (inventory[i])
            delete inventory[i];
        inventory[i] = deep_cpy_materias;
    }
    return (*this);
}

string const  &Character::getName() const
{
    return name;
};

void    add_floor_materia(AMateria *materia, AMateria ***floor_materia)
{
    size_t  floor_matrias_len = 0;
    AMateria    **new_floor_materias;

    while (*floor_materia && (*floor_materia)[floor_matrias_len])
        ++floor_matrias_len;
    new_floor_materias = new AMateria*[floor_matrias_len + 2];
    floor_matrias_len = 0;
    while (*floor_materia && (*floor_materia)[floor_matrias_len])
    {
        new_floor_materias[floor_matrias_len] = (*floor_materia)[floor_matrias_len];
        ++floor_matrias_len;
    }
    new_floor_materias[floor_matrias_len++] = materia;
    new_floor_materias[floor_matrias_len] = NULL;
    if (*floor_materia)
        delete[] *floor_materia;
    *floor_materia = new_floor_materias;
}

void    Character::equip(AMateria *m)
{
    if (!m)
        return;
    size_t i = -1;
    while (++i < 4)
    {
        if (!inventory[i])
        {
            inventory[i] = m;
            return;
        }
    }
}

void    Character::unequip(int idx)
{
    if ( idx < 0 || idx > 3 || !inventory[idx])
        return;
    add_floor_materia(inventory[idx], &floor_materias);
    inventory[idx] = NULL;
}

void    Character::use(int idx, ICharacter &target)
{
    if (idx < 0 || idx > 3 || !inventory[idx])
        return;
    inventory[idx]->use(target);
}

Character::~Character()
{
    size_t  i = -1;
    
    while (++i < 4)
    {
        if (inventory[i])
            delete inventory[i];
    }
    i = -1;
    while (floor_materias && floor_materias[++i])
        delete floor_materias[i];
    if (floor_materias)
        delete[] floor_materias;
};
