/*
请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。路径可以从矩阵中的任意一格开始，每一步可以在矩阵中向左、右、上、下移动一格。如果一条路径经过了矩阵的某一格，那么该路径不能再次进入该格子。例如，在下面的3×4的矩阵中包含一条字符串“bfce”的路径（路径中的字母用加粗标出）。

[["a","b","c","e"],
["s","f","c","s"],
["a","d","e","e"]]

但矩阵中不包含字符串“abfb”的路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入这个格子。

示例 1:
输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
输出：true

示例 2:
输入：board = [["a","b"],["c","d"]], word = "abcd"
输出：false

类型：递归深度搜索DFS
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//解答1
class Solution 
{
    public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        vector<int> result;
        result.clear();
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return result;
        }
        int x = 0;
        int y = 0;
        bool exit_sta = false;
        int size =  matrix.size() * matrix[0].size();
    
        while(1)
        {
            if(result.size() >= size)
            {
                exit_sta = true;
                break;
            }
            for(; x < matrix[y].size(); x++)
            {
                if(result.size() >= size)
                {
                    exit_sta = true;
                    break;
                }
                result.push_back(matrix[y][x]);
            }

            if(exit_sta)
                break;

            x-=1;
            y+=1;
            for(; y < matrix.size(); y++)
            {
                if(result.size() >= size)
                {
                    exit_sta = true;
                    break;
                }
                result.push_back(matrix[y][x]);
            }

            if(exit_sta)
                break;

            y-=1;
            x-=1;
            for(; x >=0 ; x--)
            {
                if(result.size() >= size)
                {
                    exit_sta = true;
                    break;
                }
                result.push_back(matrix[y][x]);
            }

            if(exit_sta)
                break;
            y-=1;
            x+=1;
            for(; y >= 1; y--)
            {
                if(result.size() >= size)
                {
                    exit_sta = true;
                    break;
                }
                result.push_back(matrix[y][x]);
            }

            if(exit_sta)
                break;

            y+=1;
            x+=1;
        }
        
        return result;
    }
};


//leetcode运行报错，这里可以
class Solution2
{
    private:
        vector<int> spiralOrder_recursion(vector<vector<int>>& matrix, vector<int> & result)
        {
            if(matrix.empty())
                return result;

            vector<vector<int>>::iterator it;

            //读行
            it = matrix.begin();
            while(!it->empty())
            {
                result.push_back(*(it->begin()));
                it->erase(it->begin());
            }

            matrix.erase(it);
            if(matrix.empty())
                return result;

            //读列
            for(it = matrix.begin(); it != matrix.end(); ++it)
            {
                result.push_back(*(it->end()-1));
                it->erase(it->end()-1);
            }

            //读行
            it = matrix.end() - 1;
            while(!it->empty())
            {
                result.push_back(*(it->end()-1));
                it->erase(it->end()-1);
            }

            matrix.erase(it);
            if(matrix.empty())
                return result;

            //读列
            for(it = matrix.end()-1; it != matrix.begin(); --it)
            {
                result.push_back(*(it->begin()));
                it->erase(it->begin());
            }
            result.push_back(*(it->begin()));
            it->erase(it->begin());

            return spiralOrder_recursion(matrix, result);
        }
    public:
        vector<int> spiralOrder(vector<vector<int>>& matrix) 
        {
            vector<int>  result;
            return spiralOrder_recursion(matrix, result);
        }
};

//官方解答
class Solution3 {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return {};
        }

        int rows = matrix.size(), columns = matrix[0].size();
        vector<int> order;
        int left = 0, right = columns - 1, top = 0, bottom = rows - 1;
        while (left <= right && top <= bottom) {
            for (int column = left; column <= right; column++) {
                order.push_back(matrix[top][column]);
            }
            for (int row = top + 1; row <= bottom; row++) {
                order.push_back(matrix[row][right]);
            }
            if (left < right && top < bottom) {
                for (int column = right - 1; column > left; column--) {
                    order.push_back(matrix[bottom][column]);
                }
                for (int row = bottom; row > top; row--) {
                    order.push_back(matrix[row][left]);
                }
            }
            left++;
            right--;
            top++;
            bottom--;
        }
        return order;
    }
};

int main(void)
{
    Solution matrix_solution;
    vector<vector<int>> board;
    vector<int> row;
    vector<int> result;
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
        result.clear();

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
        result = matrix_solution.spiralOrder(board);
        for(int i = 0; i < result.size(); i++)
            cout << result[i] << " ";
        cout << endl;
    }

    return 0;
}