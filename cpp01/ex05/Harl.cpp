/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:31:29 by bamrouch          #+#    #+#             */
/*   Updated: 2023/09/14 13:03:47 by bamrouch         ###   ########.fr       */
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

void    Harl::warning(void)
{
    cout << "This is unacceptable! I want to speak to the manager now." << endl;
}

Harl::Harl(void):h_level(NONE)
{};

Harl::Harl(const Harl &cpy_harl):h_level(cpy_harl.h_level)
{};

Harl &Harl::operator=(const Harl &eq_harl)
{
    h_level = eq_harl.h_level;
}

void    Harl::complain(string level)
{
    int i = -1;

    while (++i < 4)
        if (level == complains_str[i])
            h_level = static_cast<harLevels>(i);
    switch (h_level)
    {
        case DEBUG:
        {
            (this->*complain_fn[h_level])();        
            break;
        }
        case INFO:
        {
            (this->*complain_fn[h_level])();        
            break;
        }
        case WARNING:
        {
            (this->*complain_fn[h_level])();        
            break;
        }
        case ERROR:
        {
            (this->*complain_fn[h_level])();        
            break;
        }
        default:
            break;
    }
}


Harl::~Harl(void)
{};
