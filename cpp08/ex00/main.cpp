/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 07:09:08 by bamrouch          #+#    #+#             */
/*   Updated: 2023/10/13 07:23:37 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"


int main()
{
    vector<int> v_nums;
    list<int> l_nums;

    int i = 0;
    while (++i < 6)
    {
        v_nums.push_back(i);
        l_nums.push_back(6 - i);
    }

    int v_index = easyfind(v_nums, 2);
    int l_index = easyfind(l_nums, 2);
    int v_not_found = easyfind(v_nums, -1);
    int l_not_found = easyfind(l_nums, -1);

    cout << "this is the index of 2 in v_nums :"<< v_index << endl;
    cout << "this is the index of 2 in l_nums :"<< l_index << endl;
    cout << "this is the index of -1 in v_nums :"<< v_not_found << endl;
    cout << "this is the index of -1 in l_nums :"<< l_not_found << endl;
}