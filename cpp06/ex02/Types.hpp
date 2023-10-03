/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Types.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:37:55 by bamrouch          #+#    #+#             */
/*   Updated: 2023/10/03 23:04:28 by bamrouch         ###   ########.fr       */
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


class A : public Base
{
    public:
        ~A();
};

class B: public Base
{
    public:
        ~B();
};

class C: public Base
{
    public:
        ~C();
};
