#ifndef _PROTOTYPE_PATTERN_H
#define _PROTOTYPE_PATTERN_H
#include <string>

using namespace std;

class Prototype
{
    public:
        virtual Prototype *clone() = 0;

        Prototype(){}
        virtual ~Prototype(){}
};

class Shape : public Prototype
{
    private:
        string m_id;
    
    protected:
        string m_type;
    
    public:
        virtual void draw() = 0;
        string getType()
        {
            return m_type;
        }

        void setId(string id)
        {
            m_id = id;
        } 

        string getId()
        {
            return m_id;
        }

        virtual Shape *clone(){}

        virtual ~Shape(){}
};

#endif

