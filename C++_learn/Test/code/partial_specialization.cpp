/*
概述：
    模板类部分具体化的使用问题
*/
#include<iostream>
template <typename T1, typename T2, typename T3>
class test
{
    private:
        T1 num1;
        T2 num2;
        T3 num3;
    public:
        test(){}

        test(T1 n1, T2 n2, T3 n3):num1(n1), num2(n2), num3(n3)
        {

        }

        void show()
        {
            std::cout << "This is general template:" << num1 << " " << num2 << " " << num3 << std::endl;
        }
};

template <typename T1, typename T2>
class test<T1, T2, T2>
{
    private:
        T1 num1;
        T2 num2;
        T2 num3;
    public:
        test(){}

        test(T1 n1, T2 n2, T2 n3):num1(n1), num2(n2), num3(n3)
        {

        }

        void show()
        {
            std::cout << "This is template <typename T1, typename T2> template:" << num1 << " " << num2 << " " << num3 << std::endl;
        }
};

template <typename T1>
class test<T1, T1*, T1*>
{
    private:
        const T1 num1;
        const T1 *num2;
        const T1 *num3;
    public:
        test(){}

        test(const T1 n1, const T1 *n2, const T1 *n3):num1(n1), num2(n2), num3(n3)
        {

        }

        void show() const
        {
            std::cout << "This is template <typename T1> template:" << num1 << " " << num2 << " " << num3 << std::endl;
        }
};

int main(void)
{
    test<int, double, float> test1(1, 1.2, 2.2);
    test1.show();

    test<int, double, double> test2(1, 1.2, 2.2);
    test2.show();

    test<char, char *, char *> test3('A', "test", "test2");
    test3.show();
    return 0;
}
