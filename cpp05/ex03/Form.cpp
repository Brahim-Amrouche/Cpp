/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 16:17:50 by bamrouch          #+#    #+#             */
/*   Updated: 2023/09/26 18:42:09 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

const char *AForm::GradeTooHighException::what() const throw()
{
    return "AForm Grade is Higher than 1";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "AForm Grade is Lower than 150";
}

const char *AForm::NotSigneForm::what() const throw()
{
    return "AForm Not Signed";
}

AForm::AForm():name(""), is_signed(false), sign_grade(1), execute_grade(1)
{}

AForm::AForm(string new_name, int new_sign_grade, int new_exec_grade):name(new_name), is_signed(false), sign_grade(new_sign_grade), execute_grade(new_exec_grade)
{
    if (sign_grade < 1 || execute_grade < 1)
        throw GradeTooHighException();
    else if (sign_grade > 150 || execute_grade > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm &cpy_AForm):name(cpy_AForm.name), is_signed(false), sign_grade(cpy_AForm.sign_grade), execute_grade(cpy_AForm.execute_grade)
{}

AForm    &AForm::operator=(const AForm&eq_AForm)
{
    is_signed = eq_AForm.is_signed;
    return (*this);
}

string AForm::getName() const
{
    return name;
}

bool    AForm::getSign() const
{
    return is_signed;
}

int     AForm::getSignGrade() const
{
    return sign_grade;
}

int     AForm::getExecGrade() const
{
    return execute_grade;
}

void    AForm::setSign(bool new_sign)
{
    is_signed = new_sign;
}

void    AForm::beSigned(const Bureaucrat &bureau)
{
    if (bureau.getGrade() > sign_grade)
        throw GradeTooLowException();
    setSign(true);
}

void AForm::execute(const Bureaucrat &bureau)
{
    if (!is_signed)
        throw NotSigneForm();
    if (bureau.getGrade() > execute_grade)
        throw GradeTooLowException();
}

AForm::~AForm()
{}

ostream &operator<<(ostream &os, const AForm &AForm)
{
    os << AForm.getName() << " is ";
    if (AForm.getSign())
        os << "signed ";
    else
        os << "not signed ";
    os << "has a sign grade of " << AForm.getSignGrade() << " and an execute grade of " << AForm.getExecGrade();
    return os;
}