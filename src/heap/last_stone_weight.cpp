#include "heap.h"
#include <iostream>

// 
// https://leetcode.com/problems/last-stone-weight/

class Solution {
public:
    int lastStoneWeight(std::vector<int>& stones) 
    {

        gpds::heap<int> heap;

        for( auto & ele: stones)
            heap.push(ele);


        while(heap.size() > 1)
        {
            auto stone1 = heap.peek();
            heap.pop();

            auto stone2 = heap.peek();
            heap.pop();

            if(stone1 == stone2 )
                continue;

            int diff = std::abs(stone1-stone2);
            heap.push(diff);
        }
        
        if(heap.size() > 0)
            return heap.peek();
        else 
            return 0;
    }
};


int main()
{
    Solution s ;
    //std::vector<int> arr = {2,7,4,1,8,1};
    std::vector<int> arr = {1,3};
    auto result = s.lastStoneWeight (arr);

    std::cout<<"result: "<<result<<"\n";
}
