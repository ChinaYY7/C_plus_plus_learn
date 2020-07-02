#include <iostream>
#include <string>

template<typename T>
void show_list(T value)
{
    std::cout << value << std::endl;
}

template<typename T, typename... Args>
void show_list(T value, Args... args)
{
    std::cout << value << ",";
    show_list(args...);
}

int main()
{
    int n = 14;
    double x = 2.71828;
    std::string mr = "Mr. string objects !";
    show_list(n,x);
    show_list(x*x, '!', 7, mr);

    return 0;
}