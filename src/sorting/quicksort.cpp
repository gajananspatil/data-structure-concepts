#include <random>
#include <iostream>
#include <vector>
#include <algorithm>

void exchange(int &a , int &b)
{
    int temp = a;
    a = b;
    b = temp;

}

bool isLess(int a, int b)
{
    return a < b;
}

void print(std::vector<int> arr)
{
    for(auto &i: arr)
        std::cout<<i<<" ";
    std::cout<<"\n";
}
namespace sorting
{
    //Partition element such that, all the elements to the left of selected number are less 
    // and to the right of it are great or equal
    int hoarePartition(std::vector<int>& arr, int low, int high)
    {
        int left = low;
        int right = high;
        int pivot = arr[left + (right - left)/2];
        while(left < right)
        {
            while( isLess( arr[left], pivot ) )
            {
                left++;
            }

            while (isLess(pivot, arr[right] ) )
            {
                right--;
            }

            if( left < right )
            {
                //DBGprint(arr);
                //DBGstd::cout<<"Exchange Index: "<<left<<" <--> : "<< right<<"\n";
                exchange(arr[left], arr[right] );
            }
        }

        exchange(pivot, arr[right] );

        return right;
    }



    void quicksort(std::vector<int>& arr, int low, int high, int level)
    {
        for(auto i=0; i < level;++i )
            std::cout<<"\t";
        //DBGstd::cout<<"QuickSort: low -> "<<low<<", high -> "<< high<<"\n";
        if(high <= low)
            return;

        int partition = hoarePartition(arr, low, high);
        quicksort(arr, low, partition -1,++level);
        quicksort(arr, partition+1, high, level);
    }

    void quicksort(std::vector<int> & arr)
    {
        size_t len = arr.size() -1;

        if(len > 1)
        {
            std::random_device rd;
            std::mt19937 g(rd());
            std::shuffle(arr.begin(), arr.end(), g);
            quicksort(arr, 0, len, 0);
        }
    }
}


int main()
{

    std::vector<int> arr={10,5,1,8,3,9,2,4,15,35,11,23,45,99,6};
    for(int& i : arr)
        std::cout<<i<<" ";
    std::cout<<"\n";

    sorting::quicksort(arr);

    for(int& i : arr)
        std::cout<<i<<" ";
    std::cout<<"\n";

}
