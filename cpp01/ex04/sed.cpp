/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 01:38:13 by bamrouch          #+#    #+#             */
/*   Updated: 2023/09/13 11:50:16 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.hpp"

Sed::Sed(string in_path, string out_path)
{
    infile.open(in_path, ios::in);
    if (!infile)
        cerr << "coulnd't open input file" << endl;
    outfile.open(out_path, ios::out | ios::trunc);
    if (!outfile)
        cerr << "couldn't open output file" << endl;
};

Sed::Sed(const Sed &cpy_sed)
{
    infile.copyfmt(cpy_sed.infile);
    infile.clear();
    outfile.copyfmt(cpy_sed.outfile);
    outfile.clear();
};

Sed &Sed::operator=(const Sed &eq_sed)
{
    infile.copyfmt(eq_sed.infile);
    infile.clear();
    outfile.copyfmt(eq_sed.outfile);
    outfile.clear();   
};

bool    Sed::replace_in_file(string s1, string s2)
{
    if (!infile || !outfile)
        return false;
    while (getline(infile, line))
    {
        replace(s1, s2);
        outfile << line << endl;
    }
    return true;
}

void    Sed::replace(string s1, string s2)
{
    size_t last_find = 0;
    size_t s1_len = s1.size();
    size_t s2_len = s2.size();

    last_find = line.find(s1, 0);
    while (last_find != string::npos)
    {
        line.erase(last_find, s1_len);
        line.insert(last_find, s2);
        last_find = line.find(s1, last_find + s2_len);
    }
}

Sed::~Sed()
{
    infile.close();
    outfile.close();
}