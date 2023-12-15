/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:19:01 by bamrouch          #+#    #+#             */
/*   Updated: 2023/12/15 18:34:32 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

Rpn::RpnException::RpnException(RPN_ERRORS err): err_c(err)
{
    switch (err_c)
    {
        case RPN_ERRORS::WRONG_TOKEN :
            msg = "Error: inputed wrong rpn token [0-9] or [+-*/]";
            break;
        case RPN_ERRORS::WRONG_SYNTAX:
            msg = "Error: wrong input sytax";
        default:
            msg = "Error: Unknown";
            break;
    }
}

const char *Rpn::RpnException::what() const throw()
{
    return msg.c_str();
}

Rpn::RpnException::~RpnException() throw()
{}

Rpn::Rpn(const string &input)
{
    size_t i = -1;
    while (++i < input.size())
    {
        char c = input[i];
        if (std::isdigit(c))
            rpn_stack.push(string(1, input[i]));
        else if (c == ' ' || c == '\t')
            continue;
        else
            this->calculate(c);   
    }
    if (rpn_stack.empty())
        throw Rpn::RpnException(RPN_ERRORS::WRONG_SYNTAX);
}

void Rpn::calculate(char c)
{
    switch (c)
    {
        case PLUS:
            this->calc_plus();
            break;
        case MINUS:
            this->calc_minus();
            break;
        case MULT:
            this->calc_mult();
            break;
        case DIV:
            this->calc_div();
            break;
        default:
            throw RpnException(RPN_ERRORS::WRONG_TOKEN);
    }
}

Rpn::~Rpn()
{}


