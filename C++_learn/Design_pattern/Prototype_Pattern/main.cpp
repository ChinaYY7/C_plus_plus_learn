#include <iostream>
#include "Prototype.h"
using namespace std;

int main(void)
{
    ShapeCache shapecache;
    shapecache.loadCache();

    Shape *clonedShape1 = shapecache.getShape("1");
    cout << "shape: " <<  clonedShape1->getType() << endl;
    
    Shape *clonedShape2 = shapecache.getShape("2");
    cout << "shape: " <<  clonedShape2->getType() << endl;

    Shape *clonedShape3 = shapecache.getShape("3");
    cout << "shape: " <<  clonedShape3->getType() << endl;

    return 0;
}