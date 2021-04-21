#include <iostream>
#include <vector>

bool isLess(int a, int b)
{
    return a < b;
}


void exchange(int &a, int &b)
{
    int hold = a;
    a = b;
    b = hold;
}

//All the element to the left of index are seen and in ascending order.
//Right side elements are unseen. Keep inserting unseen element to left at its correct position
void insertionSort(std::vector<int> &a)     
{
    size_t len = a.size();

    for(int i =0; i < len; i++)
    {
        int min = i;        
        for(int j = i; j >= 0; j--)
        {
            if(isLess(a[min], a[j]))
            {
                exchange( a[min], a[j] );
                min = j;
            }
        }
        
    }

}

int main()
{
    std::vector<int> arr={10,5,1,8,3,9,2,4};
    for(int& i : arr)
        std::cout<<i<<" ";
    std::cout<<"\n";

    insertionSort(arr);

    for(int& i : arr)
        std::cout<<i<<" ";
    std::cout<<"\n";


}
