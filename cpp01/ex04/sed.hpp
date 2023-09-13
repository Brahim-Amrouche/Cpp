/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 01:38:18 by bamrouch          #+#    #+#             */
/*   Updated: 2023/09/13 11:46:04 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SED_H
#define SED_H

#include "string"
#include "iostream"
#include "fstream"

using std::cin;
using std::cerr;
using std::endl;
using std::string;
using std::ifstream;
using std::getline;
using std::ofstream;
using std::ios;


class Sed
{
    private:
        ifstream infile;
        ofstream outfile;
        string  line;
    public:
        Sed		(string in_path, string out_path);
        Sed		(const Sed &cpy_sed);
		Sed		&operator=(const Sed &eq_sed);
        ~Sed	(void);
        bool    replace_in_file(string s1, string s2);
        void    replace(string s1, string s2);

};


#endif