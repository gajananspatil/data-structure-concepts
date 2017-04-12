/*
Problem Statement:
Harish went to a supermarket to buy exactly .k. kilograms apples for his .n. friends. The supermarket was really weird. The pricing of items was very different. He went to the Apples section and enquired about the prices. The salesman gave him a card in which he found that the prices of apples were not per kg. The apples were packed into covers, each containing .x. kg of apples, x > 0 and .x. is an integer. An .x. kg packet would be valued at .y. rupees. So, the placard contained a table with an entry .y. denoting the price of an .x. kg packet. If .y. is -1 it means that the corresponding packet is not available. Now as apples are available only in packets, he decides to buy atmost .n. packets for his .n. friends i.e he will not buy more than n packets of apples.

Harish likes his friends a lot and so he does not want to disappoint his friends. So now, he will tell you how many friends he has and you have to tell him the minimum amount of money he has to spend for his friends.
*/


#include <iostream>
#include <new>
#include <cstdlib>
#include <vector>
#include <limits>


const int imin = std::numeric_limits<int>::min(); // minimum value
const int imax = std::numeric_limits<int>::max();

using namespace std;
int *memo;
int buyApple(vector<int> &appleprice, size_t totalwieght)
{
    if( totalwieght == 0 )
    {
        return 0;
    }
    int val = imax;
    for( int i=1;i <= appleprice.size(); ++i )
    {
        if( totalwieght >= i )
        {
            if( memo[totalwieght] == imax )
            {
                val = std::min( val, appleprice[i-1] + buyApple(appleprice, totalwieght - i ));
                memo[totalwieght-1] = val;
               cerr<<"calculated: memo value : "<< memo[totalwieght] <<" total wt : "<<totalwieght<<endl;
            }
            val =   memo[totalwieght-1];
        }
    }
    cerr<<" ->vector size:" << appleprice.size()<< " total wt:"<<totalwieght;
    cerr<<" value :"<<val<<endl;
    return val;

}

int main(int argc,char **argv)
{
    if(argc != 2 )
    {
        cerr<<"invalid input"<<endl;
        cerr<<"buyapple <totalwieght> ";
        return 0;
    }
    int totalweight  = atoi(argv[1] );
    int arr[]= {1,5,8,9,10,17,17,20,24,30};

    vector<int> appleprice(arr, arr+sizeof(arr)/sizeof(int));

    cerr<<"vector size:" << appleprice.size()<<endl;
    cerr<<"arraysize "<<sizeof(arr)/sizeof(int)<<endl;
    memo = new int[totalweight + 1];
    for( int i=0; i <= totalweight; i++ )
        memo[i]=imax;

    if(!memo)
    {
        cerr<<"memory allocation for memo failed";
        return -1;
    }
    int optimalprofit = buyApple(appleprice,totalweight); 

    cout<<"optimal profit for size"<<totalweight<<"  :"<<optimalprofit<<endl;
    delete []memo;

}
