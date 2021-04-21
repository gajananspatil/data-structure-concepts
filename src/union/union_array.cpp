#include <iostream>
#include <vector>

// 1. isConnected gives result in O(1) time
// 2. connect traverses complete array to make union of two sets . as id of one set gets changed to second set.
//     so gives O(n) as insert/union operation worst case
//
class QuickUnion {

std::vector<int> id;
public:
    
    QuickUnion(int n)
    {
        id.reserve(n);
        for(int i =0; i <n ; i++)
            id.push_back(i);
    }

    bool isConnected(int p, int q)
    {
        return (id[p] == id[q]);
    }

    
    void connect(int p , int q)
    {
        auto pid = id[p];
        auto qid = id[q];
        for(auto & v: id)
        {
            if(v == pid) 
                v = qid;
        }
    }
};

//  0    1 -  2    3    4  
//       |
//  5    6    7    8    9   
//

int main()
{

    QuickUnion qu(10);
    std::cout<<"isConnected(1,2): " <<std::boolalpha<<qu.isConnected(1,2)<<std::endl;
    std::cout<<"connect(1,2)"<<"\n";qu.connect(1,2);
    std::cout<<"isConnected(1,2): "<<std::boolalpha<<qu.isConnected(1,2)<<"\n";

    std::cout<<"isConnected(2,6): "<<std::boolalpha<<qu.isConnected(2,6)<<"\n";
    std::cout<<"connect(1,6)"<<"\n";qu.connect(1,6);
    std::cout<<"isConnected(2,6): "<<std::boolalpha<<qu.isConnected(2,6)<<"\n";
}
