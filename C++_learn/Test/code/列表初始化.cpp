#include <iostream>
int main(void)
{
    int max = 5;

    /*
    *一维数组可以通过列表初始化将所有值设为0，如，int num[10] = {};
    *二维数组只能采用以下方式初始化
    */
    int num[max][max] = {{1, 2, 3, 4, 5},
    {1, 2, 3, 4, 5},
    {1, 2, 3, 4, 5},
    {1, 2, 3, 4, 5},
    {1, 2, 3, 4, 5}};

    std::cout << "数组为：" << std::endl;
    for(int i = 0; i < max; i++)
    {
        for(int j = 0; j < max; j++)
            std::cout << num[i][j] << " ";
        std::cout << std::endl;
    }
    
    

    return 0;
}