#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;
/*
输入：
100
5
77 92 
22 22
29 36
50 46
99 70
输出：
114


输入：
200
8
79 83
58 81
86 54
110 150
62 52
45 48
68 62
30 22
输出：
253
*/
int solution(long int T, vector<int> p, vector<int> w)
{

    //vector<vector<int>> dp = vector<vector<int>>(p.size() + 1, vector<int>(T + 1,0));
    vector<vector<int>> dp(p.size() + 1, vector<int>(T + 1,0));
    for(int i = 1; i <= p.size(); i++)
    {
        for(int j = 1; j <= T; j++)
        {
            if(j >= p[i-1])
                dp[i][j] = max(dp[i-1][j-p[i-1]] + w[i-1], dp[i-1][j]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    return dp[p.size()][T];
}
int main(void)
{
    long int T;
    int n;
    vector<int> p;
    vector<int> w;
    while(1)
    {
        p.clear();
        w.clear();
        cin >> T >> n;

        for(int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            p.push_back(temp);
            cin >> temp;
            w.push_back(temp);
        }

        cout << solution(T, p, w) << endl;
    }
}