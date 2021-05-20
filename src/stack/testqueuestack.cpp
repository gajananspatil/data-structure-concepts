#include "stackusingqueue.h"
#include <iostream>

void test1()
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

    std::cout<<s.top()<<","<< std::endl;
    s.pop();
    std::cout<<s.top()<<","<< std::endl;
    s.pop();
    std::cout<<s.top()<<","<< std::endl;
    s.pop();
    std::cout<<s.top()<<","<< std::endl;
    s.pop();
    std::cout<<s.top()<<","<< std::endl;
    s.pop();
    std::cout<<s.top()<<","<< std::endl;
    s.pop();
    std::cout<<s.top()<<","<< std::endl;
    s.pop();
    std::cout<<s.top()<<","<< std::endl;
    s.pop();
    std::cout<<s.top()<<","<< std::endl;
}
void test2()
{
    Stack<int> s;
    int a=1;
    s.push(a); //1
    a=2;
    s.push(a);
    std::cout<<"Top:"<<s.top()<<"\n";
    a=3;
    s.push(a);
    std::cout<<"Top:"<<s.top()<<"\n";
}
int main()
{
    //test1();
    test2();
}
