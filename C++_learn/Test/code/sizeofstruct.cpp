#include <iostream>
/*
数据对齐
1.数据对齐是指在处理结构体中成员时，成员在内存中的起始地址编码必须是成员类型所占字节数的整数倍
2.结构体sizeof的计算结果必须是结构体中占用空间最多的成员所占空间的整数倍
3.数据对齐时，要以结构体中最深层的基本数据类型为准
*/
struct s1
{
    char a;
    short b;
    int c;
    double d;
};

struct s2
{
    char a;
    double b;
    short c;
    int d;
};

struct s3
{
    int a;
};

struct s4
{
    char a[4];
};

struct s5
{
    char a[4];
    char b;
};

struct s6
{
    s3 a;
    char b;
};

struct s7
{
    s4 a;
    char b;
};

int main()
{
    std::cout << "sizeof struct1:" << sizeof(s1) << std::endl;
    std::cout << "sizeof struct2:" << sizeof(s2) << std::endl;
    std::cout << "sizeof struct3:" << sizeof(s3) << std::endl;
    std::cout << "sizeof struct4:" << sizeof(s4) << std::endl;
    std::cout << "sizeof struct5:" << sizeof(s5) << std::endl;
    std::cout << "sizeof struct6:" << sizeof(s6) << std::endl;
    std::cout << "sizeof struct7:" << sizeof(s7) << std::endl;
    std::cout << "sizeof void *:" << sizeof(void *) << std::endl;
    return 0;
}