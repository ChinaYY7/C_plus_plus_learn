#ifndef _QUICKSORT_H
#define _QUICKSORT_H

#include<iostream>
#include<algorithm>
#include<exception>

/*
快速排序
最优的情况是在选择比对的值位于整个数组有序中间的数值
最差的情况是选择比对的值位于整个数组有序后最大的数值
*/
template<typename T>
class sort
{
    private:
        static long count;
        int quick_sort_one(T data[], int len, int start, int end);
        void quick_sort(T data[], int len, int start, int end);
    
    public:
        void quick_sort(T data[], int len);
        long get_count(){return count;}
};

template <typename T>
long sort<T>::count = 0; 

template <typename T>
int sort<T>::quick_sort_one(T data[], int len, int start, int end)
{
    if(data == nullptr || len <= 0 || start > end || start < 0 || end >= len)
    {
        throw new std::logic_error("Invalid Parameters.");
    }

    int small = start - 1;
    int index;
    for(index = start; index < end; index++)
    {
        count++;
        if(data[index] < data[end])
        {
            small++;
            if(small != index)
                std::swap(data[index], data[small]);
        }
    }
    small++;
    std::swap(data[small], data[end]);

    return small;
}

template<typename T>
void sort<T>::quick_sort(T data[], int len, int start, int end)
{
    if(start == end)
        return;

    int index = quick_sort_one(data, len, start, end);
    if(index < end)
        quick_sort(data, len, index + 1, end);
    if(index > start)
        quick_sort(data, len, start, index - 1);
}

template<typename T>
void sort<T>::quick_sort(T data[], int len)
{
    count = 0;
    quick_sort(data, len, 0, len -1);
}

#endif