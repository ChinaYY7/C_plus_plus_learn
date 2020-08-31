#ifndef _MEMENTO_H
#define _MEMENTO_H
#include "Memento_Pattern.h"

using namespace std;

//包含备忘录模式的类
class Originator
{
    private:
        string m_state;
    
    public:
        string getState() const 
        {
            return m_state;
        }

        void setState(const string & state)
        {
            m_state = state;
        }

        Memento * saveStateToMemento()
        {
            return new Memento(m_state);
        }

        void getStateFromMemento(const Memento * memento)
        {
            m_state = memento->getState();
        }
};

#endif