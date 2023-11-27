/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 15:13:26 by bamrouch          #+#    #+#             */
/*   Updated: 2023/11/27 09:29:45 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm():AForm("PresidentialPardonForm", 25, 5)
{}

PresidentialPardonForm::PresidentialPardonForm(const string &target_name):AForm("PresidentialPardonForm", 25, 5), target(target_name)
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &cpy_presid):
    AForm(cpy_presid.getName(), cpy_presid.getSignGrade(), cpy_presid.getExecGrade())
{}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &eq_presid)
{
    AForm::operator=(eq_presid);
    return (*this);
}

void PresidentialPardonForm::execute(const Bureaucrat &bureau)
{
    AForm::check_signed(bureau);
    cout << target << " has been pardoned by Zaphod Beeblebrox." << endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{}

