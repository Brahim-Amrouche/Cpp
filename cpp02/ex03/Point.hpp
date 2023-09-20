/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 14:18:18 by bamrouch          #+#    #+#             */
/*   Updated: 2023/09/20 19:27:47 by bamrouch         ###   ########.fr       */
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
        void    get_cords(Fixed (&cords)[2]) const;
        void    set_cords(float new_x, float new_y);
        ~Point();
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif