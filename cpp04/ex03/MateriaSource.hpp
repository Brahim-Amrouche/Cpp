/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:16:47 by bamrouch          #+#    #+#             */
/*   Updated: 2023/11/09 20:51:19 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Interfaces.hpp"

class MateriaSource :public IMateriaSource
{
    private:
        AMateria    *materias[4];
    public:
        MateriaSource();
        MateriaSource(const MateriaSource &cpy_source);
        MateriaSource   &operator=(const MateriaSource &eq_source);
        void    learnMateria(AMateria *m);
        AMateria    *createMateria(string const &type);
        ~MateriaSource();
};

