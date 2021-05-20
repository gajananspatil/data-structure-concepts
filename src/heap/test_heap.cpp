#include <iostream>
#include "heap.h"


int main()
{

    std::vector<int> arr = {10, 2, 4, 9, 7, 19, 5, 11, 6};
    gpds::heap<int> heap ;


    std::cout<<"Raw data: ";
    for (auto & ele: arr)
        std::cout<<ele<<" ";
    std::cout<<"\n";
    
    for (auto & ele: arr)
        heap.push(ele);

    std::cout<<"\n pop all : \n\n";
    
     while(heap.size() > 0 )
     {
        std::cout<<heap.peek() <<" ";
        heap.pop();
     }
     

}
