#include <iostream>
int main()
{
    using namespace std;    //make definitions visible
    cout << "\aOperation \"HyperHype\" is now activated!\n";
    cout << "Enter your agent code:_______\b\b\b\b\b\b\b";
    long code;

    cin >> code;

    cout << "\aYou entered " << code << "....\n";

    cout << "please input code2\n";

    long code2;
    cin >> code2;

    cout << "code2 is " << code2 << endl;

    return 0;
}