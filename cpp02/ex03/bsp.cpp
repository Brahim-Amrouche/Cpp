/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 16:51:29 by bamrouch          #+#    #+#             */
/*   Updated: 2023/09/20 19:38:03 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    Fixed A[2];
    Fixed B[2];
    Fixed C[2];
    Fixed P[2];
    Fixed det, alpha, beta, gamma;


    a.get_cords(A);
    b.get_cords(B);
    c.get_cords(C);
    point.get_cords(P);

    det = (B[1] - C[1]) * (A[0] - C[0]) + (C[0] - B[0]) * (A[1] - C[1]);
    alpha = ((B[1] - C[1]) * (P[0] - C[0]) + (C[0] - B[0]) * (P[1] - C[1])) / det;
    beta = ((C[1] - A[1]) * (P[0] - C[0]) + (A[0] - C[0]) * (P[1] - C[1])) / det;
    gamma = Fixed(1)  - alpha - beta;

    if (alpha < Fixed(0.0f) || alpha > Fixed(1.0f))
        return (0);
    else if (beta < Fixed(0.0f) || beta > Fixed(1.0f))
        return (0);
    else if (gamma < Fixed (0.0f) || gamma > Fixed(1.0f))
        return (0);
    return (1);
}



