/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 14:28:13 by bamrouch          #+#    #+#             */
/*   Updated: 2023/10/01 16:33:32 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#define NAN "nan"
#define MIN_INF "-inf"
#define MAX_INF "+inf"

#define INT_MAX (2147483647)
#define INT_MIN (-2147483648)

void    undefined_print(string print)
{
    cout << "char: impossible"<< endl;
    cout << "int: impossible"<< endl;
    cout << "float: "<< print <<"f"<< endl;
    cout << "double: "<< print << endl;
}

bool    undefined_values(string literal)
{
    if (literal == NAN)
    {
        undefined_print(NAN);
        return true;
    }
    else if (literal == MIN_INF)
    {
        undefined_print(MIN_INF);
        return true;
    }
    else if (literal == MAX_INF)
    {
        undefined_print(MAX_INF);
        return true;
    }
    return false;
}


void    print_convertions(double dbl_conv, float float_conv, int int_convert, bool sets[3])
{
    cout << "char: ";
    if (!sets[2])
        cout << "impossible";
    else if (isprint(int_convert))
        cout << "'" << char(int_convert) << "'";
    else
        cout << "Non displayable";
    cout << endl;
    
    cout << "int: ";
    if (sets[2])
        cout << int_convert;
    else
        cout << "impossible";
    cout << endl;
    
    cout << "float: ";
    if (sets[1])
        cout << float_conv << "f";
    else
        cout << "impossible";
    cout << endl;
    
    cout << "double: ";
    if (sets[0])
        cout << dbl_conv;
    else
        cout << "impossible";
    cout << endl;
}

int main(int argc, char *argv[])
{

    double dbl_convert;
    float  float_convert;
    int    int_convert;
    bool   sets[3];

    if (argc == 2)
    {   
        if (undefined_values(argv[1]))
            return 0;
        try {
            dbl_convert = ScalarConverter::convert<double>(argv[1]);
            sets[0] = true;
        }
        catch (const invalid_argument &e)
        {
            sets[0] = false;
        }
        if (sets[0] && dbl_convert <= FLT_MAX && dbl_convert >= FLT_MIN)
        {
            float_convert = static_cast<float>(dbl_convert);
            sets[1] = true;
        }
        else
            sets[1] = false;
        if (sets[0] && dbl_convert <= static_cast<double>(INT_MAX) && dbl_convert >= static_cast<double>(INT_MIN))
        {
            int_convert = static_cast<int>(dbl_convert);
            sets[2] = true;
        }
        else
            sets[2] = false;
        print_convertions(dbl_convert, float_convert, int_convert, sets);
        return (0);
    }
    cerr << "Wrong input" << endl;
    return (1);
}