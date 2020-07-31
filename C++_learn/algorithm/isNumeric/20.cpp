#include <iostream>
#include <string>
#include "isNumeric.h"
using namespace std;
int main()
{
    string numeric;
    while(1)
    {
        cout << "输入数值字符：";
        cin >> numeric;
        bool result = Numeric::IsNumeric(numeric.c_str());
        cout << "是否是数组：" << (result == true ? "是":"否") << endl;
    }
    return 0;
}