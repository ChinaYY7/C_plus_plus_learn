#include <iostream>
int main(void)
{
    int n = 0;
    int result = 0;
    std::cin >> n;
    if(n >0 && n % 2 == 0)
        result = n / 2;
    else if(n >0)
        result = (n - 1) / 2;
    std::cout << result << std::endl;
    return 0;
}