#include <iostream>
#include <map>
using namespace std;

int main()
{
    int n;
    cin >> n;
    map<int, int> data;
    for(int i = 0; i < n; i++)
    {
        int num1;
        int num2;
        cin >> num1;
        cin >> num2;
        pair<map<int, int>::iterator, bool> Insert_Pair = data.insert(pair<int, int> (num1, num2));
        if(!Insert_Pair.second)
            Insert_Pair.first->second += num2;        
    }
    
    for(pair<int, int> temp : data)
        cout << temp.first << " " << temp.second << endl;
    
    return 0;
}