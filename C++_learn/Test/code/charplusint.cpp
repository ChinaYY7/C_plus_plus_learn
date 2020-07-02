#include<iostream>
int main(void)
{
    std::string string1{"This is a test"};   
    unsigned int num = 5;

    std::string string2(string1.c_str() + num); 

    std::cout << "string1 = " << string1 << std::endl;
    std::cout << "string2 = " << string2 << std::endl;

    return 0;
}