/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:37:55 by bamrouch          #+#    #+#             */
/*   Updated: 2023/12/11 09:16:15 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "iostream"
#include "cstdlib"
#include "ctime"
#include "typeinfo"

using std::srand;
using std::rand;
using std::time;
using std::cout;
using std::endl;
using std::bad_cast;

enum RANDOM_GENERATION
{
    A_CLASS,
    B_CLASS,
    C_CLASS
};

class Base
{
    public:
        static Base    *generate(void);
        static void     identify(Base *p);
        static void     identify(Base &p);
        virtual ~Base();
};
