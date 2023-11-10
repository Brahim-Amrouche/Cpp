/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:03:37 by bamrouch          #+#    #+#             */
/*   Updated: 2023/11/10 12:18:04 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "string"
#include "iostream"

using   std::string;
using   std::cout;
using   std::endl;

class ICharacter;

class AMateria
{
    protected:
        string  materia_type;
    public:
        AMateria();
        AMateria(string const &type);
        AMateria(const AMateria &cpy_materia);
        AMateria &operator=(const AMateria &eq_materia);
        string  const &getType() const;
        virtual AMateria* clone() const = 0;
        virtual void    use(ICharacter &target);
        virtual ~AMateria();
};

#include "ICharacter.hpp"
