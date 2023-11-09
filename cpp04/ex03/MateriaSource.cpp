/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:21:55 by bamrouch          #+#    #+#             */
/*   Updated: 2023/11/09 20:51:50 by bamrouch         ###   ########.fr       */
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
}

MateriaSource &MateriaSource::operator=(const MateriaSource &eq_source)
{
    if (this == &eq_source)
        return (*this);
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
    return *this;
}

void    MateriaSource::learnMateria(AMateria *m)
{
    if (!m)
        return;
    size_t i = -1;
    while (++i < 4)
    {
        if (!materias[i])
        {
            materias[i] = m;
            return ;
        }
    }
}

AMateria    *MateriaSource::createMateria(string const &type)
{
    int  i = -1;

    while (++i < 4)
    {
        if (materias[i] && materias[i]->getType() == type)
            return materias[i]->clone();
    }
    return NULL;
}

MateriaSource::~MateriaSource()
{
    size_t i = -1;

    while (++i < 4)
    {
        if (materias[i])
            delete materias[i];
    }
}
