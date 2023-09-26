/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:48:40 by bamrouch          #+#    #+#             */
/*   Updated: 2023/09/26 19:00:04 by bamrouch         ###   ########.fr       */
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

class Bureaucrat;

class AForm
{
    private:
        const string name;
        bool  is_signed;
        const int sign_grade;
        const int execute_grade;
    public:
        class GradeTooHighException : public exception
        {
            public:
                const char *what() const throw();
        };
        class GradeTooLowException : public exception
        {
            public:
                const char *what() const throw();
        };
        AForm();
        AForm(string new_name, int new_sign_grade, int new_exec_grade);
        AForm(const AForm &cpy_AForm);
        AForm &operator=(const AForm &eq_AForm);
        string  getName() const;
        bool    getSign() const;
        int     getSignGrade() const;
        int     getExecGrade() const;
        void    setSign(bool new_sign);
        void    beSigned(const Bureaucrat &bureau);
        virtual void execute(const Bureaucrat &bureau) = 0;
        ~AForm();
};

ostream &operator<<(ostream &os, const AForm &AForm);