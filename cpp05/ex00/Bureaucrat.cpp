/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:59:17 by bamrouch          #+#    #+#             */
/*   Updated: 2023/11/27 07:53:08 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Bureaucrat grade too high it should be beyond 1";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Bureaucrat grade too low it should be under 150";
}

Bureaucrat::Bureaucrat():name(""),grade(150)
{}

Bureaucrat::Bureaucrat(string new_name, int new_grade): name(new_name)
{
    if (new_grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (new_grade > 150)
        throw Bureaucrat::GradeTooLowException();
    grade = new_grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &cpy_bureau): name(cpy_bureau.name), grade(cpy_bureau.grade)
{}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &eq_bureau)
{
    grade = eq_bureau.grade;   
    return (*this);
}

void    Bureaucrat::increment_grade()
{
    if (grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    --grade;
}

void    Bureaucrat::decrement_grade()
{
    if (grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    ++grade;
}

string Bureaucrat::getName() const
{
    return name;
}

int Bureaucrat::getGrade() const
{
    return grade;
}

Bureaucrat::~Bureaucrat()
{}

ostream &operator<<(ostream &os, const Bureaucrat &bureau)
{
    cout << bureau.getName() << ", bureaucrat grade " << bureau.getGrade();
    return (os);
}