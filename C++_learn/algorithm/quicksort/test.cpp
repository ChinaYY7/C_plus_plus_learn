#include<iostream>
#include<algorithm>
#include<exception>
#include "quicksort.h"

int main(void)
{
    double data[5];
    sort<double> QuickSort;
    
    while(1)
    {
        std::cout << "请输入5个数字:"; 
        for(int i = 0; i < 5; i++)
            std::cin >> data[i];

        try
        {
            QuickSort.quick_sort(data, 5);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    
        std::cout << "执行次数：" << QuickSort.get_count() << std::endl; 
        std::cout << "排序结果为:" ;
        for(int i = 0; i < 5; i++)
            std::cout << data[i] << " ";
        
        std:: cout << std::endl;
        
    }
}