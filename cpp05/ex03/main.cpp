/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 16:07:54 by bamrouch          #+#    #+#             */
/*   Updated: 2023/09/29 18:02:40 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ConcretForms.hpp"

int main()
{
    Bureaucrat x("Shrub", 137);
    Bureaucrat y("Robot", 44);
    Bureaucrat z("Presid", 4);
    
    ShrubberyCreationForm shru("form1");
    x.signForm(shru);
    x.executeForm(shru);

    RobotomyRequestForm robo("form2");
    y.signForm(robo);
    y.executeForm(robo);
    y.executeForm(robo);
    x.executeForm(robo);
    
    PresidentialPardonForm  presid("form3");
    z.signForm(presid);
    z.executeForm(presid);   
}