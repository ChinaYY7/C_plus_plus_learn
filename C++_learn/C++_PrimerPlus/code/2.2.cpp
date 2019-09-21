#include <iostream>

using namespace std;
int main(void)
{
    long distance_o, distance_d;

    cout << "Input distance: ";
    cin >> distance_o;

    distance_d = distance_o * 220;

    cout << "Result distance: " << distance_d << " 码" << endl;

    return 0;
}