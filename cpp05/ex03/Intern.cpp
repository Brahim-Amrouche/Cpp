/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 18:50:12 by bamrouch          #+#    #+#             */
/*   Updated: 2023/09/30 17:13:32 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"



AForm   *CustomFormConstructor(string type, string name)
{
    size_t i = -1;
    while (++i < 3)
        if (forms_names[i] == type)
            break;
    switch (i)
    {
        case 0 :
            return new ShrubberyCreationForm(name);
        case 1 :
            return new RobotomyRequestForm(name);
        case 2 :
            return new PresidentialPardonForm(name);
        default :
            cerr << "Not a Valid Form Type" << endl;
    }
    return NULL;
}

Form::Form():type(new AForm()), 
    AForm(*type) , target("", 1)
{}

Form::Form(string new_type, string target_name):type(CustomFormConstructor(new_type, new_type)), 
    AForm(type == NULL ? AForm(new_type, 1, 1) : *type) , target(target_name, 1)
{
    if (!type)
        type = new AForm(new_type , 1, 1);
};

Form::Form(const Form &cpy_form): type(cpy_form.type), AForm(*type), target(cpy_form.target)
{}

Form &Form::operator=(const Form &eq_form)
{
    AForm::operator=(eq_form);
    target = eq_form.target;
    type = eq_form.type;
    return (*this);
}

Form::~Form()
{
    delete type;
}

void Form::execute(const Bureaucrat &bureau)
{
    type->execute(target);
}

//  Intern Implementation

Intern::Intern()
{};

Intern::Intern(const Intern &cpy_intern)
{};

Intern &Intern::operator=(const Intern &eq_intern)
{
    return (*this);
};

Intern::~Intern()
{};

Form   *Intern::makeForm(string form_name, string target_name)
{
    cout << "Intern creates " << form_name << endl;
    Form        *new_form = new Form(form_name, target_name);
    return new_form;
};
