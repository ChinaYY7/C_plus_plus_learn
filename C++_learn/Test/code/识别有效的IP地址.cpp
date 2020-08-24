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

    return true;
}

bool is_mask(int *num)
{
    bool one_stat = true;
    const int mask[8] = {0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01};
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            if(!(num[i] & mask[j]))
            {
                if(one_stat)
                    one_stat = false;
            }
            else
            {
                if(!one_stat)
                    return false;
            }
        }
    }

    return true;
}

bool is_ip(int *num, int & ip_class, bool & private_ip)
{
    private_ip = false;
    if(num[0] < 256 && num[1] < 256 && num[2] < 256 && num[3] < 256)
    {
        if(num[0] == 0 || num[0] == 127)
            ip_class = 0;
        else if(num[0] > 0 && num[0] < 127)
        {
            ip_class = 1;
            if(num[0] == 10)
                private_ip = true;
        }
        else if(num[0] > 127 && num[0] < 192)
        {
            ip_class = 2;
            if(num[0] == 172 && num[1] > 15 && num[1] < 32)
                private_ip = true;
        }
        else if(num[0] > 191 && num[0] < 224)
        {
            ip_class = 3;
            if(num[0] == 192 && num[1] == 168)
                private_ip = true;
        }
        else if(num[0] > 223 && num[0] < 240)
            ip_class = 4;
        else
            ip_class = 5;
    }
    else
        return false;
    
    return true;
}

int main()
{
    string str;
    int A = 0;
    int B = 0;
    int C = 0;
    int D = 0;
    int E = 0;
    int Error = 0;
    int private_i = 0;

    while(cin >> str)
    {
        string str1, str2;
        if(split_string(str, str1, str2))
        {
            int num[2][4];
            if(split_num(str2, num[1]))
            {
                if(is_mask(num[1]))
                {
                    if(split_num(str1, num[0]))
                    {
                        int ip_class = 0;
                        bool private_ip = false;
                        if(is_ip(num[0], ip_class, private_ip))
                        {
                            switch (ip_class)
                            {
                                case 1:
                                    A++;
                                    break;
                                case 2:
                                    B++;
                                    break;
                                case 3:
                                    C++;
                                    break;
                                case 4:
                                    D++;
                                    break;
                                case 5:
                                    E++;
                                    break;
                                default:
                                    break;
                            }
                            if(private_ip)
                                private_i++;
                        }
                        else
                            Error++;
                    }
                    else
                        Error++;
                }
                else
                    Error++;
            }
            else
                Error++;
        }
    }

    cout << A << " " << B << " " << C << " " << D << " " << E << " " << Error << " " << private_i << endl; 

    return 0;
}