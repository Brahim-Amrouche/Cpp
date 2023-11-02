/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 14:18:18 by bamrouch          #+#    #+#             */
/*   Updated: 2023/11/02 14:31:59 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef POINT_H
#define POINT_H

#include "Fixed.hpp"

class Point
{
    private:
        Fixed const x;
        Fixed const y;
    public:
        Point();
        Point(float const new_x, float const new_y);
        Point(const Point &cpy_point);
        Point &operator=(const Point &eq_point);
        Fixed const get_x() const;
        Fixed const get_y() const;
        ~Point();
};

bool bsp(Point &a, Point &b, Point &c, Point &point);

#endif