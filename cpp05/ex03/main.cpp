/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 16:07:54 by bamrouch          #+#    #+#             */
/*   Updated: 2023/11/27 11:08:11 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Form.hpp"

int main()
{
    Intern someRandomIntern;
    Bureaucrat signer("me", 1);
    Form* rrf;
    rrf = someRandomIntern.makeForm(ROBOT, "Bender");
    signer.signForm(*rrf);
    signer.executeForm(*rrf);
    delete rrf;
    rrf = someRandomIntern.makeForm(PRESID, "Biden");
    signer.signForm(*rrf);
    signer.executeForm(*rrf);
    delete rrf;
    rrf = someRandomIntern.makeForm(SHRUB, "Tree");
    signer.signForm(*rrf);
    signer.executeForm(*rrf);
    delete rrf;
    rrf = someRandomIntern.makeForm("random text", "tag");
}