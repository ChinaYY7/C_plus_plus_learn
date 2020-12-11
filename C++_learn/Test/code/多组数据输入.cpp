#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main(void)
{
    vector<set<int>>rand_nums;
    int num = 0;

    //多组输入样例时候的做法，实际上就是输入一次计算一次并输出
    while(cin >> num)
    {   
        set<int> rand_num;
        for(int i = 0; i < num; i++)
        {
            int temp;
            cin >> temp;
            rand_num.insert(temp);
        }
        
        for(int num : rand_num)
            cout << num << endl;
        
    }
    
    return 0;
}