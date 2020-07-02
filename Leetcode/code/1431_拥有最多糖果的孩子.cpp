/*
给你一个数组 candies 和一个整数 extraCandies ，其中 candies[i] 代表第 i 个孩子拥有的糖果数目。
对每一个孩子，检查是否存在一种方案，将额外的 extraCandies 个糖果分配给孩子们之后，此孩子有 最多 的糖果。注意，允许有多个孩子同时拥有 最多 的糖果数目。

示例 1:
输入：candies = [2,3,5,1,3], extraCandies = 3
输出：[true,true,true,false,true] 
解释：
孩子 1 有 2 个糖果，如果他得到所有额外的糖果（3个），那么他总共有 5 个糖果，他将成为拥有最多糖果的孩子。
孩子 2 有 3 个糖果，如果他得到至少 2 个额外糖果，那么他将成为拥有最多糖果的孩子。
孩子 3 有 5 个糖果，他已经是拥有最多糖果的孩子。
孩子 4 有 1 个糖果，即使他得到所有额外的糖果，他也只有 4 个糖果，无法成为拥有糖果最多的孩子。
孩子 5 有 3 个糖果，如果他得到至少 2 个额外糖果，那么他将成为拥有最多糖果的孩子。

示例 2:
输入：candies = [4,2,1,1,2], extraCandies = 1
输出：[true,false,false,false,false] 
解释：只有 1 个额外糖果，所以不管额外糖果给谁，只有孩子 1 可以成为拥有糖果最多的孩子。

类型：贪心
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution 
{
    public:
        vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) 
        {
            int max_candies = 0;
            vector<bool> result;

            max_candies =  *max_element(candies.begin(), candies.end());

            for(int i = 0; i < candies.size(); i++)
                result.push_back(candies[i] +  extraCandies >= max_candies);
    
            return result;
        }
};

int main(void)
{
    Solution kid_solution;
    vector<int> candies;
    int extraCandies;
    int i = 0;
    int temp;
    char ch;
    vector<bool> result;
    
    while(1)
    {
        candies.clear();
        cout << "输入一个数组Candies(回车结束)：" << endl;
        while(1)
        {
            cin >> temp;
            candies.push_back(temp);
            cin.get(ch);
            if(ch == '\n')
            break;
        }

        cout << "candies:";
        for(int i = 0; i < candies.size(); i++)
            cout << candies[i] << " ";
        cout << endl;

        cout << "输入一个整数extraCandies：";
        cin >> extraCandies;
        cin.get(ch);

        cout << "extraCandies:"  << extraCandies << endl;
        result = kid_solution.kidsWithCandies(candies, extraCandies);
        cout << "结果为:" << endl;
        ios_base::fmtflags initial;         //用于保存初始格式
        initial = cout.setf(ios::boolalpha); //使cout在显式bool值时，显式true和false，而不是1和0
        cout << "[";
        for(i = 0; i < result.size() - 1; i++)
            cout << result[i] << ",";
        
        cout << result[i] << "]" << endl;
    }

    return 0;
}