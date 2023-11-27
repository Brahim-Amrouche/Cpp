/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:48:40 by bamrouch          #+#    #+#             */
/*   Updated: 2023/11/27 08:37:35 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include "iostream"
#include <sstream>
#include "stdexcept"

using std::string;
using std::cout;
using std::cerr;
using std::endl;
using std::ostream;
using std::stringstream;
using std::exception;

class Bureaucrat;

class Form
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
            private :
                string s;
            public:
                GradeTooLowException(const int &g);
                virtual const char *what() const throw();
                ~GradeTooLowException() throw();
        };
        Form();
        Form(string new_name, int new_sign_grade, int new_exec_grade);
        Form(const Form &cpy_form);
        Form &operator=(const Form &eq_form);
        string  getName() const;
        bool    getSign() const;
        int     getSignGrade() const;
        int     getExecGrade() const;
        void    setSign(bool new_sign);
        void    beSigned(const Bureaucrat &bureau);
        ~Form();
};

ostream &operator<<(ostream &os, const Form &form);