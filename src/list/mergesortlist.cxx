#include "linkedlist.hxx"
#include <cstdlib>
#include <time.h>


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

/*
 * Receives start node.
 * Start fast and slow pointers, when fast reaches to end of list i.e. fast->next ==NULL, 
 * break the list and make slow->next == NULL
 */
void splitlist(Node *startnode,Node **list1, Node **list2)
{
    if( startnode == NULL || startnode->next == NULL)
    {
        *list1 = startnode;
        *list2 = NULL;
    }
    else
    {
        Node *slowptr = startnode;
        Node *fastptr = startnode->next;

        while ( fastptr )
        {
            fastptr = fastptr->next;
            if(fastptr)
            {
                fastptr = fastptr->next;
                slowptr = slowptr->next;
            }
        }

        *list1 = startnode;
        *list2 = slowptr->next;
        slowptr->next = NULL;
    }
    return;
}

Node* mergesortedlists(Node *list1, Node *list2)
{
    Node *result = NULL;
    if(!list1)
        return list2;
    else if(!list2)
        return list1;

    if(list1->data <= list2->data)
    {
        result = list1;
        result->next = mergesortedlists(list1->next,list2);

    }
    else
    {
        result = list2;
        result->next = mergesortedlists(list1,list2->next);
    }
    return result;

}
void mergesort( Node **list )
{
    Node *head = *list;
    Node *list1 = NULL;
    Node *list2 = NULL;

    if((head == NULL)||(head->next == NULL))
    {
        return;
    }

    splitlist(head,&list1,&list2);
    
    mergesort(&list1);
    mergesort(&list2);

    *list = mergesortedlists(list1,list2);
}

int main()
{
    vector<int> vec;
    // initialize random seed: 
    srand (time(NULL));
    for(int i=1;i<=7;i++)
    {
        int v2 = rand() % 100 + 1;  
        vec.push_back(v2);
        cout<<vec[i]<<",";
    }
    cout<<endl;

    List *list = createList(vec);
    cout<<list;

    mergesort(&list->head);
    cout<<"Sorted List:"<<list;


    //delete list;
}
