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
class Solution 
{
    private:
        bool dfs(vector<vector<char>>& board, int i, int j, string word, int k)
        {
            if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[k])
                return false;
            if(k == word.size() - 1)
                return true;
            //缓存一下，用于还原，否则影响再一次使用
            char temp = board[i][j];
            board[i][j] = '/';
            bool res = (dfs(board, i + 1, j, word, k + 1) || dfs(board, i - 1, j, word, k + 1) || dfs(board, i, j - 1, word, k + 1) || dfs(board, i, j + 1, word, k + 1));
            board[i][j] = temp;
            return res;
        }
    public:
        bool exist(vector<vector<char>>& board, string word) 
        {
            for(int i = 0; i < board.size(); i++)
            {
                for(int j = 0; j < board[i].size(); j++)
                {
                    if(dfs(board, i, j, word, 0))
                        return true;
                }
            }
            return false;
        }

};

int main(void)
{
    Solution dfs_solution;
    vector<vector<char>> board;
    vector<char> row;
    char temp;
    char ch;
    string word;

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

        cout << "输入一个字符串：";
        cin >> word;
        cout << "输入的字符串为：" << word << endl;

        bool res = dfs_solution.exist(board, word);
        ios_base::fmtflags initial;         //用于保存初始格式
        initial = cout.setf(ios::boolalpha); //使cout在显式bool值时，显式true和false，而不是1和0
        cout << "是否存在路径：" << res << endl;
    }

    return 0;
}