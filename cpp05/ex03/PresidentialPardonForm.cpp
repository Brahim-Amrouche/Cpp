/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 15:13:26 by bamrouch          #+#    #+#             */
/*   Updated: 2023/11/27 10:45:08 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm():Form(PRESID, 25, 5)
{}

PresidentialPardonForm::PresidentialPardonForm(const string &target_name):Form(PRESID, 25, 5), target(target_name)
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &cpy_presid):
    Form(cpy_presid.getName(), cpy_presid.getSignGrade(), cpy_presid.getExecGrade())
{}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &eq_presid)
{
    Form::operator=(eq_presid);
    return (*this);
}

void PresidentialPardonForm::execute(const Bureaucrat &bureau)
{
    Form::check_signed(bureau);
    cout << target << " has been pardoned by Zaphod Beeblebrox." << endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{}

