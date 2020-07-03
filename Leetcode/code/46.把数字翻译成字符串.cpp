/*
给定一个数字，我们按照如下规则把它翻译为字符串：0 翻译成 “a” ，1 翻译成 “b”，……，11 翻译成 “l”，……，25 翻译成 “z”。一个数字可能有多个翻译。请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法。

示例 1:

输入: 12258
输出: 5
解释: 12258有5种不同的翻译，分别是"bccfi", "bwfi", "bczi", "mcfi"和"mzi"

类型：动态规划
*/
#include<iostream>
#include<vector>
#include<array>
using namespace std;

//动态规划
class Solution {
public:
    int translateNum(int num) 
    {
        vector<int> num_element;
        int dp[3];

        if(num < 10)
            return 1;

        while(num)
        {
            num_element.push_back(num % 10);
            num /= 10;
        }
        
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 1;

        for(int i = num_element.size() - 1; i >= 0; i--)
        {
            if(num_element[i] == 0)
                continue;
            
            dp[0] = dp[1];
            dp[1] = dp[2];
            dp[2] = 0;
            int temp = num_element[i] * 10 + num_element[i - 1];
            if(temp > 9 && temp < 26)
                dp[2] = dp[1] + dp[0];
            else
                dp[2] = dp[1];
        }

        return dp[2];
    }
};


//递归做法
class Solution1 {
public:
    int translateNum(int num) {
        if (num == 0) return 1;
        return f(num);
    }

    int f(int num) {
        if (num < 10) {
            return 1;
        }
        if (num % 100 < 26 && num % 100 > 9) {
            return f(num / 10) + f(num / 100);
        } else {
            return f(num / 10);
        }
    }
};

int main(void)
{
    int num;

    Solution Solution1;
    
    while(1)
    {
        cout << "输入一个数字：" << endl;
        cin >> num;

        cout << "nums:";
        cout << num << endl;

        int result = Solution1.translateNum(num);
        cout << "结果为：";
        cout << result << endl;
    }

    return 0;
}