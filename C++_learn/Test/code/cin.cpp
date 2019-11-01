#include <iostream>

using namespace std;
int main(void)
{
    char str1[20];
    char str2[20];
    char str3[20];
    //int num1;
    cout << R"(jim "King" Tutt uses "\n" instead of endl.)" << endl;

    //cout << "please input num1: ";
    //cin >> num1;
    cout << "please input str1: ";
    cin >> str1;
    cout << "please input str2: ";
    cin.getline(str2,10);
    cout << "please input str3: ";
    cin >> str3;
    

    //cout << "num1 is " << num1 << endl;
    cout << "str1 is " << str1 << endl;
    cout << "str2 is " << str2 << endl;
    cout << "str3 is " << str3 << endl;

    return 0;
}