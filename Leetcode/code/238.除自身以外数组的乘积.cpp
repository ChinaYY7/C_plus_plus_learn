/*
给你一个长度为 n 的整数数组 nums，其中 n > 1，返回输出数组 output ，其中 output[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积。

示例 1:
输入: [1,2,3,4]
输出: [24,12,8,6]

类型：节约内存
*/
#include<iostream>
#include<vector>
using namespace std;
class Solution1 
{
    public:
        vector<int> productExceptSelf(vector<int>& nums) 
        {
            vector<int> L;
            vector<int> R;
            vector<int> res;
            L.resize(nums.size());
            R.resize(nums.size());
            res.resize(nums.size());
            L[0] = 1;
            R[nums.size()-1] = 1;
            for(int i = 1; i < nums.size(); i++)
                L[i] = L[i-1] * nums[i - 1];
            for(int i = nums.size() - 2; i >= 0; i--)
                R[i] = R[i+1] * nums[i+1];
            for(int i = 0; i < nums.size(); i++)
                res[i] = L[i] * R[i];

            return res;
        }
};

class Solution2
{
    public:
        vector<int> productExceptSelf(vector<int>& nums) 
        {
            vector<int> answer;
            answer.resize(nums.size());

            answer[0] = 1;
            int R = 1;
            for(int i = 1; i < nums.size(); i++)
                answer[i] = answer[i-1] * nums[i - 1];
            for(int i = nums.size() - 1; i >= 0; i--)
            {
                answer[i] = answer[i] * R;
                R *= nums[i];
            }
            
            return answer;
        }
};

int main(void)
{
    Solution2 mul_solution2;
    vector<int> nums;
    vector<int> res;
    int i = 0;
    int temp;
    char ch;
    
    while(1)
    {
        nums.clear();
        res.clear();
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

        res = mul_solution2.productExceptSelf(nums);
        for(int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}