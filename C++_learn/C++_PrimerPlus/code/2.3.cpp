#include <iostream>

void fun_1(void)
{
    std::cout << "Three blind mice" << std::endl;
}

void fun_2(void)
{
    std::cout << "See how they run" << std::endl;
}

int main(void)
{
    fun_1();
    fun_1();
    fun_2();
    fun_2();

    return 0;
}