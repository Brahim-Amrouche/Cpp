/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 19:04:35 by bamrouch          #+#    #+#             */
/*   Updated: 2023/11/27 09:24:57 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "fstream"

using std::ofstream;
using std::ios;

class ShrubberyCreationForm : public AForm
{
    private:
        string target;
    public :
        class FileErr: public exception
        {
            const char *what() const throw();
        };
        ShrubberyCreationForm();
        ShrubberyCreationForm(const string &target_name);
        ShrubberyCreationForm(const ShrubberyCreationForm &cpy_shrubbery);
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &eq_shrubbery);
        ~ShrubberyCreationForm();
        void execute(const Bureaucrat &bureau);
};

