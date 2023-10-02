/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 12:05:53 by bamrouch          #+#    #+#             */
/*   Updated: 2023/10/02 13:31:02 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data(): next(NULL), content(NULL)
{}

Data::Data(Data *new_data, void *new_content): next(new_data), content(new_content) 
{}

Data::Data(const Data &cpy_data): next(cpy_data.next), content(cpy_data.content)
{}

Data &Data::operator=(const Data &eq_data)
{
    next = eq_data.next;
    content = eq_data.content;
    return (*this);
}

void    *Data::getNext()
{
    return (next);
}

void    *Data::getContent()
{
    return (content);
}


void    Data::setNext(Data *new_next)
{
    next = new_next;
}

void    Data::setContent(void *new_content)
{
    content = new_content;
}

Data::~Data()
{}
