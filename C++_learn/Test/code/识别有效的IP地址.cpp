#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

bool split_string(const string & orignal_str, string & str1, string & str2)
{
    char *temp;
    temp = strtok((char *)orignal_str.c_str(), "~");
    if(temp == NULL)
        return false;
    str1 = temp;

    temp = strtok(NULL, "~");
    if(temp == NULL)
        return false;

    str2 = temp;
    return true;
}

bool split_num(const string & orignal_str, int *num)
{
    char *temp;
    temp = strtok((char *)orignal_str.c_str(), ".");
    if(temp == NULL)
        return false;
    num[0] = atoi(temp);

    temp = strtok(NULL, ".");
    if(temp == NULL)
        return false;
    num[1] = atoi(temp);

    temp = strtok(NULL, ".");
    if(temp == NULL)
        return false;
    num[2] = atoi(temp);

    temp = strtok(NULL, ".");
    if(temp == NULL)
        return false;
    num[3] = atoi(temp);
}

bool is_mask(int *num)
{
    bool one_stat = true;
    const int mask[8] = {0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01};
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            if(!(num[i] && mask[j]))
                one_stat
        }
    }
}
int main()
{
    string str;
    int num[4];
    while(cin >> str)
    {
        split_num(str, num);
    }

    for(int i = 0; i < 4; i++)
        cout << num[i] << " ";
    
    cout << endl;

    return 0;
}