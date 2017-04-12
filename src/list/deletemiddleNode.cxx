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

void deleteMiddleNode( List *list )
{
    Node *fastptr = list->head;
    Node *slowptr = list->head;
    Node *prev = NULL;
    int size =0;

    if( !fastptr )
    {
        cout<<"Empty List"<<endl;
        return;
    }
    else if( !fastptr->next )
    {
        cout<<"list have only 1 element, deleting it"<<endl;
        delete fastptr;
        list->head = NULL;
        return;
    }

    while(fastptr)
    {
        fastptr = fastptr->next,size++;
        if(fastptr)
            fastptr = fastptr->next,size++;
        else 
            break;
    
        prev = slowptr;        
        slowptr = slowptr->next;
    }

   
    prev->next = slowptr->next;
    delete slowptr;
    return;        
}



int main()
{
    vector<int> vec;
    for(int i=1;i<=6;i++)
    {
        vec.push_back(i);
        cout<<vec[i]<<",";
    }
    cout<<endl;

    List *list = createList(vec);
    cout<<list;

    deleteMiddleNode(list);
    cout<<"Modified List: " << list;

    //delete list;
}
