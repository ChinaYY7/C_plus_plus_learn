#include <iostream>
#include <cstring>
#include <chrono>
#define SIZE 100000

#define START_TIMER auto start = std::chrono::high_resolution_clock::now();
#define STOP_TIMER(print_message) std::cout << print_message << \
    std::chrono::duration_cast<std::chrono::microseconds>( \
    std::chrono::high_resolution_clock::now() - start).count() \
    << " us " << std::endl;

inline std::chrono::high_resolution_clock::time_point Start_time()
{
    return std::chrono::high_resolution_clock::now();
}
            
//单位:us
inline int64_t Duration(std::chrono::high_resolution_clock::time_point start_time)
{
    return std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - start_time).count();
}

int main(void)
{
    double test0[SIZE];
    double *ptest0 = new double[SIZE];

    double test1[SIZE];
    double *ptest1 = new double[SIZE];
    std::chrono::high_resolution_clock::time_point start_time;
    int64_t duration_time;

    memset(test0, 1, SIZE * sizeof(double));
    start_time = Start_time();
    for(uint64_t i = 0; i < SIZE; i++)
        ptest0[i] = test0[i];
    duration_time = Duration(start_time);
    std::cout << "for spend time:" << duration_time << " us" << std::endl;

    memset(test1, 1, SIZE * sizeof(double));
    start_time = Start_time();
    memcpy(ptest1, test1, SIZE * sizeof(double));
    duration_time = Duration(start_time);
    std::cout << "memcpy spend time:" << duration_time << " us"  << std::endl;
}