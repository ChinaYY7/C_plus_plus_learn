#ifndef _QUICKSORT_H
#define _QUICKSORT_H

#include<iostream>
#include<algorithm>
#include<exception>

template<typename T>
class sort
{
    private:
        int quick_sort_one(T data[], int len, int start, int end);
        void quick_sort(T data[], int len, int start, int end);
    
    public:
        void quick_sort(T data[], int len);
};

template<typename T>
int sort<T>::quick_sort_one(T data[], int len, int start, int end)
{
    if(data == nullptr || len <= 0 || start > end || start < 0 || end >= len)
    {
        std::logic_error ex("Invalid Parameters.");
        throw new std::exception(ex);
    }

    int small = start - 1;
    int index;
    for(index = start; index < end; index++)
    {
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
    quick_sort(data, len, 0, len -1);
}

#endif