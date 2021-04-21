#include <iostream>
#include <vector>

bool isLess(int a , int b)    // strictly less than 
{
    return a < b;
}

void exchange(int &a, int &b)
{
    int hold = a;
    a = b;
    b = hold;
}

void selectionSort(std::vector<int>& a)
{
    size_t len = a.size();

    for(int i=0; i < len; i++)
    {
        int min = i;
        for( int j = i; j < len; j++ )
        {
            if(isLess(a[j], a[min]))
                min = j; 
        }
        if(i != min)
            exchange(a[i], a[min]);
    }
}


int main()
{
    std::vector<int> arr={10,5,1,8,3,9,2,4};
    for(int& i : arr)
        std::cout<<i<<" ";
    std::cout<<"\n";

    selectionSort(arr);

    for(int& i : arr)
        std::cout<<i<<" ";
    std::cout<<"\n";


}
