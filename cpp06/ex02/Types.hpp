/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Types.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:37:55 by bamrouch          #+#    #+#             */
/*   Updated: 2023/10/02 14:57:01 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class Base
{
    public:
        Base    *generate(void);
        void     identify(Base *p);
        void     identify(Base &p);
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
