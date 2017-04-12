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

Node* alternatereverse(Node *head, int reversalcount)
{
    Node *curr = head;
    Node *prev = NULL;
    Node *temp = NULL;  
    int count = 0;

    if(!head || !head->next)
        return head;

    while(curr && count < reversalcount)
    {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
        count++;
    }

    // After reversal of k nodes, 
    // current head should point to next list to be processed
    head->next = curr;
    head = prev;

    count = 0;
    while(curr && count < reversalcount)
    {
        prev = curr;
        curr = curr->next;
        count++;
    }

    prev->next = alternatereverse(curr,reversalcount );
    return head;
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

    List *origlist = createList(vec);
    origlist->head = alternatereverse(origlist->head,4);
    cout<<"Reversed KNodes List: " << origlist;
    //delete list;
}
