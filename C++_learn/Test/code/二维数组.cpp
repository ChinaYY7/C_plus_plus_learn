#include <iostream>

void print_num(int (*martix)[5], int n)
{
    int i, j;
    for (i = 0;i < 2; i++)
    {
        for (j = 0; j < n; j++)
        {
            std::cout << martix[i][j] << std::endl;
        }
    }
}

int main(void)
{
    int matix[2][5] = {{1,2,3,4,5},{6,7,8,9,0}};

    print_num(matix, 5);

    return 0;
}