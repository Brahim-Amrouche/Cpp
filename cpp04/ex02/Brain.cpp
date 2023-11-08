/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 20:15:46 by bamrouch          #+#    #+#             */
/*   Updated: 2023/11/08 20:15:49 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
    cout << "Brain Default constructor" << endl;
    size_t i = 0;
    while (i < 100)
        ideas[i++] = "";
}

Brain::Brain(const Brain &cpy_brain)
{
    cout << "Brain Copy Constructor" << endl;
    size_t i = -1;
    while (++i < 100)
        ideas[i] = cpy_brain.ideas[i];
}

Brain &Brain::operator=(const Brain &eq_brain)
{
    cout << "Brain assignement operator"  << endl;
    if (this != &eq_brain)
    {
        size_t i = -1;
        while (++i < 100)
            ideas[i] = eq_brain.ideas[i];
    }
    return (*this);
}

string      Brain::get_idea(size_t i)
{
    if (i == 0 || i > 100)
        return "";
    return ideas[i];
}

void        Brain::set_idea(string idea, size_t i)
{
    if (i == 0 || i > 100)
        return ;
    ideas[i] = idea;
}

Brain::~Brain()
{
    cout << "Brain Deconstructor" << endl;
}
