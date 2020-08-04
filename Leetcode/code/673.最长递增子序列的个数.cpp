#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int> dp; //用于保存每个数组大小情况下的最长递增子序列大小
        vector<int> dp_count;   //用于保存每个数组大小情况下最长递增子序列的数量
        dp.resize(nums.size());
        dp_count.resize(nums.size());
        int max_length = 0;
        int count = 1;
        for(int i = 0; i < nums.size(); i++)
        {
            int max = 1;
            dp_count[i] = 1;
            for(int j = 0; j < i; j++)
            {
                if(nums[i] > nums[j])
                {
                    if(dp[j] + 1 > max)
                    {
                        dp_count[i] = dp_count[j];
                        max = dp[j] + 1;
                    }
                    else if(dp[j] + 1 == max)
                        dp_count[i]+=dp_count[j];
                }
            }
            dp[i] = max;
            if(dp[i] > max_length)
            {
                max_length = dp[i];
                count = dp_count[i];
            }
            else if(dp[i] == max_length)
                count+=dp_count[i];
        }

        return dp_count[nums.size() - 1];
    }
};


int main(void)
{
    vector<int> nums;
    int n;
    Solution Solution1;
    while(1)
    {
        nums.clear();
        cout << "输入：" << endl;
        cin >> n;
        nums.resize(n);
        for(int i = 0; i < n; i++)
            cin >> nums[i];

        int result = Solution1.findNumberOfLIS(nums);

        cout << "输出：" << endl;
        cout << result << endl;
    }

    return 0;
}