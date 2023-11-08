/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:39:15 by bamrouch          #+#    #+#             */
/*   Updated: 2023/09/24 12:20:12 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "WrongAnimal.hpp"


class WrongCat: public WrongAnimal
{
    public :
        WrongCat();
        WrongCat(const WrongCat &cpy_wrong);
        WrongCat &operator=(const WrongCat &eq_wrong);
        void    makeSound(void) const;
        ~WrongCat();
};
