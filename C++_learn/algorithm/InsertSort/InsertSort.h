#ifndef _INSERTSORT_H
#define _INSERTSORT_H
#include <vector>


template<typename T>
class InsertSort
{
    public:
        void DirectInsertSort(std::vector<T> & unordered_number);
        void BiInsertSort(std::vector<T> & unordered_number);
        void ShellSort(std::vector<T> & unordered_number);
};

//直接插入
template<typename T>
void InsertSort<T>::DirectInsertSort(std::vector<T> & unordered_number)
{
    for(int i = 1; i < unordered_number.size(); i++)
    {
        int temp = unordered_number[i];
        int j;
        for(j = i - 1; j >= 0 && temp < unordered_number[j]; j--)
            unordered_number[j+1] = unordered_number[j];

        unordered_number[j+1] = temp;
    }
}

//折半插入
template<typename T>
void InsertSort<T>::BiInsertSort(std::vector<T> & unordered_number)
{
    for(int i = 1; i < unordered_number.size(); i++)
    {
        int j;
        int mid, up = i, down = 0;
        int temp = unordered_number[i];

        //必须down大于up后，down的位置就是大于或等于数据的后面
        while(up >= down)
        {
            mid = (up + down) / 2;
            if(temp < unordered_number[mid])
                up = mid - 1;
            else
                down = mid + 1;
        }
        for(j = i - 1; j >= down; j--)
            unordered_number[j+1] = unordered_number[j];

        //down位置原始数据已经移到下一位，此时可以放比对的那个数据
        unordered_number[down] = temp;
    }
}

//希尔排序
template<typename T>
void InsertSort<T>::ShellSort(std::vector<T> & unordered_number)
{
    for(int d = unordered_number.size() / 2; d >= 1; d /= 2)
    {
        for(int i = d; i < unordered_number.size(); i++)
        {
            int temp = unordered_number[i];
            int j;
            //通过直接排序轮流调整各个子数组中的顺序
            for(j = i - d; j >= 0 && temp < unordered_number[j]; j-=d)
                unordered_number[j + d] = unordered_number[j];
            unordered_number[j + d] = temp;
        }
    }
}

#endif