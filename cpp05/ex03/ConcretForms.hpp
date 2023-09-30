/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConcretForms.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 19:04:35 by bamrouch          #+#    #+#             */
/*   Updated: 2023/09/30 17:12:54 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "fstream"

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



class Form : public AForm
{
    private :
        Bureaucrat  target;
        AForm   *type;
    public :
        class NotAValidFormType : public exception
        {
            public:
                const char *what() const throw();
        };
        Form();
        Form(string new_type, string target_name);
        Form(const Form &cpy_form);
        Form &operator=(const Form &eq_form);
        ~Form();
        void    execute(const Bureaucrat &bureau);
};

#define SHRUB "shrubbery creation"
#define ROBOT "robotomy request"
#define PRESID "presidential pardon"

static string forms_names[3] = {SHRUB, ROBOT, PRESID};

AForm   *CustomFormConstructor(string type, string name);

