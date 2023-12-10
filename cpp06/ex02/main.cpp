/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:45:22 by bamrouch          #+#    #+#             */
/*   Updated: 2023/12/10 16:07:02 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Types.hpp"

int main()
{
    Base *x = Base::generate();

    Base::identify(x);
    Base::identify(*x);
    delete x;
}
