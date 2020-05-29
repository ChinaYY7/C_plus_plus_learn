/*
你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。

示例 1:
输入: [1,2,3,1]
输出: 4
解释: 偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
    偷窃到的最高金额 = 1 + 3 = 4 。

示例 2:
输入: [2,7,9,3,1]
输出: 12
解释: 偷窃 1 号房屋 (金额 = 2), 偷窃 3 号房屋 (金额 = 9)，接着偷窃 5 号房屋 (金额 = 1)。
    偷窃到的最高金额 = 2 + 9 + 1 = 12 。

类型：动态规划
*/
#include<iostream>
#include<vector>
using namespace std;
class Solution 
{
    public:
        int rob(vector<int>& nums) 
        {
            if(nums.empty())
                return 0;

            int size = nums.size();
            if(size == 1)
                return nums[0];

            int max_money[3];
            max_money[0] = nums[0];
            max_money[1] = max(nums[0], nums[1]);
            
            int i;
            for(i = 2; i < size; i++)
            {
                max_money[2] = max(max_money[1], max_money[0] + nums[i]);
                max_money[0] = max_money[1];
                max_money[1] = max_money[2];
            }
            if(size > 2)
                return max_money[2];
            else
                return max_money[1];
        }
};

int main(void)
{
    Solution rob_solution;
    vector<int> nums;
    int i = 0;
    int temp;
    char ch;
    
    while(1)
    {
        nums.clear();
        cout << "输入一个数组(回车结束)：" << endl;
        while(1)
        {
            cin >> temp;
            nums.push_back(temp);
            cin.get(ch);
            if(ch == '\n')
            break;
        }

        cout << "nums:";
        for(int i = 0; i < nums.size(); i++)
        cout << nums[i] << " ";
        cout << endl;

        int solution_max = rob_solution.rob(nums);
        cout << "计算结果为:" << solution_max << endl;
    }

    return 0;
}