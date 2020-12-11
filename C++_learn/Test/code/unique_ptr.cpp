#include <iostream>
#include <memory>
using namespace std;
int main() 
{
    unique_ptr<int> pInt(new int(5));
    unique_ptr<int> pInt2 = std::move(pInt); // 转移所有权
    cout << pInt.get() << endl; // 出错，pInt为空
    cout << *pInt2 << endl;
    unique_ptr<int> pInt3(std::move(pInt2));
}