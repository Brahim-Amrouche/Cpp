/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 14:10:00 by bamrouch          #+#    #+#             */
/*   Updated: 2023/11/01 15:24:36 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point():x(0.0f), y(0.0f)
{};

Point::Point(float const new_x, float const new_y):x(new_x), y(new_y)
{
};

Point::Point(const Point &cpy_point):x(cpy_point.x), y(cpy_point.x)
{};

Point &Point::operator=(const Point &eq_point)
{
    Point *new_point = new Point(eq_point);
    delete this;
    return (*new_point);
};

Fixed const Point::get_x() const
{
    return x;
}

Fixed const Point::get_y() const
{
    return y;
}

void   Point::get_cords(Fixed (&cords)[2]) const
{
    cords[0] = x;
    cords[1] = y;
}

Point::~Point()
{};

