#include <iostream>
#include <string>
#include <cmath>
#include<algorithm>
using namespace std;
class Solution {
public:
    int longestCommonSubsequence(std::string text1, std::string text2) {
        int dp[text1.size() + 1][text2.size() + 1];
        for(int i = 0; i <= text1.size(); i++)
        {
            for(int j = 0; j <= text2.size(); j++)
            {
                if(i > 0 && j > 0 && text1[i-1] == text2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else if(i == 0 || j == 0)
                    dp[i][j] = 0;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j - 1]);
            }
        }
        return dp[text1.size()][text2.size()];
    }
};

int main(void)
{
    std::string text1;
    std::string text2;
    Solution solution;

    while (1)
    {
        std::cout << "输入字符串1：";
        std::cin >> text1;
        std::cout << "输入字符串2：";
        std::cin >> text2;

        int result = solution.longestCommonSubsequence(text1, text2);
        std::cout << "最长公共子序列大小为：" << result  <<std::endl;

    }

    return 0;
}