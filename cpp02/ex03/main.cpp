/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 19:27:25 by bamrouch          #+#    #+#             */
/*   Updated: 2023/11/02 15:37:43 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main()
{
    Point a(0.0f, 0.0f);
    Point b(0.0f, 10.0f);
    Point c(10.0f, 0.0f);
    Point d(0.0f, 10.0f);

    cout << "the result is =========== " << bsp(a, b, c, d) << endl;
}