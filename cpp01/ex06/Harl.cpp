/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:31:29 by bamrouch          #+#    #+#             */
/*   Updated: 2023/09/20 13:19:32 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void    Harl::debug(void)
{
    cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << endl;
}

void    Harl::info(void)
{
    cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << endl;
}

void    Harl::warning(void)
{
    cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << endl;
}

void    Harl::error(void)
{
    cout << "This is unacceptable! I want to speak to the manager now." << endl;
}

Harl::Harl(void):h_level(NONE)
{
    Complains_list[0] = &Harl::debug;
    Complains_list[1] = &Harl::info;
    Complains_list[2] = &Harl::warning;
    Complains_list[3] = &Harl::error;

    complains_str[0] = "DEBUG";
    complains_str[1] = "INFO";
    complains_str[2] = "WARNING";
    complains_str[3] = "ERROR";
};

Harl::Harl(const Harl &cpy_harl):h_level(cpy_harl.h_level)
{
    Complains_list[0] = &Harl::debug;
    Complains_list[1] = &Harl::info;
    Complains_list[2] = &Harl::warning;
    Complains_list[3] = &Harl::error;

    complains_str[0] = "DEBUG";
    complains_str[1] = "INFO";
    complains_str[2] = "WARNING";
    complains_str[3] = "ERROR";
};

Harl &Harl::operator=(const Harl &eq_harl)
{
    h_level = eq_harl.h_level;
    return (*this);
}

void    Harl::complain(string level)
{
    int i = -1;

    h_level = NONE;
    while (++i < 4)
        if (level == complains_str[i])
            h_level = static_cast<harLevels>(i);
    while (h_level != NONE)
    {
        switch (h_level)
        {
            case DEBUG:
            {
                (this->*Complains_list[h_level])();        
                h_level = INFO;
                break;
            }
            case INFO:
            {
                (this->*Complains_list[h_level])();        
                h_level = WARNING;
                break;
            }
            case WARNING:
            {
                (this->*Complains_list[h_level])();        
                h_level = ERROR;
                break;
            }
            case ERROR:
            {
                (this->*Complains_list[h_level])();
                h_level = NONE;  
                break;
            }
            default:
             break;
        }
    }
    
}


Harl::~Harl(void)
{};
