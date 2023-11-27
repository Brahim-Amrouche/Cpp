/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 08:57:16 by bamrouch          #+#    #+#             */
/*   Updated: 2023/11/27 08:59:42 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"
#include "Bureaucrat.hpp"

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