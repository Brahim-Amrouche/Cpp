/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 08:52:45 by bamrouch          #+#    #+#             */
/*   Updated: 2023/11/27 10:45:21 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Form.hpp"
#include "Bureaucrat.hpp"
#define PRESID "presidential pardon"

class PresidentialPardonForm : public Form
{
    private:
        const string target;
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(const string &target_name);
        PresidentialPardonForm(const PresidentialPardonForm &cpy_presid);
        PresidentialPardonForm  &operator=(const PresidentialPardonForm &eq_presid);
        ~PresidentialPardonForm();
        void execute(const Bureaucrat &bureau);
};