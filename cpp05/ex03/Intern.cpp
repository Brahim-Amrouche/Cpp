/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 18:50:12 by bamrouch          #+#    #+#             */
/*   Updated: 2023/11/27 10:53:43 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
//  Intern Implementation
static string forms_names[3] = {SHRUB, ROBOT, PRESID};
static Form *(*constructor[3])(string x);

Form *new_shrub(const string target)
{
    return new ShrubberyCreationForm(target);
}

Form *new_robo(const string target)
{
    return new RobotomyRequestForm(target);
}

Form *new_presid(const string target)
{
    return new PresidentialPardonForm(target);
}

Intern::Intern()
{
    constructor[0] = new_shrub;
    constructor[1] = new_robo;
    constructor[2] = new_presid;
};

Intern::Intern(const Intern &cpy_intern)
{
    (void) cpy_intern;
};

Intern &Intern::operator=(const Intern &eq_intern)
{
    (void) eq_intern;
    return (*this);
};

Intern::~Intern()
{};

Form   *Intern::makeForm(string form_name, string target_name)
{
    cout << "Intern creates " << form_name << endl;
    Form *new_form = NULL;
    size_t i = -1;
    while (++i < 3)
    {
        if (forms_names[i] == form_name)
        {
            new_form = constructor[i](target_name);
            break;
        }
    }
    if (!new_form)
    {
        cerr << "Not a Valid Form Type" << endl;
        return NULL;
    }
    return new_form;
};
