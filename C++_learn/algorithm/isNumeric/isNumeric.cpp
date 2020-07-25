#include <iostream>
#include "isNumeric.h"
bool Numeric::scanUnsignedInteger(const char **str)
{
    const char *before = *str;
    while(**str != '\0' && **str <= '9' && **str >= '0')
        (*str)++;
    return (*str) > before;
}

bool Numeric::scanIneger(const char **str)
{
    if(**str == '+' || **str == '-')
        (*str)++;
    return Numeric::scanUnsignedInteger(str);
}

bool Numeric::IsNumeric(const char *str)
{
    if(str == nullptr)
        return false;
    
    bool numeric = Numeric::scanIneger(&str);
    
    if(*str == '.')
    {
        str++;
        numeric = Numeric::scanUnsignedInteger(&str) || numeric;
    }

    if(*str == 'e' || *str == 'E')
    {
        str++;
        numeric = numeric && Numeric::scanIneger(&str);
    }

    return numeric;
}