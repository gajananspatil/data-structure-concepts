#include "linkedlist.hxx"
using namespace std;


List * createList( std::vector<int> &vec)
{
    List *list = new List();
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

        prev = curr;
    }
    return list;
}

List *reverseList( List *list )
{
    Node *curr = list->head;
    Node *prev = NULL;
    Node *temp = NULL;

    while(curr)
    {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }

    list->head = prev;
    return list;
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

    List *list = createList(vec);
    cout<<list;

    reverseList(list);
    cout<<"Reversed List: " << list;

    //delete list;
}
