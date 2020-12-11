#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    long int num;
    cin >> num;
    while(num != 1)
    {
        for(int i = 2; i <= num; i++)
        {
            if(num % i == 0)
            {
                cout << i << " ";
                num /= i;
                break;
            }
        }
    }
    
    return 0;
}