#include <iostream>
#include <vector>

//coursera union improvement
//  This is augmentation over pervious QuickUnion.
//  Here we will maintain size of each tree and while merging (union op^n) , alwasy put small tree under big tree
//  
//   0  1    2      3       
//   |     /   \   / \
//   5    6    7  8   9
//      /
//      4
//
// i      0  1  2  3  4  5  6  7  8  9
// id[]   0  1  2  3  6  0  2  2  3  3

// cons: this can create skewed tree as we don't know size of mergin tree and keep on adding one side only
class QuickUnionAug
{
    std::vector<int> id;
    std::vector<int> size;
    std::vector<int> max;
public:
    
    QuickUnionAug(int n):
    size(n,1)
    {
        id.reserve(n);
        
        for(int i=0;i <n; i++)
        {
            id.push_back(i);
            max.push_back(i);
        }
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

        if(size[p] > size[q])
        {
            id[pRoot] = qRoot;
            size[qRoot] += size[pRoot];
            max[qRoot] = std::max(max[pRoot],max[qRoot]);
        }
        else
        {
            id[qRoot] = pRoot;
            size[pRoot] += size[qRoot];
            max[pRoot] = std::max(max[pRoot],max[qRoot]);
        }

    }

    int find(int p)
    {
        auto r = root(p);
        return max[r];
    }

private:

    int root(int p)
    {
        while(id[p] != p)
        {
            // Path compression: Flatten tree by change parent of node to its grandparent.
            id[p] = id[id[p]];          
            p = id[p];
        }
        return p;
    }
};

//  0    1 -  2    3  - 4  
//       |         |
//  5    6    7    8    9   
//

int main()
{

    QuickUnionAug qu(10);
    std::cout<<"isConnected(1,2): " <<std::boolalpha<<qu.isConnected(1,2)<<std::endl;
    std::cout<<"connect(1,2)"<<"\n";qu.connect(1,2);
    std::cout<<"isConnected(1,2): "<<std::boolalpha<<qu.isConnected(1,2)<<"\n";
    std::cout<<"find(1)" <<qu.find(2)<<", "<<qu.find(1)<<"\n";
    
    std::cout<<"isConnected(2,6): "<<std::boolalpha<<qu.isConnected(2,6)<<"\n";
    std::cout<<"connect(1,6)"<<"\n";qu.connect(1,6);
    std::cout<<"isConnected(2,6): "<<std::boolalpha<<qu.isConnected(2,6)<<"\n";
    std::cout<<"find(2)" <<qu.find(2)<<", "<<qu.find(1)<<","<<qu.find(6)<<"\n";

    std::cout<<"isConnected(4,3): " <<std::boolalpha<<qu.isConnected(4,3)<<std::endl;
    std::cout<<"connect(3,4)"<<"\n";qu.connect(3,4);
    std::cout<<"isConnected(4,3): "<<std::boolalpha<<qu.isConnected(4,3)<<"\n";

    std::cout<<"isConnected(8,3): "<<std::boolalpha<<qu.isConnected(8,3)<<"\n";
    std::cout<<"connect(8,3)"<<"\n";qu.connect(8,3);
    std::cout<<"isConnected(8,3): "<<std::boolalpha<<qu.isConnected(8,3)<<"\n";

    qu.connect(7,3);
    std::cout<<"after connect 7,3, find(1)"<<qu.find(1)<<"\n";
}
