#ifndef _OBSERVER_PATTERN_H
#define _OBSERVER_PATTERN_H
#include <list>
#include <unordered_map>
using namespace std;
class Observer;

//管理观察同一对象的所有观察者
class Subject
{
    private:
        unordered_map<int, Observer *> m_Observers;
        int m_state;
    
    public:
        int get_state()
        {
            return m_state;
        }
        
        void set_state(int state)
        {
            m_state = state;
            notifyAllObservers();
        }

        void attach(int id, Observer * observer);

        void dettach(int id)
        {
            m_Observers.erase(id);
        }

        void notifyAllObservers();
};

//观察者
class Observer
{
    protected:
        Subject * m_subject;  //用于将观察者自身注册到对应的被观察对象
    public:
        virtual void update() = 0;  //通知观察者
};

void Subject::notifyAllObservers()
{
    for(auto temp : m_Observers)
        temp.second->update();
}

void Subject::attach(int id, Observer *observer)
{
    m_Observers[id] = observer;
}
#endif