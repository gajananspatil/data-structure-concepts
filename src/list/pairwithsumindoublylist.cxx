#include "doublylinkedlist.hxx"

using namespace std;

DList * createDoublyList( std::vector<int> &vec)
{
    DList *list = new DList();
    list->size = vec.size(); 
    Node *curr = NULL;
    Node *prev = NULL;
    for( int i=0; i < vec.size(); i++)
    {
        curr = new Node(vec[i]);
        if( i == 0) 
            list->head = curr;

        if(prev)
            prev->next = curr;
        curr->prev = prev;

        prev = curr;
    }
    return list;
}


// This function assums that the list is sorted
void findPairWithGivenSum( DList *list , int sum )
{
    Node *forward = list->head;
    Node *reverse = list->head;
    Node *itr = reverse;
    // Traverse usin reverse to the end of list 
    while(reverse->next)
        reverse = reverse->next;

    bool found = false;
    int val = 0;
    while( reverse  && forward  && reverse != forward && forward->prev != reverse )
    {
        val = forward->data + reverse->data;

        if( val == sum )
        {
            cout<<"Pair-"<<forward->data<<","<<reverse->data<<endl;
             forward = forward->next;
             reverse = reverse->prev;
        }
        else if( val < sum )
            forward = forward->next;
        else
            reverse = reverse->prev;
    }

}


int main()
{
    vector<int> vec;
    for(int i=1;i<=21;i++)
    {
        vec.push_back(i);
        cout<<vec[i]<<",";
    }
    cout<<endl;

    DList *list = createDoublyList(vec);
    cout<<list;

    findPairWithGivenSum(list,25);

    //delete list;
}
