#include <iostream>
int main(void)
{
    int j = 0;
    for(int i = 0; i < 10; i++)
        j = (j++);        //

    std::cout << "j = " << j << std::endl;
    return 0;
}