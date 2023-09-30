/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 15:13:26 by bamrouch          #+#    #+#             */
/*   Updated: 2023/09/29 16:54:18 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ConcretForms.hpp"


PresidentialPardonForm::PresidentialPardonForm():AForm("", 25, 5)
{}

PresidentialPardonForm::PresidentialPardonForm(string new_name):AForm(new_name, 25, 5)
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
    AForm::execute(bureau);
    cout << bureau.getName() << " has been pardoned by Zaphod Beeblebrox." << endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{}

