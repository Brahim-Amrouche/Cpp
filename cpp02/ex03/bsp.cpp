/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 16:51:29 by bamrouch          #+#    #+#             */
/*   Updated: 2023/09/23 11:52:37 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp(Point &a, Point &b, Point &c, Point &point)
{
    Fixed A[2], AB[2], AP[2];
    Fixed B[2], BC[2], BP[2];
    Fixed C[2], CA[2], CP[2];
    Fixed P[2];
    Fixed alpha, beta, gamma, zero;

    a.get_cords(A);
    b.get_cords(B);
    c.get_cords(C);
    point.get_cords(P);
    
    cout << "multiplication: " << A[0] * B[0] << endl;
    AB[0] = B[0] - A[0];
    AB[1] = B[1] - A[1];

    BC[0] = C[0] - B[0];
    BC[1] = C[1] - B[1];

    CA[0] = A[0] - C[0];
    CA[1] = A[1] - C[1];

    AP[0] = P[0] - A[0];
    AP[1] = P[1] - A[1];

    BP[0] = P[0] - B[0];
    BP[1] = P[1] - B[1];

    CP[0] = P[0] - C[0];
    CP[1] = P[1] - C[1];

    alpha = AB[0] * AP[0] + AB[1] * AP[1];
    beta = BC [0] * BP[0] + BC[1] * BP[1];
    gamma = CA[0] * CP[0] + CA[1] * CP[1];
    
    zero = Fixed(0.0f);
    if ((alpha >= zero && beta >= zero && gamma >= zero) ||
        (alpha <= zero && beta <= zero && gamma <= zero))
        return (1);
    return (0);
}



