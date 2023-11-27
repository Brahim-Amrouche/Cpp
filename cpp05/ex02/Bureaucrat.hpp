/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:59:39 by bamrouch          #+#    #+#             */
/*   Updated: 2023/11/27 08:51:07 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "string"
#include "iostream"
#include "stdexcept"

using std::string;
using std::cout;
using std::cerr;
using std::endl;
using std::ostream;
using std::exception;

#include "AForm.hpp"

class Bureaucrat
{
    private:
        const string name;
        int   grade;
    public:
        class GradeTooHighException :public exception
        {
            public:
                const char *what() const throw();
        };
        class GradeTooLowException : public virtual exception
        {
            public:
                const char *what() const throw();
        };
        Bureaucrat();
        Bureaucrat(string new_name, int new_grade);
        Bureaucrat(const Bureaucrat &cpy_bureau);
        Bureaucrat &operator=(const Bureaucrat &eq_bureau);
        void    increment_grade();
        void    decrement_grade();
        string  getName() const;
        int     getGrade() const;
        void    signForm(AForm &form) const;
        void    executeForm(AForm &form) const;
        ~Bureaucrat();
};

ostream &operator<<(ostream &os, const Bureaucrat &bureau);

