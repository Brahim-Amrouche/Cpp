/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 08:58:34 by bamrouch          #+#    #+#             */
/*   Updated: 2023/11/27 11:00:59 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm():AForm("RobotomyRequestForm",72, 45)
{}

RobotomyRequestForm::RobotomyRequestForm(const string &target_name):AForm("RobotomyRequestForm", 72, 45),target(target_name)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &cpy_robotomy):AForm(cpy_robotomy.getName(), 72, 45)
{}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &eq_robotomy)
{
    AForm::operator=(eq_robotomy);
    return (*this);
}

void RobotomyRequestForm::execute(const Bureaucrat &bureau)
{
    AForm::check_signed(bureau);
    cout << "Drilling..." << endl;
    cout << "Robotomy on " << target;
    std::srand(std::time(NULL));
    if (std::rand() % 2)
        cout << " succeeded" << endl;
    else
        cout << " failed" << endl;
}   

RobotomyRequestForm::~RobotomyRequestForm()
{}
