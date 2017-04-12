#include <iostream>
#include <vector>

struct Node
{
    int data;
    Node *next;
    Node *prev;

    Node( int val ):
        data(val),
        next(NULL),
        prev(NULL)
    {
    }
};

struct DList
{
    Node *head;
    size_t size;

    friend std::ostream& operator << (std::ostream& out, DList *list);

    ~DList()
    {
        if(head && size > 0)
        {
            std::cout<<"delete all nodes";
            Node *curr = head;
            Node *next = curr->next;
            while(curr)
            {
                delete curr;
                curr = next;
                if(next)
                    next = next->next;
            }
        }
    }
};

std::ostream& operator << (std::ostream& out, DList *list)
{
    Node *node = list->head;
    while(node)
    {
        out<<node->data<<"<->";
        node = node->next;
    }
    out<<"NULL"<<std::endl;
    return out;
}
