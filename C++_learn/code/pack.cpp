#include<iostream>

struct c
{
    double d;
    char b;
    int a;
    short c;
};

#pragma pack(push)
#pragma pack(4)
struct b
{
    double d;
    char b;
    int a;
    short c;
};

#pragma pack(pop)

int main(void)
{
    using namespace std;

    c test;

    cout << "#pragma pack()" << endl;
    cout << "size:double: "<< sizeof(test.d) << endl;
    cout << "size:char: "<< sizeof(test.b) << endl;
    cout << "size:int: "<< sizeof(test.a) << endl;
    cout << "size:short: "<< sizeof(test.c) << endl;

    cout << "size:struct c: "<< sizeof(test) << endl << endl;

    b testb;
    cout << "#pragma pack(4)" << endl;
    cout << "size:double: "<< sizeof(testb.d) << endl;
    cout << "size:char: "<< sizeof(testb.b) << endl;
    cout << "size:int: "<< sizeof(testb.a) << endl;
    cout << "size:short: "<< sizeof(testb.c) << endl;

    cout << "size:struct c: "<< sizeof(testb) << endl;
}