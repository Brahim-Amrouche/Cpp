/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Interfaces.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 11:09:24 by bamrouch          #+#    #+#             */
/*   Updated: 2023/09/24 15:34:05 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once
#include "string"
#include "iostream"


using   std::string;
using   std::cout;
using   std::endl;

class AMateria;

class ICharacter
{
    public:
        virtual ~ICharacter() {}
        virtual string const & getName() const = 0;
        virtual void equip(AMateria* m) = 0;
        virtual void unequip(int idx) = 0;
        virtual void use(int idx, ICharacter& target) = 0;
};

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

class IMateriaSource
{
    public:
        virtual ~IMateriaSource() {}
        virtual void learnMateria(AMateria *m) = 0;
        virtual AMateria* createMateria(string const & type) = 0;
};
