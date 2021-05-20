#ifndef __STACK_HEADER__
#define __STACK_HEADER__
#include <vector>

template <typename TYPE>
class Stack
{
    std::vector<TYPE> s;
    std::vector<TYPE> minS;

public:
    Stack() {}

    ~Stack()  {}

    void push (TYPE data)
    {
        s.push_back(data);

        if(minS.empty() )
        {
            minS.push_back(data);
        }
        else if(*minS.rbegin() > data)
        {
            minS.push_back(data);
        }
        else /* replicate current top */
        {
            minS.push_back(*minS.rbegin());
        }
    }

    void pop ()
    {

        if(s.size() == 0)
        {
            //std::cout<<"Empty Stack!";
            return ;

        }
        s.pop_back();
        minS.pop_back();
    }

    TYPE top ()
    {
        return s.back();
    }

    TYPE min()
    {
        return minS.back();
    }

    bool empty()
    {
        if(s.size() <= 0)
            return true;

        return false;
    }
};

#endif
