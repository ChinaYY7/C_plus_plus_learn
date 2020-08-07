#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class ClassA
{
    private:
        
    public:
        static int count;
        ClassA()
        {
            count++;
            cout << "ClassA constructed:" << count << endl;
        }

        ~ClassA()
        {
            count--;
            cout << "ClassA destroy:" << count << endl;
        }
};

int ClassA::count = 0;

class ClassB
{
    public:
        ClassB()
        {
            cout << "ClassB constructed" << endl;
        }

        ~ClassB()
        {
            cout << "ClassB destroy" << endl;
        }
};

int main() 
{   
    shared_ptr<ClassA> CA(new ClassA);
    cout << "当前CA引用计数：" << CA.use_count() << endl; // use_count = 1
    shared_ptr<ClassA> CA1(CA);
    cout << "当前CA引用计数：" << CA1.use_count() << endl; // use_count = 1

    shared_ptr<ClassA> CAA(new ClassA);
    cout << "当前CAA引用计数：" << CAA.use_count() << endl; // use_count = 1
    //已经初始化后的share_ptr 再次赋值，会将之前引用减1，新的引用+1
    CA1 = CAA;
    cout << "当前CAA引用计数：" << CAA.use_count() << endl; // use_count = 1
    cout << "当前CA引用计数：" << CA.use_count() << endl; // use_count = 1

    auto_ptr<ClassA> aCA(new ClassA);
    auto_ptr<ClassA> aCA1(new ClassA);

    cout << "address aCA:" << aCA.get() << endl;
    cout << "address aCA1:" << aCA1.get() << endl;

    aCA = aCA1;
    
    cout << "address aCA:" << aCA.get() << endl;
    cout << "address aCA1:" << aCA1.get() << endl;
    return 0;
}