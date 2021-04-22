#include "stack.h"
#include <iostream>

int main()
{
    Stack<int> s;

    std::vector<int> arr = {11,15,20,5,6,2,3,9,10,1};

    for( int a : arr)
    {
        std::cout<<a <<" ";
        s.push(a);
    }
    std::cout<<std::endl;
    //s.push(5); s.push(6); s.push(2); s.push(3); s.push(9);

    std::cout<<s.top()<<","<< s.min()<<std::endl;
    s.pop();
    std::cout<<s.top()<<","<< s.min()<<std::endl;
    s.pop();
    std::cout<<s.top()<<","<< s.min()<<std::endl;
    s.pop();
    std::cout<<s.top()<<","<< s.min()<<std::endl;
    s.pop();
    std::cout<<s.top()<<","<< s.min()<<std::endl;
    s.pop();
    std::cout<<s.top()<<","<< s.min()<<std::endl;
    s.pop();
    std::cout<<s.top()<<","<< s.min()<<std::endl;
    s.pop();
    std::cout<<s.top()<<","<< s.min()<<std::endl;
    s.pop();
    std::cout<<s.top()<<","<< s.min()<<std::endl;
}
