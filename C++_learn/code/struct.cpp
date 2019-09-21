#include <iostream>
#include <string>

struct inflatable
{
    std::string name;
    float volume;
    double price;
};

int main()
{
    using namespace std;

    inflatable struct1{"struct1", 12, 24};//c++11初始化方式只能在定义时初始化使用

    //struct1 = {"struct1", 12, 24};

    cout << "name: "<< struct1.name << endl
    << "volume: " << struct1.volume << endl
    << "price: " << struct1.price << endl;

    return 0;
}