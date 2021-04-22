#ifndef __INCLUDE_QUEUE_STACK__
#define __INCLUDE_QUEUE_STACK__

#include <queue>



template <typename TYPE>
class Stack
{
    std::queue<TYPE> pushQ;
    std::queue<TYPE> popQ;
public:
    Stack() {}
    ~Stack() {}

    void push(TYPE& d)
    {
        pushQ.push(d); 
    }

    void pop()
    {
        if(pushQ.size() != 0)
            copyFromPushQ();

        popQ.pop();

    }

    TYPE& top()
    {
        if(pushQ.size() !=0)
            copyFromPushQ();

        return popQ.front();
    }

private:
    void copyFromPushQ()
    {
        std::vector<TYPE> temp;
        while(!pushQ.empty())
        {
            temp.push_back(pushQ.front());
            pushQ.pop();
        }

        std::vector<TYPE> temp2;
        while(!popQ.empty())
        {
            temp2.push_back(popQ.front());
            popQ.pop();
        }
        for(auto i = temp.rbegin(); i != temp.rend(); ++i)
            popQ.push(*i);
        for(auto i = temp2.begin(); i!= temp2.end(); ++i)
            popQ.push(*i);
    }
};
#endif
