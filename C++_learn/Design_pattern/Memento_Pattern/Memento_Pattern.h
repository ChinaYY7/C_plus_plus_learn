#ifndef _MEMENTO_PATTERN_H
#define _MEMENTO_PATTERN_H
#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

//备忘录类
class Memento
{
    private:
        string m_state;
    
    public:
        Memento(string state) : m_state(state){}

        string getState() const
        {
            return m_state;
        }
};

//备忘录的管理类
class CareTaker
{
    private:
        unordered_map<string, Memento *> memento_map;

    public:
        void add(const string & key, Memento * state)
        {
            memento_map[key] = state;
        }

        void remove(const string & key)
        {
            delete memento_map[key];
            memento_map.erase(key);
        }

        Memento * get(const string & key)
        {
            return memento_map[key];
        }

        ~CareTaker()
        {
            for(pair<string, Memento *> temp : memento_map)
                delete temp.second;
            cout << "relese all Memento" << endl;
        }
};

#endif