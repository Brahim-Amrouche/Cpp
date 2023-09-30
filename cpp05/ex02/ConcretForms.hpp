/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConcretForms.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 19:04:35 by bamrouch          #+#    #+#             */
/*   Updated: 2023/09/29 18:48:53 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "fstream"
// #include "thread"
// #include "chrono"

using std::ofstream;
using std::ios;

class ShrubberyCreationForm : public AForm
{
    public :
        class FileErr: public exception
        {
            const char *what() const throw();
        };
        ShrubberyCreationForm();
        ShrubberyCreationForm(string new_name);
        ShrubberyCreationForm(const ShrubberyCreationForm &cpy_shrubbery);
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &eq_shrubbery);
        ~ShrubberyCreationForm();
        void execute(const Bureaucrat &bureau);
};



class  RobotomyRequestForm : public AForm
{
    private:
        bool flip;
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(string new_name);
        RobotomyRequestForm(const RobotomyRequestForm &cpy_robotomy);
        RobotomyRequestForm &operator=(const RobotomyRequestForm &eq_robotomy);
        ~RobotomyRequestForm();
        void    execute(const Bureaucrat &bureau);
};

class PresidentialPardonForm : public AForm
{
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(string new_name);
        PresidentialPardonForm(const PresidentialPardonForm &cpy_presid);
        PresidentialPardonForm  &operator=(const PresidentialPardonForm &eq_presid);
        ~PresidentialPardonForm();
        void execute(const Bureaucrat &bureau);
};