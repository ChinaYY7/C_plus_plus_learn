#ifndef _OBSERVER_H
#define _OBSERVER_H
#include <iostream>
#include <bitset>
#include "Observer_Pattern.h"
using namespace std;
//观察者实例，当添加新的观察者时，只需要再从Observer类继承一个对象并实现对应的方法就行
class BinaryOberver : public Observer
{
    private:
        int m_id;
    public:
        BinaryOberver(int id, Subject * subject) : m_id(id)
        {
            m_subject = subject;
            m_subject->attach(m_id, this);
        }
    
        virtual void update()
        {
            cout << "Binary String: " << bitset<32>(m_subject->get_state()) << endl;
        }
};

class OctalOberver : public Observer
{
    private:
        int m_id;
    public:
        OctalOberver(int id, Subject * subject) : m_id(id)
        {
            m_subject = subject;
            m_subject->attach(m_id, this);
        }
    
        virtual void update()
        {
            cout << "Octal String: " << oct << m_subject->get_state() << endl;
        }
};

class HexOberver : public Observer
{
    private:
        int m_id;
    public:
        HexOberver(int id, Subject * subject) : m_id(id)
        {
            m_subject = subject;
            m_subject->attach(m_id, this);
        }
    
        virtual void update()
        {
            cout << "Hex String: " << hex << m_subject->get_state() << endl;
        }
};
#endif