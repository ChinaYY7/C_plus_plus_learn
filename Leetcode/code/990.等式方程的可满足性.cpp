/*
给定一个由表示变量之间关系的字符串方程组成的数组，每个字符串方程 equations[i] 的长度为 4，并采用两种不同的形式之一："a==b" 或 "a!=b"。在这里，a 和 b 是小写字母（不一定不同），表示单字母变量名。

只有当可以将整数分配给变量名，以便满足所有给定的方程时才返回 true，否则返回 false。 

示例 1：

输入：["a==b","b!=a"]
输出：false
解释：如果我们指定，a = 1 且 b = 1，那么可以满足第一个方程，但无法满足第二个方程。没有办法分配变量同时满足这两个方程。


示例 2：

输出：["b==a","a==b"]
输入：true
解释：我们可以指定 a = 1 且 b = 1 以满足满足这两个方程。


示例 3：

输入：["a==b","b==c","a==c"]
输出：true


示例 4：

输入：["a==b","b!=c","c==a"]
输出：false


示例 5：

输入：["c==c","b==d","x!=z"]
输出：true

类型：并查集
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<array>
#include<map>
using namespace std;
class Solution 
{
    private:
        array<int, 26> roots;

        int find_root(char element)
        {
            int position = element - 'a';
            while(1)
            {
                if(roots[position] == -1)
                    return position;
                else
                    position = roots[position];
            }
        }

        //相当于一个聚类的过程，相等的全部集中到一颗树下
        void unionroots(char element1, char element2)
        {
            int root1 = find_root(element1);
            int root2 = find_root(element2);

            if(root1 != root2)
                roots[root2] = root1;
        }


    public:
        bool equationsPossible(vector<string>& equations) 
        {
            roots.fill(-1);
            for(int i = 0; i < equations.size(); i++)
            {
                if(equations[i][1] == '=')
                    unionroots(equations[i][0], equations[i][3]);
            }

            for(int i = 0; i < equations.size(); i++)
            {
                if(equations[i][1] == '!')
                {
                    if(find_root(equations[i][0]) == find_root(equations[i][3]))
                        return false;
                }
            }
            return true;
        }
};

class Solution1
{
    private:
        array<int, 26> roots;
        array<int, 26> root_level;

        int find_root(char element)
        {
            int position = element - 'a';
            while(1)
            {
                if(roots[position] == -1)
                    return position;
                else
                    position = roots[position];
            }
        }

        void unionroots(char element1, char element2)
        {
            int root1 = find_root(element1);
            int root2 = find_root(element2);

            if(root1 != root2)
            {
                if(root_level[root1] >= root_level[root2])
                {
                    roots[root2] = root1;
                    root_level[root1]++;
                }
                else if(root_level[root1] < root_level[root2])
                {
                    roots[root1] = root2;
                    root_level[root2]++;
                }
            }
        }


    public:
        bool equationsPossible(vector<string>& equations) 
        {
            roots.fill(-1);
            root_level.fill(0);
            for(int i = 0; i < equations.size(); i++)
            {
                if(equations[i][1] == '=')
                    unionroots(equations[i][0], equations[i][3]);
            }

            for(int i = 0; i < equations.size(); i++)
            {
                if(equations[i][1] == '!')
                {
                    if(find_root(equations[i][0]) == find_root(equations[i][3]))
                        return false;
                }
            }
            return true;
        }
};

int main(void)
{
    char ch;
    
    Solution1 equations_solution;
    vector<string> equations;
    string temp = {};

    bool result = false;
    
    while(1)
    {
        equations.clear();
        cout << "输入等式（回车结束）:" << endl;
        while(1)
        {
            cin.get(ch);
            if(ch == ' ' || ch == '\n')
            {
                if(temp.size() != 4)
                {
                    cout << "输入格式有误！"<<endl;
                    break;
                }
                equations.push_back(temp);
                temp.clear();
                if(ch == '\n')
                    break;
            }
            else
                temp = temp + ch; 
        }
        
        cout << "输入的字符串数组为：" << endl;
        for(int i = 0; i < equations.size(); i++)
            cout << equations[i] << endl;

        result = equations_solution.equationsPossible(equations);
        cout << "结果为：" << (result ? "true":"false") << endl;
    }

    return 0;
}