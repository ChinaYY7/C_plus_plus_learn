#include <iostream>
#include "Observer.h"

using namespace std;

int main(void)
{
    Subject subject;

    BinaryOberver binaryOberver(0, &subject);
    OctalOberver octalOberver(1, &subject);
    HexOberver hexOberver(2, &subject);

    cout << "First state change: 15" << endl;
    subject.set_state(15);
    
    cout << "Second state change: 10" << endl;
    subject.set_state(10);
    
    return 0;
}