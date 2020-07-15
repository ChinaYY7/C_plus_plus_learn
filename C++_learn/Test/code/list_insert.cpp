#include <iostream>
#include <list>

int main(void)
{
    std::list<int> mylist;
    std::list<int>::iterator it;

    // set some initial values:
    for (int i=1; i<=5; ++i) mylist.push_back(i); // 1 2 3 4 5

    it = mylist.end();

    //it始终指向it原本指向的元素，所以插入后it还是指向end
    //it1指向最新插入的元素，因此不等于end
    std::list<int>::iterator it1 =  mylist.insert (it,10);

    if(it == mylist.end())
    {
        std::cout << "it == mylist.end()  " << *it << std::endl;
    }

    if(it1 == mylist.end())
    {
        std::cout << "it1 == mylist.end()" << std::endl;
    }
    else
    {
        std::cout << "it1 = " << *it1 << std::endl;
    }
    

    std::cout << "mylist contains:";
    for (it=mylist.begin(); it!=mylist.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';         
}