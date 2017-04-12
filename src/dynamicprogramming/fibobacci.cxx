#include <iostream>
#include <sstream>
#include <cstdio>
#include <string.h>

using namespace std;
typedef unsigned int uint_32;
uint_32 *table;
uint_32 fibonacci(uint_32 num )
{
    cout<<"\nfib call "<<num;
    if(num <= 0 )
        return 0;

    if(num <= 2)
    {
        table[num] = 1;
    }
    else
    {
        if( !table[num] )
            table[num]=fibonacci(num-1)+fibonacci(num-2);
    }
    return table[num];
} 

int main( int argc , char **argv )
{
    if( argc != 2 )
    {
        cout<<"Usage <fibonacci> <number>";
        return -1;
    }
    int num = 0;
    istringstream buf( argv[1] );
    buf >> num;
    cout<<"argument:"<<num<<endl;

    table = new uint_32[num+1];
    memset(table,0,sizeof(uint_32)*(num+1));

    cout<<"fib:"<<fibonacci(num)<<endl;
    cout<<"Series: ";
    for(int i=1;i<=num;++i)
        cout<<table[i]<<", ";

    delete []table;

}
