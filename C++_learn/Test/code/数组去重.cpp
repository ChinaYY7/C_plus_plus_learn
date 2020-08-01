#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void No_dup(vector<int> & num)
{
    for(int i = 0; i < num.size(); i++)
    {
        for(int j = i+1; j < num.size(); j++)
        {
            if(num[i] == num[j])
            {
                while(1)
                {
                    if(num.size()-1 != num[i])
                    {
                        if(j <= num.size())
                        {
                            num[j] = num[num.size()-1]; 
                            num.erase(num.end() - 1);
                            break;
                        }
                    }
                    num.erase(num.end() - 1);
                }
                
            }
        }
    }
}

int fast_sort_in(vector<int> & nums, int start, int end)
{
    int small = start - 1;
    for(int i = start; i < end; i++)
    {
        if(nums[i] < nums[end])
        {
            small++;
            if(small != i)
            {
                swap(nums[i], nums[small]);
            }
        }
    }

    small++;
    swap(nums[small], nums[end]);
    return small;
}

void fast_sort(vector<int> & nums, int start, int end)
{
    if(start == end)
        return;
    int mid = fast_sort_in(nums, start, end);
    if(mid > start && mid < end)
    {
        fast_sort(nums, mid+1, end);
        fast_sort(nums, start , mid - 1);
    }
    else if(mid > start)
        fast_sort(nums, start, mid-1);
    else
        fast_sort(nums, mid+1, end);
}

void Remove_dup(vector<int> &nums)
{
    for(int i = nums.size() - 1; i > 0; i--)
    {
        if(nums[i] == nums[i-1])
            nums.erase(nums.begin()+i);
    }
}

void fast_sort(vector<int> & nums)
{
    fast_sort(nums, 0, nums.size() - 1);
}
int main()
{
    int num = 0;
    vector<int> nums;
    while(1)
    {
        cout << "输入数组大小：";
        cin >> num;
        nums.clear();
        cout << "输入" << num << "个整数:" << endl;
        for(int i = 0; i < num; i++)
        {
            int temp;
            cin >> temp;
            nums.push_back(temp);
        }

        fast_sort(nums);
        cout << "排序结果为：" << endl;
        for(int temp : nums)
            cout << temp << " ";
        cout << endl;

        Remove_dup(nums);
        cout << "去重结果为：" << endl;
        for(int temp : nums)
            cout << temp << " ";
        
        cout << endl;
    }

    return 0;
}