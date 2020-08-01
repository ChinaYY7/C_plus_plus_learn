#include<iostream>
#include<algorithm>
#include<exception>
#include<vector>
#include "InsertSort.h"

using namespace std;
int main(void)
{
    InsertSort<int> insertsort;
    vector<int> numbers;

    while(1)
    {
        int count = 0;
        cout << "输入数组大小：";
        cin >> count;
        cout << "请输入 " << count << "个数字" << endl; 
        numbers.clear();
        for(int i = 0; i < count; i++)
        {
            int temp;
            cin >> temp;
            numbers.push_back(temp);
        }

        insertsort.ShellSort(numbers);

        std::cout << "排序结果为:" ;
        for(int i = 0; i < count; i++)
            std::cout << numbers[i] << " ";
        
        std:: cout << std::endl;
        
    }
}