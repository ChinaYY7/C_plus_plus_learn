#ifndef _STACKTP_H
#define _STACKTP_H
template <class Type>
class Stack
{
    private:
        enum {MAX = 10};
        Type items[MAX];
        int top;

    public:
        Stack() : top(0){}
        bool isempty() {return top == 0;}
        bool isfull(){return top == MAX;}

        bool push (const Type & item);
        bool pop(Type & item);
};

template <class Type>
bool Stack<Type>::push(const Type & item)
{
    if(top < MAX)
    {
        items[top++] = item;
        return true;
    }
    else
        return false;
}

template <class Type>
bool Stack<Type>::pop(Type & item)
{
    if(top > 0)
    {
        item = items[--top];
        return true;
    }
    else
        return false;
}


#endif