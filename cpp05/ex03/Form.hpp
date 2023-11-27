/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:48:40 by bamrouch          #+#    #+#             */
/*   Updated: 2023/11/27 11:03:16 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "string"
#include "iostream"
#include "stdexcept"
#include <sstream>

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
        class NotSigneForm : public exception
        {
            public:
                const char *what() const throw();
        };
        Form();
        Form(string new_name, int new_sign_grade, int new_exec_grade);
        Form(const Form &cpy_Form);
        Form &operator=(const Form &eq_Form);
        string  getName() const;
        bool    getSign() const;
        int     getSignGrade() const;
        int     getExecGrade() const;
        void    setSign(bool new_sign);
        void    beSigned(const Bureaucrat &bureau);
        void    check_signed(const Bureaucrat &bureau);
        virtual void execute(const Bureaucrat &bureau) = 0;
        virtual ~Form();
};

ostream &operator<<(ostream &os, const Form &Form);

