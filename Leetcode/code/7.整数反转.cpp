#include <iostream>
#include <limits.h>
using namespace std;
class Solution {
public:
    int reverse(int x) {
        int nums[10];
        int i = 0;
        int j = 0;
        while(x)
        {
            nums[i++] = x % 10;
            x /= 10;
        }

        long reverse_num = 0;
        while(j < i)
        {
            reverse_num = reverse_num * 10 + nums[j++];
        }

        if(abs(reverse_num) > INT_MAX)
            reverse_num = 0;
        else
        {
            if(x < 0)
                reverse_num = -reverse_num;
        } 
        return reverse_num;
    }
};

int main()
{
    int num;
    Solution Solution1;
    while(1)
    {
        cout << "输入整数:";
        cin >> num;
        int result = Solution1.reverse(num);
        cout << "结果为:" << result << endl;
    }
}