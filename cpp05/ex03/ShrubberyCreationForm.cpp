/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 20:16:45 by bamrouch          #+#    #+#             */
/*   Updated: 2023/11/27 11:06:26 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

#define TREE_HEIGHT 8
#define TRUNK_WIDTH 3
#define TRUNK_HEIGHT 3

const char *ShrubberyCreationForm::FileErr::what() const throw()
{
    return "File err occured";
}

ShrubberyCreationForm::ShrubberyCreationForm():Form(SHRUB, 145, 137)
{};

ShrubberyCreationForm::ShrubberyCreationForm(const string &target_name):Form(SHRUB,  145, 137), target(target_name)
{};

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &cpy_shrubbery):Form(cpy_shrubbery)
{}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &eq_shrubbery)
{
    Form::operator=(eq_shrubbery);
    return (*this);
};

void   tree_branches(ofstream &outfile)
{
    int i = -1;
    int j = -1;
    
    while (++i < TREE_HEIGHT)
    {
        j = -1;
        while (++j <  TREE_HEIGHT - i)
            outfile << " ";
        j = -1;
        while (++j < (i * 2) - 1)
            outfile << "*";
        outfile << endl;
    }
}

void  tree_trunk(ofstream &outfile)
{
    size_t i = -1;
    size_t j = -1;
    
    while (++i < TRUNK_HEIGHT)
    {
        j = -1;
        while (++j < (2 * TREE_HEIGHT - TRUNK_WIDTH) / 2)
            outfile << " ";
        j = -1;
        while (++j < TRUNK_WIDTH)
            outfile << "|";
        outfile << endl;
    }
}

void  ShrubberyCreationForm::execute(const Bureaucrat &bureau)
{
    Form::check_signed(bureau);
    ofstream    outfile;
    outfile.open(target.append("_shrubbery").c_str(), ios::out | ios::trunc);
    if (!outfile)
        throw FileErr();
    tree_branches(outfile);
    tree_trunk(outfile);
    outfile.close();
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}