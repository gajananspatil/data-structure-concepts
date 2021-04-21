#include <iostream>
#include <vector>

//  To get a better efficiency of CONNECT operation we can try maintaining tree over plain array.
//  So union operation happens by just changing one entry. i.e just change root of one tree merges two connected components. 
//   0  1    2      3       
//   |     /   \   / \
//   5    6    7  8   9
//      /
//      4
//
// i      0  1  2  3  4  5  6  7  8  9
// id[]   0  1  2  3  6  0  2  2  3  3

// cons: this can create skewed tree as we don't know size of mergin tree and keep on adding one side only
class QuickUnion
{
    std::vector<int> id;
public:
    
    QuickUnion(int n)
    {
        id.reserve(n);
        for(int i=0;i <n; i++)
            id.push_back(i);
    }


    bool isConnected(int p, int q)
    {
        return root(p) == root(q);        
    }

    void connect(int p , int q)
    {
        auto pRoot = root(p);
        auto qRoot = root(q);
        if( p == q)      // already connected components
            return ;

        id[pRoot] = qRoot;
    }



private:

    int root(int p)
    {
        while(id[p] != p)
            p = id[p];
        return p;
    }
};

//  0    1 -  2    3  - 4  
//       |         |
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

    std::cout<<"isConnected(4,3): " <<std::boolalpha<<qu.isConnected(4,3)<<std::endl;
    std::cout<<"connect(3,4)"<<"\n";qu.connect(3,4);
    std::cout<<"isConnected(4,3): "<<std::boolalpha<<qu.isConnected(4,3)<<"\n";

    std::cout<<"isConnected(8,3): "<<std::boolalpha<<qu.isConnected(8,3)<<"\n";
    std::cout<<"connect(8,3)"<<"\n";qu.connect(8,3);
    std::cout<<"isConnected(8,3): "<<std::boolalpha<<qu.isConnected(8,3)<<"\n";
}
