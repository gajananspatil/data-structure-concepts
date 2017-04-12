#include "linkedlist.hxx"
#include <map>
using namespace std;


List * createList( std::vector<int> &vec, bool createcycle)
{
    List *list = new List();
    list->size = vec.size(); 
    Node *curr = NULL;
    Node *prev = NULL;
    Node *cyclenode = NULL;
    for( int i=0; i < vec.size(); i++)
    {
        curr = new Node(vec[i]);
        if( i == 0) 
            list->head = curr;

        if(prev)
            prev->next = curr;

        if( i == 6 )
            cyclenode = curr;

        prev = curr;
    }

    if( createcycle)
    {
        curr->next = cyclenode;
        cout<<"Cycle created from "<<curr->data<<" to "<<cyclenode->data<<endl;
    }

    return list;
}

bool iscyclepresent(Node *head)
{
    bool result = false;
    map<int,bool> visited;
    std::map<int,bool>::iterator it;
    Node *node = head;
    Node *prev = NULL;

    while(node)
    {
        it = visited.find(node->data);
        if( it != visited.end() )
        {
            result = true;
            break;
        }
        visited[node->data] = true;
        prev = node;
        node = node->next;
    }

    if( result)
        cout<<"Cycle Present: Node: "<<prev->data<<" -> Node: "<<node->data<<" forms cycle "<<endl;
    else
        cout<<"No cycle present";
    return result;
}

int main()
{
    vector<int> vec;
    for(int i=1;i<=19;i++)
    {
        vec.push_back(i);
        cout<<vec[i-1]<<",";
    }
    cout<<endl;

    List *list = createList(vec,false);
    cout<<list;

    List *origlist = createList(vec,true);
    cout<<origlist;


    iscyclepresent(origlist->head);
    iscyclepresent(list->head);
    //delete list;
}
