#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    string addStrings(string num1, string num2) {
        if(num1.size() < num2.size())
        {
            return addStrings(num2, num1);
        }
        int over = 0;
        string result;
        int j = num2.size() - 1;

        for(int i = num1.size() - 1; i >= 0; i--)
        {
            int sum = 0;
            if(j >= 0)
            {
                sum = num1[i] - '0' + num2[j] - '0' + over;
                j--;
            }
            else
                sum = num1[i] - '0' + over;

            over = 0;
                
            if(sum > 9)
            {
                over = 1;
                sum-=10;
            }
            num1[i] = sum + '0';
        }

        if(over)
            num1.insert(0, 1 ,'1');
        
        return num1;
    }
};

int main(void)
{
    string string1;
    string string2;

    Solution solution;

    getline(cin, string1);
    getline(cin, string2);

    cout << string1 << " " << string2 << endl;

    string result = solution.addStrings(string1, string2);
    cout << result << endl;

    return 0; 
}