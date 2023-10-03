/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Types.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:53:27 by bamrouch          #+#    #+#             */
/*   Updated: 2023/10/03 23:08:14 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Types.hpp"


Base *Base::generate(void)
{
    time_t current_time = time(NULL);
    srand((unsigned int) current_time);

    int randomnum = (rand() % 3);
    
    switch (randomnum)
    {
        case A_CLASS:
            return new A();
        case B_CLASS:
            return new B();
        case C_CLASS:
            return new C();
        default:
            break;
    }
    return NULL;
}

void    Base::identify(Base *p)
{
    A *a_cast = dynamic_cast<A *>(p);
    if (a_cast)
    {
        cout << "A" << endl;
        return;
    }
    
    B *b_cast = dynamic_cast<B *>(p);
    if (b_cast)
    {
        cout << "B" << endl;
        return;
    }

    C *c_cast = dynamic_cast<C *>(p);
    if (c_cast)
        cout << "C" << endl;  
}

void    Base::identify(Base &p)
{
    try {
        A &a_ref = dynamic_cast<A &>(p);
        (void) a_ref;
        cout << "A" << endl;
        return;
    }
    catch(bad_cast &e)
    {
        (void) e;
    }

    try{
        B &b_ref = dynamic_cast<B &>(p);
        (void) b_ref;
        cout << "B" << endl;
        return ;
    }
    catch(bad_cast &e)
    {
        (void) e;
    }

    try{
        C &c_ref = dynamic_cast<C &>(p);
        (void) c_ref;
        cout << "C" << endl;
        return ;
    }
    catch(bad_cast &e)
    {
        (void) e;
    }
}

Base::~Base()
{}

A::~A()
{}

B::~B()
{}

C::~C()
{}

