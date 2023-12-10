/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:44:29 by bamrouch          #+#    #+#             */
/*   Updated: 2023/12/10 15:51:16 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Data.hpp"
#include "stdint.h"

class Serializer
{
    private:
        Serializer();
        Serializer(const Serializer &cpy);
        Serializer &operator=(const Serializer &eq);
        ~Serializer();
    public:
        static uintptr_t    serialize(Data *ptr);
        static Data         *deserialize(uintptr_t raw);
};