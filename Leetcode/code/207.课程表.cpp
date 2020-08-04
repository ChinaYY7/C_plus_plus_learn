/*
拓扑排序，深度优先搜索和广度优先搜索
题目：
你这个学期必须选修 numCourse 门课程，记为 0 到 numCourse-1 。
在选修某些课程之前需要一些先修课程。 例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示他们：[0,1]
给定课程总量以及它们的先决条件，请你判断是否可能完成所有课程的学习？
示例：
示例 1:
输入: 
2 1
1 0 
输出: true
解释: 总共有 2 门课程。学习课程 1 之前，你需要完成课程 0。所以这是可能的。

示例 2:
输入: 
2 2
1 0
0 1
输出: false
解释: 总共有 2 门课程。学习课程 1 之前，你需要先完成​课程 0；并且学习课程 0 之前，你还应先完成课程 1。这是不可能的。
*/

#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

//拓扑排序，深度优先搜索
class Solution 
{
    private:
        const static int UNSEARCH = 0;
        const static int SEARCHING = 1;
        const static int FINISH = 2;
        vector<vector<int>> edges;
        vector<int> visited;
        bool vailed = true;

        void dfs(int element)
        {
            //标记结点为正在搜索
            visited[element] = SEARCHING;
            for(auto elment_temp : edges[element])
            {
                //搜索到正在搜索的点，说明出现环路，即不存在拓扑排序
                if(visited[elment_temp] == SEARCHING)
                {
                    vailed = false;
                    return;
                }

                //当前结点未搜索过，继续向下搜索
                if(visited[elment_temp] == UNSEARCH)
                    dfs(elment_temp);

                //当上一次dfs后出现了环路，直接返回，不用再进行判断了
                if(!vailed)
                    return;
            }

            //标记该点下的所有点已搜索完成（如果此时进行入栈的话，可以从栈中获得拓扑排序，栈顶为拓扑排序中第一个元素）
            visited[element] = FINISH;
        }
    public:
        bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
        {
            visited.clear();
            edges.clear();
            vailed = true;

            //设置vector的大小
            visited.resize(numCourses);
            edges.resize(numCourses);

            //构建邻接表
            for(auto edge : prerequisites)
                edges[edge[1]].push_back(edge[0]);

            for(int i = 0; i < numCourses; i++)
            {
                //未搜索过的结点，开始深度优先搜索
                if(visited[i] == UNSEARCH)
                    dfs(i);
            }

            return vailed;
        }
};

//拓扑排序，广度优先搜索
class Solution1 
{
    private:
        vector<vector<int>> edges;
        vector<int> indeg;
        int visited;

    public:
        bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
        {
            visited = 0;
            edges.clear();
            indeg.clear();
        
            //设置vector的大小
            edges.resize(numCourses);
            indeg.resize(numCourses);

            queue<int> deg_queue;

            //构建邻接表
            for(auto edge : prerequisites)
            {
                edges[edge[1]].push_back(edge[0]);

                //统计各个点的入度
                indeg[edge[0]]++;
            }   

            //将入度为0的点放入队列    
            for(int i = 0; i < numCourses; i++)
            {
                if(indeg[i] == 0)
                    deg_queue.push(i);
            }

            //从队列中依次出队元素，并减少出队元素所连接的点的度
            while(!deg_queue.empty())
            {
                int element = deg_queue.front();
                deg_queue.pop();
                visited++;
                for(auto edge : edges[element])
                {
                    if(--indeg[edge] == 0)
                        deg_queue.push(edge);
                }
            }

            //若存在拓扑排序，则所有元素都能入队
            return visited == numCourses;
        }
};

int main(void)
{
    int numcourse;
    int request;
    vector<vector<int>> prerequisites;
    Solution1 Solution1;

    while(1)
    {
        prerequisites.clear();
        cout << "输入：" << endl;
        cin >> numcourse >> request;
        for(int i = 0; i < request; i++)
        {
            int temp;
            vector<int> v_temp;

            cin >> temp;
            v_temp.push_back(temp);
            
            cin >> temp;
            v_temp.push_back(temp);

            prerequisites.push_back(v_temp);
        }

        cout << "输出：" << endl;
        cout << (Solution1.canFinish(numcourse, prerequisites) ? "true" : "false") << endl;
    }

    return 0;
}