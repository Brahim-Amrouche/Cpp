/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 16:17:50 by bamrouch          #+#    #+#             */
/*   Updated: 2023/11/27 08:44:47 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

const char *Form::GradeTooHighException::what() const throw()
{
    return "Form Grade is Higher than 1";
}

Form::GradeTooLowException::GradeTooLowException(const int &g)
{
    stringstream ss;
    s += "Form Grade is ";
    ss << g;
    s += ss.str();
}

const char *Form::GradeTooLowException::what() const throw()
{
    return s.c_str();
}

Form::GradeTooLowException::~GradeTooLowException() throw()
{}

Form::Form():name(""), is_signed(false), sign_grade(1), execute_grade(1)
{}

Form::Form(string new_name, int new_sign_grade, int new_exec_grade):name(new_name), is_signed(false), sign_grade(new_sign_grade), execute_grade(new_exec_grade)
{
    if (sign_grade < 1 || execute_grade < 1)
        throw GradeTooHighException();
    else if (sign_grade > 150 || execute_grade > 150)
        throw GradeTooLowException(150);
}

Form::Form(const Form &cpy_form):name(cpy_form.name), is_signed(false), sign_grade(cpy_form.sign_grade), execute_grade(cpy_form.execute_grade)
{}

Form    &Form::operator=(const Form&eq_form)
{
    is_signed = eq_form.is_signed;
    return (*this);
}

string Form::getName() const
{
    return name;
}

bool    Form::getSign() const
{
    return is_signed;
}

int     Form::getSignGrade() const
{
    return sign_grade;
}

int     Form::getExecGrade() const
{
    return execute_grade;
}

void    Form::setSign(bool new_sign)
{
    is_signed = new_sign;
}

void    Form::beSigned(const Bureaucrat &bureau)
{
    if (bureau.getGrade() > sign_grade)
        throw GradeTooLowException(sign_grade);
    setSign(true);
}

Form::~Form()
{}

ostream &operator<<(ostream &os, const Form &form)
{
    os << form.getName() << " is ";
    if (form.getSign())
        os << "signed ";
    else
        os << "not signed ";
    os << ",has a sign grade of " << form.getSignGrade() << " and an execute grade of " << form.getExecGrade();
    return os;
}