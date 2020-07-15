#include <iostream>

class A
{
    private:
        int A_a;
    public:
        int A_b = 12;
    protected:
        int A_c;
};

class B : protected A
{   
    private:
        int B_A = A_b;

    public:
        void show()
        {
            std::cout << B_A << std::endl;
        }
};

class C : protected B
{
    public:
        void show()
        {
            std::cout << A_b << std::endl;
        }
};
int main(void)
{
    C c;
    c.show();

    B b;
    b.show();

    return 0;
}