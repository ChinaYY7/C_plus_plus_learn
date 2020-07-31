#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//递归解法
class Solution {
private:
    void minPathSum(vector<vector<int>>& grid, int x, int y, int min, int &minSum)
    {
        min+=grid[y][x];
    
        if(x == (grid[0].size() - 1) && y == (grid.size() - 1))
        {
            if(min < minSum || minSum < 0)
                minSum = min;
            return;
        }

        if(minSum > 0 && min > minSum)
            return;
            
        else if(x == (grid[0].size() - 1))
            minPathSum(grid, x, y+1, min, minSum);
        else if(y == (grid.size() - 1))
            minPathSum(grid, x+1, y, min, minSum);
        else 
        {
            minPathSum(grid, x, y+1, min, minSum);
            minPathSum(grid, x+1, y, min, minSum);
        }
    }

public:
    int minPathSum(vector<vector<int>>& grid) {
        int minSum = -1;
        minPathSum(grid, 0, 0, 0, minSum);
        return minSum;
    }
};

//动态规划
class Solution1 {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int minSum = -1;
        vector<vector<int>> dp = vector<vector<int>>(grid.size(), vector <int>(grid[0].size()));
        dp[0][0] = grid[0][0];
        int i = 0;
        int j = 0;
        for(i = 0; i < grid[0].size(); i++)
        {
            for(j = 0; j < grid.size(); j++)
            {
                if(j == 0 && i > 0)
                    dp[j][i] = dp[j][i -1] + grid[j][i];
                else if(i == 0 && j > 0)
                    dp[j][i] = dp[j-1][i] + grid[j][i];
                else if(i > 0 && j >0)
                    dp[j][i] = dp[j][i -1] > dp[j-1][i]? dp[j-1][i] + grid[j][i] : dp[j][i -1] + grid[j][i];
            }
        }
        return dp[j - 1][i - 1];
    }
};


int main(void)
{
    Solution minPathSum_solution;
    Solution1 minPathSum_solution1;
    vector<vector<int>> board;
    vector<int> row;
    int min;
    int temp;
    char ch;

    int row_num = 0;
    int column_num = 0;
    
    while(1)
    {
        cout << "输入矩阵大小（行x列）：";
        cin >> row_num;
        cin >> column_num;
        cin.get(ch);

        board.clear();

        cout << "输入一个矩阵(回车结束)：" << endl;

        for(int i = 0; i < row_num; i++)
        {
            row.clear();
            for(int j = 0; j < column_num; j++)
            {
                cin >> temp;
                row.push_back(temp);
            }
            board.push_back(row);
        }
        cin.get(ch);

        cout << "输入的矩阵为：" << endl;
        for(int i = 0; i < row_num; i++)
        {
            for(int j = 0; j < column_num; j++)
            {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }

        cout << "result:" << endl;
        min = minPathSum_solution1.minPathSum(board);
        
        cout << min << endl;
    }

    return 0;
}