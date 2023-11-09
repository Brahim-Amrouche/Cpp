/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 11:35:31 by bamrouch          #+#    #+#             */
/*   Updated: 2023/11/09 19:45:15 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Interfaces.hpp"

AMateria::AMateria():materia_type("")
{}

AMateria::AMateria(const string &type): materia_type(type)
{};

AMateria::AMateria(const AMateria &cpy_materia): materia_type(cpy_materia.materia_type)
{};

AMateria    &AMateria::operator=(const AMateria &eq_materia)
{
    (void) eq_materia;
    return (*this);
}

string const &AMateria::getType() const
{
    return (materia_type);
};

void    AMateria::use(ICharacter &target)
{
    cout << "Try's to attack " << target.getName() << " but has nothing at hand " << endl;
}

AMateria::~AMateria()
{};