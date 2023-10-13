/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 06:03:03 by bamrouch          #+#    #+#             */
/*   Updated: 2023/10/13 07:18:35 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "vector"
#include "list"
#include "iostream"


using std::vector;
using std::list;
using std::cout;
using std::endl;

template <typename Container>
int  easyfind(Container &container, int to_find)
{
    typename Container::iterator start = container.begin();
    typename Container::iterator end = container.end();

    size_t index = 0;
    while (start != end)
    {
        if (*start == to_find)
            return index;
        start++;
        index++;
    }
    return -1;
}
