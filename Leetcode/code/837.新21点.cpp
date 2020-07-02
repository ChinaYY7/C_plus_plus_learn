/*
爱丽丝参与一个大致基于纸牌游戏 “21点” 规则的游戏，描述如下：

爱丽丝以 0 分开始，并在她的得分少于 K 分时抽取数字。 抽取时，她从 [1, W] 的范围中随机获得一个整数作为分数进行累计，其中 W 是整数。 每次抽取都是独立的，其结果具有相同的概率。

当爱丽丝获得不少于 K 分时，她就停止抽取数字。 爱丽丝的分数不超过 N 的概率是多少？


示例 1:
输入：N = 10, K = 1, W = 10
输出：1.00000
说明：爱丽丝得到一张卡，然后停止。

示例 2:
输入：N = 6, K = 1, W = 10
输出：0.60000
说明：爱丽丝得到一张卡，然后停止。
在 W = 10 的 6 种可能下，她的得分不超过 N = 6 分。

示例 3：
输入：N = 21, K = 17, W = 10
输出：0.73278

类型：动态规划
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//错误解答
class Solution1 
{
    private:
        int m_N;
        int m_K;
        int m_W;

        double K_count = 0;
        double N_count = 0;

        void plus(uint64_t sum)
        {
            uint64_t temp = sum;
            for(int i = 1; i <= m_W; i++)
            {
                temp = sum + i;
                if(temp < m_K)
                {
                    plus(temp);
                }
                else
                {
                    K_count++;
                    if(temp <= m_N)
                        N_count++;
                }
            }
        }
    public:
        double new21Game(int N, int K, int W) 
        {
            m_N = N;
            m_K = K;
            m_W = W;
            plus(0);

            return N_count / K_count;
        }

        void clear_count()
        {
            K_count = 0;
            N_count = 0;
        }
};

//官方正解
class Solution2 {
public:
    double new21Game(int N, int K, int W) {
        if (K == 0) {
            return 1.0;
        }
        vector<double> dp(K + W + 1);
        for (int i = K; i <= N && i < K + W; i++) {
            dp[i] = 1.0;
        }
        dp[K - 1] = 1.0 * min(N - K + 1, W) / W;
        for (int i = K - 2; i >= 0; i--) {
            dp[i] = dp[i + 1] - (dp[i + W + 1] - dp[i + 1]) / W;
        }
        return dp[0];
    }
};

//理解后解答
class Solution3
{
    public:
        double new21Game(int N, int K, int W)
        {
            double dp[K+W];
            double sum = 0;
            int j = 0;
            for(int i = K; i < K + W; i++)
            {
                dp[i] = i <= N ? 1:0;
                sum += dp[i];
            }
            for(int i = K - 1; i >= 0; i--)
            {
                dp[i] = sum / W;
                sum = sum - dp[K+W-1-j] + dp[i];
                j++;
            }

            return dp[0];
        }
};

int main(void)
{
    int N, K, W;
    char ch;
    Solution1 recursion_solution1;
    Solution2 recursion_solution2;
    Solution3 recursion_solution3;
    double result = 0;
    
    while(1)
    {
        cout << "输入N：";
        cin >> N;
        cin.get(ch);

        cout << "输入K：";
        cin >> K;
        cin.get(ch);

        cout << "输入W：";
        cin >> W;
        cin.get(ch);

        cout << "N = " << N << ", K = " << K << ", W = " << W << endl;

        result = recursion_solution1.new21Game(N, K , W);

        cout << "solution1 Result: " << result << endl;
        recursion_solution1.clear_count();

        result = recursion_solution2.new21Game(N, K , W);
        cout << "solution2 Result: " << result << endl;

        result = recursion_solution3.new21Game(N, K , W);
        cout << "solution3 Result: " << result << endl;

    }

    return 0;
}