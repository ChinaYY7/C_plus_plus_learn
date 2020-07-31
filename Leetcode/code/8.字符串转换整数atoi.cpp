#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <limits.h>

using namespace std;

//状态机解法
class Solution1 {
    int check_char(char c)
    {
        if(c == ' ')
            return 0;
        if(c == '+' || c == '-')
            return 1;
        if(c >= '0' && c <= '9')
            return 2;
        return 3;
    }
public:
    int myAtoi(string str) {
        unordered_map<string, vector<string>> state_map = {
            {"start", {"start", "signed", "numeric", "end"}},
            {"signed", {"end", "end", "numeric", "end"}},
            {"numeric", {"end", "end", "numeric", "end"}},
            {"end", {"end", "end", "end", "end"}},
        };

        string state = "start";
        bool signe = false;
        long int result = 0;
        
        for(char c : str)
        {
            state = state_map[state][check_char(c)];
            if(state == "signed")
            {
                if(c == '-')
                    signe = true;
            } 
            else if(state == "end")
                return signe ? 0 - result : result;
            else if(state == "numeric")
            {
                result = result * 10 + (c -  '0');
                if(signe)
                {
                    if(0 - result < INT_MIN)
                        return INT_MIN;
                }
                else
                {
                    if(result > INT_MAX)
                        return INT_MAX;
                }
            }
        }
    
        return signe ? 0 - result : result;
    }
};

//老式解法
class Solution2 
{
    private:
        bool is_numeric(char c)
        {
            return c >= '0' && c <= '9';
        }
        int clear_space(string & str)
        {
            int start = 0;
            int positive = 1;
            bool flag = false;
            for(int i = 0; i < str.size(); i++)
            {
                if(str[i] == '-')
                {
                    if(!flag)
                    {
                        flag = true;
                        positive = -1;
                        if(is_numeric(str[i+1]) == false)
                            return 0;
                    }
                    else
                        return 0;
                }   
                else if(str[i] == '+')
                {
                    if(!flag)
                    {
                        positive = 1;
                        flag = true;
                        if(is_numeric(str[i+1]) == false)
                            return 0;
                    } 
                    else
                        return 0;
                }
                else
                {
                    if(is_numeric(str[i]))
                        break;
                    else if(str[i] != ' ')
                        return 0;
                }

                start++;
            }
            str = str.substr(start);
            return positive;
        }
public:
    int myAtoi(string str) {
        int positive = clear_space(str);
        if(positive == 0)
            return 0;
        
        long int result = 0;
        for(char c : str)
        {
            if(is_numeric(c))
            {
                result *= 10;
                result += (c - '0');
                if(positive == 1)
                {
                    if(result > INT_MAX)
                        return INT_MAX;
                }
                else if(positive == -1)
                {
                    if(0 - result < INT_MIN)
                        return INT_MIN;
                }
            }
            else
                break;   
        }

        return positive == 1 ? result : 0 - result;
    }
};


int main(void)
{
    string input;
    Solution1 solution1;

    while(1)
    {
        cout << "输入字符串:";
        getline(cin, input);
        int number = solution1.myAtoi(input);
        cout << "结果为：" << number << endl;
    }

    return 0;
}