/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 08:57:16 by bamrouch          #+#    #+#             */
/*   Updated: 2023/11/27 11:00:11 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>

#define ROBOT "robotomy request"

class  RobotomyRequestForm : public Form
{
    private:
        const string target;
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(const string &target_name);
        RobotomyRequestForm(const RobotomyRequestForm &cpy_robotomy);
        RobotomyRequestForm &operator=(const RobotomyRequestForm &eq_robotomy);
        ~RobotomyRequestForm();
        void    execute(const Bureaucrat &bureau);
};