/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 07:09:08 by bamrouch          #+#    #+#             */
/*   Updated: 2023/12/13 10:38:47 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"


int main()
{
    vector<int> v_nums(1, 1);
    list<int> l_nums(1, 1);

    // int i = 0;
    // while (++i < 6)
    // {
    //     v_nums.push_back(i);
    //     l_nums.push_back(6 - i);
    // }
    
    vector<int>::const_iterator v_it = easyfind(v_nums, 1);
    list<int>::const_iterator l_it = easyfind(l_nums, 1);
    vector<int>::const_iterator not_v_it = easyfind(v_nums, -1);
    list<int>::const_iterator not_l_it = easyfind(l_nums, -1);

    // vector<int>::iterator v_it = easyfind(v_nums, 1);
    // list<int>::iterator l_it = easyfind(l_nums, 1);
    // vector<int>::iterator not_v_it = easyfind(v_nums, -1);
    // list<int>::iterator not_l_it = easyfind(l_nums, -1);
    // *v_it = 5;
    // *l_it = 3;
    if (v_it != v_nums.end())
        cout << "the number 1 is found in vector: "<< *v_it << endl;
    if (l_it != l_nums.end())
        cout << "the number 1 is found in list: "<< *l_it << endl;
    if (not_v_it != v_nums.end())
        cout << "the number -1 is not found in vector: "<< *not_v_it << endl;
    if (not_l_it != l_nums.end())
        cout << "the number -1 is not found in list: "<< *not_l_it << endl;
}