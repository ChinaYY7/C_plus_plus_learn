#include "Memento.h"
#include <iostream>

using namespace std;

int main(void)
{
    Originator originator;
    CareTaker careTaker;

    originator.setState("State #1");
    originator.setState("State #2");
    careTaker.add("0", originator.saveStateToMemento());
    originator.setState("State #3");
    careTaker.add("1", originator.saveStateToMemento());
    originator.setState("State #4");

    cout << "Current State: " << originator.getState() << endl;
    originator.getStateFromMemento(careTaker.get("0"));
    cout << "First saved State: " << originator.getState() << endl;
    originator.getStateFromMemento(careTaker.get("1"));
    cout << "Second saved State: " << originator.getState() << endl;

    return 0;
}