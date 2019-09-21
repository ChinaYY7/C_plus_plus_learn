#include<mutex>
#include<iostream>
#include<thread>
std::mutex mtx;
std::mutex mtx1;
long counter = 0;

void func() 
{
    for (int i = 0; i < 10000; ++i)
    {
        mtx.lock();
        ++counter;
        mtx.unlock();
    }
}

int main ()
{
    std::thread threads[10];

    for (int i = 0; i < 10; ++i)
    {
        threads[i] = std::thread(func);
    }

    for (auto& th : threads)
    {
        th.join();
    }
    {
        std::lock_guard<std::mutex> guard(mtx1);
        std::cout << mtx1.try_lock() << std::endl;  // 0，互斥量被占用
    }
    std::cout << mtx1.try_lock() << std::endl;     // 1，互斥量释放 
    mtx.unlock();
    std::cout << counter << std::endl;   // 100000

    return 0;
}
