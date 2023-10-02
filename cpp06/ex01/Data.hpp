/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 12:06:08 by bamrouch          #+#    #+#             */
/*   Updated: 2023/10/02 13:40:53 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "iostream"

using std::cout;
using std::endl;


class Data
{
    private:
        Data    *next;
        void    *content;
    public:
        Data();
        Data(Data *new_next, void *new_content);
        Data(const Data &cpy_data);
        Data    &operator=(const Data &eq_data);
        void    *getNext();
        void    *getContent();
        void    setNext(Data *new_next);
        void    setContent(void *new_content);
        ~Data();      
};