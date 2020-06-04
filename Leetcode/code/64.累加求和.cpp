/*
求 1+2+...+n ，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。

示例 1:
输入: n = 3
输出: 6

示例 2:
输入: n = 9
输出: 45

类型：递归、逻辑运算
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution 
{
    private:
        int plus(int n)
        {
            //逻辑运算判断递归出口，对于&&运算，第一个为false，则不会继续执行之后的语句，对于||第一个为true，则不会执行之后的语句
            //n && (n += plus(n - 1));
            !n || (n += plus(n - 1));
            return n;
        }
    public:
        int sumNums(int n) 
        {
            return plus(n);
        }
};

//快速乘方式
class Sloution2
{
    private:
        int mul(int a, int b)
        {
            int res = 0;
            int tempa = a; //暂存a值，用于回溯时候
            (b & 1 || (b && !(res = mul(a<<=1, b>>=1)))) && (res = tempa + mul(a<<=1, b>>=1));
            return res;
        }
    public:
        int sumNums(int n) 
        {
            return mul(n, n + 1) >> 1;
        }
};

int main(void)
{
    Solution plus_solution;
    Sloution2 plus_solution2;
    int sum = 0;
    int n;
    char ch;
    
    while(1)
    {
        cout << "输入n：";
        cin >> n;
        cin.get(ch);

        cout << "n:" << n << endl;
        //sum = plus_solution.sumNums(n);
        sum = plus_solution2.sumNums(n);

        cout << "结果为：" << sum << endl;
    }

    return 0;
}