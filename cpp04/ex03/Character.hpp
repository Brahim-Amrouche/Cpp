/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:05:49 by bamrouch          #+#    #+#             */
/*   Updated: 2023/09/19 14:29:56 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Interfaces.hpp"

class Character: public ICharacter
{
    private :
        string name;
        AMateria    *inventory[4];
        int         throw_index = 0;
        AMateria    **floor_materias = NULL;
    public :
        Character(string const &new_name);
        Character(const Character &cpy_character);
        Character &operator=(const Character &eq_character);
        string const &getName() const;
        void        equip(AMateria *m);
        void        unequip(int idx);
        void        use(int idx, ICharacter &target);
        ~Character();
};
