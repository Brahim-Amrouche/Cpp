/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 12:32:22 by bamrouch          #+#    #+#             */
/*   Updated: 2023/11/27 08:45:10 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{  
    Form    f("list", 1, 150);
    Bureaucrat b("brahim", 2);

    try {
        b.signForm(f);
    }
    catch (const Form::GradeTooLowException &e)
    {
        return (1);
    }
    cout << f << endl;
    return (0);
}