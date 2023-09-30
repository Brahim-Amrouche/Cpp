/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:59:17 by bamrouch          #+#    #+#             */
/*   Updated: 2023/09/29 16:52:35 by bamrouch         ###   ########.fr       */
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

void    Bureaucrat::signForm(AForm &form) const
{
    try{
        form.beSigned(*this);
        cout << this->getName() << " signed " << form.getName() << endl;
    }
    catch (const AForm::GradeTooLowException &e)
    {
        cout << *this << " couldn't sign " << form << " because " << e.what() << endl;
    }
}

void    Bureaucrat::executeForm(AForm &form) const
{
    try
    {
        form.execute(*this);
        cout << this->getName() << " executed "  << form.getName() << endl; 
    }
    catch (const exception &e)
    {
        cerr << e.what() << endl;
    }
}

Bureaucrat::~Bureaucrat()
{}

ostream &operator<<(ostream &os, const Bureaucrat &bureau)
{
    cout << bureau.getName() << ", bureaucrat grade " << bureau.getGrade();
    return (os);
}