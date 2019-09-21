#include <iostream>
#include <string>
int main()
{
    using namespace std;

    int donuts = 6;
    double cups = 4.5;

    int *pt  = new int;

    *pt = 100;
    cout << "donuts is " << donuts << " and address is "
    << &donuts << endl;

    cout << "cups is " << cups << " and address is "
    << &cups << endl;

    cout << "new int is " << *pt << " and address is "
    << pt << endl;

    delete pt;

    double *p2 = new double[3];

    p2[0] = 0.2;
    p2[1] = 0.5;
    p2[2] = 0.8;

    cout << "p2[1] is " << p2[1] << endl;

    p2++;

    cout << "p2[0] is " << p2[0] << endl;

    p2--;

    delete [] p2;

    return 0;
}