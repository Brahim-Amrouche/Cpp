/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:21:55 by bamrouch          #+#    #+#             */
/*   Updated: 2023/09/19 16:07:45 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"


MateriaSource::MateriaSource()
{
    size_t  i = -1;
    while (++i < 4)
        materias[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &cpy_source)
{
    size_t i = -1;
    AMateria    *cpy_materia = NULL;

    while (++i < 4)
    {
        cpy_materia = NULL;
        if (cpy_source.materias[i])
            cpy_materia = cpy_source.materias[i]->clone();
        materias[i] = cpy_materia;
    }
    insert_index = cpy_source.insert_index;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &eq_source)
{
    size_t i = -1;
    AMateria    *cpy_materia = NULL;

    while (++i < 4)
    {
        cpy_materia = NULL;
        if (eq_source.materias[i])
            cpy_materia = eq_source.materias[i]->clone();
        if (materias[i])
            delete materias[i];
        materias[i] = cpy_materia;
    }
    insert_index = eq_source.insert_index;
    return *this;
}

void    MateriaSource::learnMateria(AMateria *m)
{
    if (insert_index > 3)
        return ;
    materias[insert_index] = m->clone();
    ++insert_index;
}

AMateria    *MateriaSource::createMateria(string const &type)
{
    size_t  i = -1;

    while (++i < insert_index)
        if (materias[i]->getType() == type)
            return materias[insert_index]->clone();
    return NULL;
}

MateriaSource::MateriaSource()
{
    size_t i = -1;

    while (++i < 4)
        if (materias[i])
            delete materias[i];
}
