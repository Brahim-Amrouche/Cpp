/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:31:22 by bamrouch          #+#    #+#             */
/*   Updated: 2023/09/14 12:58:22 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef HARL_H
#define HARL_H

#include "string"
#include "iostream"

using std::cout;
using std::endl;
using std::string;

enum harLevels
{
    DEBUG,
    INFO,
    WARNING,
    ERROR,
    NONE,
};

class Harl
{
    private:
        harLevels  h_level;
        void debug( void );
        void info( void );
        void warning( void );
        void error( void );
        void (Harl::*complain_fn[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
        string  complains_str[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    public:
        Harl    ();
        Harl    (const Harl &cpy_harl);
        Harl    &operator=(const Harl &eq_harl);
        void    complain(string level);
        ~Harl();
};


#endif