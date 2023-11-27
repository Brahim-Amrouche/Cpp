/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 08:52:45 by bamrouch          #+#    #+#             */
/*   Updated: 2023/11/27 09:21:01 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm
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