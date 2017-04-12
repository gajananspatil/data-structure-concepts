#include <iostream>
#include <vector>

struct Node
{
    int data;
    Node *next;
public:
    Node( int val ):
        data(val),
        next(NULL)
    {
    }
};

struct List
{
    Node *head;
    size_t size;

    friend std::ostream& operator <<(std::ostream& out, List *list);

    ~List()
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
std::ostream& operator <<(std::ostream& out, List *list)
{
    Node *node = list->head;
    int count = 0;
    while(node && count++<= list->size)
    {
        out<<node->data<<"->";
        node = node->next;
    }
    if(count<=list->size)
        out<<"NULL"<<std::endl;
    else
        out<<"...."<<std::endl;
    return out;
}
