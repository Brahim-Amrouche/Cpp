#include "ScalarConverter.hpp"

const char *ImpException::what() const throw()
{
    return "impossible to parse";
}

double double_conv(const string &input)
{
    const char *p = input.c_str();
    char *end;
    double value = std::strtod(p, &end);
    if (p != end && (end[0] == 0 || (end[0] == 'f' && end[1] == 0)))
    {
        return value;
    }
    else
        throw ImpException();
}

bool    double_has_decimal(const string &dbl_str)
{
    size_t i = -1;
    while (dbl_str[++i])
    {
        if (std::isdigit(dbl_str[i]))
            continue;
        else
            return true;
    }
    return false;
}

void float_conv(const double &dbl_val, const string &dbl_str ,string &flt_str)
{
    float flt_val = 0;
    if (dbl_str == "nan" || dbl_str == "inf" || dbl_str == "-inf")
        flt_str = dbl_str + "f";
    else if (dbl_str == "impossible")
        flt_str = dbl_str;
    else if (std::abs(dbl_val) <= FLT_MAX)
    {
        flt_val = static_cast<float>(dbl_val);
        std::stringstream ss;
        ss << flt_val;
        ss >> flt_str;
        string tmp;
        ss.clear();
        ss << dbl_val;
        ss >> tmp;
        if (!double_has_decimal(tmp))
            flt_str += ".0f";
        else
            flt_str += 'f';
    }
    (void) flt_val;
}

void int_conv(const double &dbl_val, const string &dbl_str, string &int_str)
{
    int_str = "impossible";
    int int_val = 0;
    if (dbl_str == "impossible" || dbl_str == "nan" || dbl_str == "inf" || dbl_str == "-inf")
        return ;
    else if (dbl_val <= INT_MAX && dbl_val >= INT_MIN)
    {
        int_val = static_cast<int>(dbl_val);
        int_str = "";
        std::stringstream ss;
        ss << int_val;
        ss >> int_str;
    }
    (void) int_val;
}

void    char_conv(const double &dbl_val, const string &dbl_str, string &c_str)
{
    char c = 0;
    c_str = "impossible";
    if (dbl_str == "impossible" || dbl_str == "nan" || dbl_str == "inf" || dbl_str == "-inf")
        return;
    else if (dbl_val >= -0.001 && dbl_val <= 255)
    {
        c = static_cast<unsigned char>(dbl_val);
        if (std::isprint(c))
        {
            c_str = "";
            c_str.push_back('\'');
            c_str.push_back(c);
            c_str.push_back('\'');
        }
        else
        {
            c_str = "Non displayable";
            return;
        }
    }
    (void) c;
}

void print_convertion(const string &dbl_str, const string &flt_str, const string &int_str, const string &c_str)
{
    (void) dbl_str;
    (void) flt_str;
    (void) c_str;
    cout << "char: " << c_str << endl;
    cout << "int: " << int_str << endl;
    cout << "float: "<< flt_str << endl;
    cout << "double: " << dbl_str << endl;
}

ScalarConverter::ScalarConverter()
{}

ScalarConverter::ScalarConverter(const ScalarConverter &cpy)
{
    (void) cpy;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &eq)
{
    (void) eq;
    return *this;
}



void ScalarConverter::Convert(const string str)
{
    string dbl_str, flt_str, int_str, c_str;
    double dbl_val = 0;
    try
    {
        dbl_val = double_conv(str);
        std::stringstream ss;
        ss << dbl_val;
        ss >> dbl_str;
        if (!double_has_decimal(dbl_str))
            dbl_str += ".0";
    }
    catch(const ImpException &e)
    {
        dbl_str = "impossible";
    }
    float_conv(dbl_val, dbl_str, flt_str);
    int_conv(dbl_val, dbl_str, int_str); 
    char_conv(dbl_val, dbl_str, c_str);
    print_convertion(dbl_str, flt_str, int_str, c_str);
}

ScalarConverter::~ScalarConverter()
{}

