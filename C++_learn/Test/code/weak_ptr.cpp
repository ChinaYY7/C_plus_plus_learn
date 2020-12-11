#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class ClassB;

class ClassA
{
    public:
    ClassA() { cout << "ClassA Constructor..." << endl; }
    ~ClassA() { cout << "ClassA Destructor..." << endl; }
    weak_ptr<ClassB> pb; // 在A中引用B
};

class ClassB
{
    public:
    ClassB() { cout << "ClassB Constructor..." << endl; }
    ~ClassB() { cout << "ClassB Destructor..." << endl; }
    weak_ptr<ClassA> pa; // 在B中引用A
};

int main() 
{
    shared_ptr<ClassA> spa = make_shared<ClassA>();
    shared_ptr<ClassB> spb = make_shared<ClassB>();
    spa->pb = spb;
    spb->pa = spa;
    // 函数结束，这里会释放资源了
}