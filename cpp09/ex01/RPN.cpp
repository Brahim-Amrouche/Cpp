/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:19:01 by bamrouch          #+#    #+#             */
/*   Updated: 2023/12/16 11:17:50 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

Rpn::RpnException::RpnException(RPN_ERRORS  err): err_c(err)
{
    switch (err_c)
    {
        case WRONG_TOKEN :
            msg = "Error: inputed wrong rpn token [0-9] or [+-*/]";
            break;
        case WRONG_SYNTAX:
            msg = "Error: wrong input sytax";
            break;
        case DIV_BY_ZERO:
            msg = "Error: divide by zero";
            break;
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
        {
            try {
                this->calculate(c);
            }
            catch (const Rpn::RpnException &e)
            {
                cout << e.what() << endl;
                return;  
            }
        }
    }
    if (rpn_stack.size() != 1)
        throw Rpn::RpnException(WRONG_SYNTAX);
    cout << rpn_stack.top() << endl;
}

long long Rpn::calc_plus(const long long &op1, const long long &op2)
{
    return (op1 + op2);
}

long long Rpn::calc_minus(const long long &op1, const long long &op2)
{
    return (op1 - op2);
}

long long Rpn::calc_mult(const long long &op1, const long long &op2)
{
    return (op1 * op2);
}

long long Rpn::calc_div(const long long &op1, const long long &op2)
{
    if (op2 == 0)
        throw Rpn::RpnException(DIV_BY_ZERO);
    return (op1 / op2);
}

void Rpn::calculate(char c)
{
    if (rpn_stack.empty())
        throw Rpn::RpnException(WRONG_SYNTAX);
    long long oper_2 = std::atoll((rpn_stack.top()).c_str());
    rpn_stack.pop();
    if (rpn_stack.empty())
        throw Rpn::RpnException(WRONG_SYNTAX);
    long long oper_1 = std::atoll((rpn_stack.top()).c_str());
    rpn_stack.pop();
    stringstream ss;
    switch (c)
    {
        case PLUS:
            ss << this->calc_plus(oper_1, oper_2);
            break;
        case MINUS:
            ss << this->calc_minus(oper_1, oper_2);
            break;
        case MULT:
            ss << this->calc_mult(oper_1, oper_2);
            break;
        case DIV:
            ss << this->calc_div(oper_1, oper_2);
            break;
        default:
            throw RpnException(WRONG_TOKEN);
    }
    rpn_stack.push(ss.str());
}

Rpn::~Rpn()
{}


