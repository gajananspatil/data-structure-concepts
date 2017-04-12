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


/**
  * Can be a member function.
  Iterative Solution for reverse K nodes and then skip K nodes
  */
void reverseAlternateKNodes( List *list, int nodecount )
{
    Node *curr = list->head;
    int newhead = 0;
    Node *listhead = list->head ;
    Node *head = listhead;
    Node *tempcurr  = NULL;
    while(curr)
    {
        cout<<"----------------------------- ITERATION --------------------------------"<<endl;
        int count = 0;
        Node *temp = NULL;
        Node *prev = NULL;
        while(curr && count < nodecount)
        {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
            count++;
        }
        cout<<"Current List"<<list;
        if(newhead == 0)
        {
            // set new list node once, the first node after reversing first k nodes 
            list->head = prev;
            head->next = curr;      // old head should now point to next element of current node i.e. next unreveresed list
            newhead = 1;
        }
        else
        {
            head->next = prev;      // make current moving head point to following reversed sub-list  6->(9->8->7..)
            tempcurr->next = curr;  // make earlier head point to next unprocessed sub-list.  6->9->8->7->(10 ....)
        }

        // Skip the next K nodes 
        count=0;
        while(curr && count< nodecount)
        {
            prev = curr;
            curr = curr->next;
            count++;
        }

        head = prev;            // move temporary node ahead
        tempcurr = curr;        // store curr node to point it to next un-reversed sub-list 
        //cout<<"Current List"<<list;
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

    List *list = createList(vec);
    cout<<list;

    List *origlist = createList(vec);
    reverseAlternateKNodes(origlist,4);
    cout<<"Reversed KNodes List: " << origlist;
    //delete list;
}
