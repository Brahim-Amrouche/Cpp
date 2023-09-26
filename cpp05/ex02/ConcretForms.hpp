/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConcretForms.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 19:04:35 by bamrouch          #+#    #+#             */
/*   Updated: 2023/09/26 20:37:10 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

#include "fstream"

using std::ifstream;
using std::ofstream;

class ShrubberyCreationForm : public AForm
{
    public :
        ShrubberyCreationForm();
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
        RobotomyRequestForm(const RobotomyRequestForm &cpy_robotomy);
        RobotomyRequestForm &operator=(const RobotomyRequestForm &eq_robotomy);
        ~RobotomyRequestForm();
        void    execute(const Bureaucrat &bureau);
};

class PresidentialPardonForm : public AForm
{
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(const PresidentialPardonForm &cpy_presid);
        PresidentialPardonForm  &operator=(const PresidentialPardonForm &eq_presid);
        ~PresidentialPardonForm();
        void execute(const Bureaucrat &bureau);
};