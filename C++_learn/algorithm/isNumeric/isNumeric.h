#ifndef _ISNUMERIC_H
#define _ISNUMERIC_H
class Numeric
{
    private:
        static bool scanUnsignedInteger(const char **str);
        static bool scanIneger(const char **str);
    public:
        static bool IsNumeric(const char *str);

};
#endif