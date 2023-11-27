/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 12:32:22 by bamrouch          #+#    #+#             */
/*   Updated: 2023/11/27 08:01:14 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{  
    Bureaucrat x("max", 1);
    Bureaucrat y("min", 150);
    
    try {
        Bureaucrat min("max", 1);
        Bureaucrat max("min", 151);
    }
    catch (const Bureaucrat::GradeTooHighException &h)
    {
        cerr << h.what() << endl;
    }
    catch (const Bureaucrat::GradeTooLowException &l)
    {
        cerr << l.what() << endl;
    }

    try
    {
        size_t i = -1;
        while (++i < 9)
            x.increment_grade();
    }
    catch(const Bureaucrat::GradeTooHighException &e)
    {
        cerr << e.what() << endl;
    }
    
    try
    {
        size_t i = -1;
        while (++i < 10)
            y.decrement_grade();
    }
    catch (const Bureaucrat::GradeTooLowException &e)
    {
        cerr << e.what() << endl;    
    }
    
    cout << x << endl;
    cout << y << endl;
    return (0);
}