#include <iostream>
#include <string>
#include <cstring>  //C-style string library
int main()
{
    using namespace std;    //make definitions visible
    const int size = 20;
    char charr1[size];
    char charr2[size] = {"jaguar"};

    string str1;
    string str2{"panther"};

    str1 = str2;
    strcpy(charr1, charr2);

    str1 += " paste";
    strcat(charr1, " juice");

    int len1 = str1.size();
    int len2 = strlen(charr1);

    cout << "The st""ring " << str1 << " contains " 
            << len1 << " characters. \n";
    cout << "The string " << charr1 << " contains "
            << len2 << " characters. \n";

    string str3;
    char str3_temp[100];
    cout << "input str3\n";
    cin.getline(str3_temp,100);
    str3 = str3_temp;
    cout << "str3 is " << str3 << endl;

    string str4;
    cout << "input str4\n";
    getline(cin,str4);
    cout << "str4 is " << str4 << endl;

    cout << R"("RAW" string test is %s \n)" << endl;
    

    return 0;
}