/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 12:32:22 by bamrouch          #+#    #+#             */
/*   Updated: 2023/09/26 15:13:21 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{  
    Bureaucrat x("max", 10);
    Bureaucrat y("min", 140);
    
    try {
        Bureaucrat min("max", 1);
        Bureaucrat max("min", 151);
    }
    catch (const Bureaucrat::GradeTooLowException &h)
    {
        cerr << h.what() << endl;
    }
    catch (const Bureaucrat::GradeTooHighException &l)
    {
        cerr << l.what() << endl;
    }

    size_t i = -1;
    while (++i < 9)
        x.increment_grade();
    
    try {
        x.increment_grade();
    }
    catch(const Bureaucrat::GradeTooHighException &e)
    {
        cerr << e.what() << endl;
    }
    
    i = -1;
    while (++i < 10)
        y.decrement_grade();
    
    try {
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