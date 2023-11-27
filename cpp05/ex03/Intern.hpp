/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 18:28:37 by bamrouch          #+#    #+#             */
/*   Updated: 2023/11/27 10:53:24 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

class Intern
{
    public :
        Intern();
        Intern(const Intern &cpy_intern);
        Intern &operator=(const Intern &eq_intern);
        ~Intern();
        Form *makeForm(string form_name, string target_name);
};

