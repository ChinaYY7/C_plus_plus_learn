#include <iostream>

int main(void)
{
    float Cle_degree;
    float Fah_degree;

    std::cout << "Please enter a Celsius value: ";
    std::cin >> Cle_degree;

    Fah_degree = Cle_degree * 1.8 + 32.0;

    std::cout << Cle_degree << " degrees Celsius is " << Fah_degree << " degrees Fahrenheit" << std::endl;

    return 0;
}