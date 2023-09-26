/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 12:32:22 by bamrouch          #+#    #+#             */
/*   Updated: 2023/09/26 18:41:32 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{  
    Form    f("list", 2, 10);
    Bureaucrat b("brahim", 1);

    try {
        b.signForm(f);
    }
    catch (const Form::GradeTooLowException &e)
    {
        return (1);
    }
    return (0);
}