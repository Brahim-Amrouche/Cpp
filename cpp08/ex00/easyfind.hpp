/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 06:03:03 by bamrouch          #+#    #+#             */
/*   Updated: 2023/12/13 10:37:54 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "vector"
#include "list"
#include "iostream"
#include "algorithm"


using std::vector;
using std::list;
using std::cout;
using std::endl;

template <class Container>
typename Container::iterator easyfind(Container &container,const int &to_find)
{
    typedef typename Container::iterator ContainerIt;
    ContainerIt start = container.begin();
    ContainerIt end = container.end();
    if(start == end)
        return end;
    return std::find(start, end, to_find);
}

template <class Container>
typename Container::const_iterator easyfind(const Container &container,const int &to_find)
{
    typedef typename Container::const_iterator ContainerIt;
    ContainerIt start = container.begin();
    ContainerIt end = container.end();
    if(start == end)
        return end;
    return std::find(start, end, to_find);
}
