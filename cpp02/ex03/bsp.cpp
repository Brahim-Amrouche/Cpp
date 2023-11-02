/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 16:51:29 by bamrouch          #+#    #+#             */
/*   Updated: 2023/11/02 15:21:13 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed vectorial_product(Point &v1, Point &v2)
{
    Fixed res = (v1.get_x() * v2.get_y()) - (v2.get_x() * v1.get_y());
    return (res);
}

Point calculate_vector(Point &a , Point &b)
{
    Fixed x = b.get_x() - a.get_x();
    Fixed y = b.get_y() - a.get_y();
    Point vector(x.toFloat(), y.toFloat());
    return vector;
}

bool scalar_sign_differs(Fixed &origin, Fixed &copy)
{
    Fixed zero = Fixed(0.0f);

    bool origin_positive = origin > zero;
    bool copy_positive = copy > zero;
    bool origin_negative = origin < zero;
    bool copy_negative = origin < zero;
    
    return ((origin_positive && copy_negative) || (origin_negative && copy_positive));
}

bool bsp(Point &a, Point &b, Point &c, Point &point)
{
    Point AB(calculate_vector(a, b)), AC(calculate_vector(a, c)), AP(calculate_vector(a, point));
    Fixed ABAC(vectorial_product(AB,AC)), ABAP(vectorial_product(AB,AC));
    if (scalar_sign_differs(ABAC, ABAP))
        return false;
    Point BC(calculate_vector(b, c)), BA(calculate_vector(b, a)) ,BP(calculate_vector(b, point));
    Fixed BCBA(vectorial_product(BC, BA)), BCBP(vectorial_product(BC,BP));
    if (scalar_sign_differs(BCBA, BCBP))
        return false;
    Point CA(calculate_vector(c, a)),CB(calculate_vector(c, b)) , CP(calculate_vector(c, point));
    Fixed CACB(vectorial_product(CA,CB)) , CACP(vectorial_product(CA, CP));
    if (scalar_sign_differs(CACB, CACP))
        return false;
    return true;
}



