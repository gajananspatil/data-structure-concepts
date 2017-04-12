#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;
int cutRod(vector<int> &rodprice, size_t rodsize)
{
    if( rodsize == 0 )
    {
        return 0;
    }
    int val = -1;
    for( int i=1;i <= rodprice.size(); ++i )
    {
        if( rodsize >= i )
            val = std::max( val, rodprice[i-1] + cutRod(rodprice, rodsize - i ));
    }
    cerr<<" ->vector size:" << rodprice.size()<< " rod size:"<<rodsize;
    cerr<<" value :"<<val<<endl;
    return val;

}

int main(int argc,char **argv)
{
    if(argc != 2 )
    {
        cerr<<"invalid input"<<endl;
        cerr<<"rodcutting <rodsize> ";
        return 0;
    }
    int rodsize  = atoi(argv[1] );
    int arr[]= {1,5,8,9,10,17,17,20,24,30};

    vector<int> rodprice(arr, arr+sizeof(arr)/sizeof(int));

    cerr<<"vector size:" << rodprice.size()<<endl;
    cerr<<"arraysize "<<sizeof(arr)/sizeof(int)<<endl;

    int optimalprofit = cutRod(rodprice,rodsize); 

    cout<<"optimal profit for size"<<rodsize<<"  :"<<optimalprofit<<endl;

}
