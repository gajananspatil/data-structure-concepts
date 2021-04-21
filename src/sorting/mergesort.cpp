#include <iostream>
#include <vector>

namespace sorting
{
    bool less(int a, int b)
    {
        return a < b;
    }

    void merge(std::vector<int>& arr, std::vector<int>& auxarr, size_t low, size_t mid, size_t high)
    {
        //copy records to aux array
        for(int i = low; i <= high; ++i)
            auxarr[i] = arr[i];

        int i = low;
        int j = mid+1;

        for(int k = low; k <= high; ++k)
        {
            if(i > mid )                        arr[k] = auxarr[j++];

            else if (j > high )                 arr[k] = auxarr[i++];

            // compared a[j] < a[i] , so that element order is maintained in case equal. every time picked from left subarry
            else if (less( auxarr[j] , auxarr[i] ))  arr[k] = auxarr[j++];  

            else                                arr[k] = auxarr[i++]; 

        }
    }

    void mergesort(std::vector<int>& arr, std::vector<int>& auxarr, int low, int high)
    {
        if(high <= low) 
           return;

        size_t mid = low + (high - low)/2;
        mergesort (arr, auxarr, low, mid);
        mergesort(arr, auxarr, mid+1, high);
        merge(arr, auxarr, low, mid,  high); 
        
        std::cout<<"Array after merge from "<< low <<"->"<<high<<"\n";
        for(int i =low; i <= high ; i ++)
            std::cout<<arr[i]<<" ";
        std::cout<<"\n";

    }

    void mergesort(std::vector<int>& arr)
    {
        
       std::vector<int> auxarr(arr.size(), 0);

       mergesort(arr, auxarr, 0, arr.size()-1 );
        
    }

    void bottomupsort(std::vector<int>& arr)
    {
        
        int len = arr.size();
        std::vector<int> auxarr(arr.size(), 0);
        for(int bucket=1; bucket < len; bucket=bucket+bucket)
            for( int i =0; i < len-bucket; i+=bucket+bucket)
                merge(arr, auxarr,i, i+bucket-1, std::min(i+bucket+bucket-1, len-1));
    }

}


int main()
{

    std::vector<int> arr={10,5,1,8,3,9,2,4};
    std::vector<int> arr1={10,5,1,8,3,9,2,4};
    for(int& i : arr)
        std::cout<<i<<" ";
    std::cout<<"\n";

    sorting::mergesort(arr);

    for(int& i : arr)
        std::cout<<i<<" ";

    sorting::bottomupsort(arr1);
    std::cout<<"\nUsing bottomupsort\n";
    for(int& i : arr1)
        std::cout<<i<<" ";


}
