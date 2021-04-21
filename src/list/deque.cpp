#include <iostream>
#include <memory>

template <typename TYPE>
struct Node
{
    TYPE item;
    std::shared_ptr<Node> next;
    std::shared_ptr<Node> prev;

    Node(TYPE d):item(d),
    next(nullptr),
    prev(nullptr)

    { }

    ~Node()
    {
        std::cout<<"Deleted\n";
    }
};

template <typename TYPE>
class Deque
{
public:

    Deque(): first(nullptr),
        last(nullptr),
        size(0)
    { }

    ~Deque() 
    {
        std::cout<<"Deque Distructor\n";
        while(!isEmpty())
            removeFirst();
    }
    
    bool isEmpty()
    {
        return (size ==0);
    }

    void addFirst(TYPE i)
    {
        auto n = std::make_shared<Node<TYPE> >(i);
        if(first == nullptr)
        {
            first = n;
            last = n;

        }
        else
        {

            n->next = first;
            first->prev = n;

            first = n;
        }
        size++;
        return;
    }

    void addLast(TYPE i)
    {
        
        auto n = std::make_shared<Node<TYPE> >(i);
        if(last == nullptr)
        {
            first = n;
            last = n;
        }
        else
        {
            last->next =n;
            n->prev = last;
            last = n;
        }
        size++;
        return;
    }

    TYPE removeFirst()
    {
        std::shared_ptr<Node<TYPE> > r;

        if(size == 0)
        {
            std::cout<<"RemoveFirst Underflow!\n";
            return TYPE();
        }

        if(first) 
        {
            r =  first;
            first = first->next;
            if(first)
                first->prev = nullptr;
        }

        if(first == nullptr)
            last = nullptr;

        size--;
        return r->item;
    }


    TYPE removeLast()
    {
        if(size == 0)
        {
            std::cout<<"RemoveLast Underflow!\n";
            return TYPE();
        }

        std::shared_ptr<Node<TYPE> > r;
        if(last) 
        {
            r =  last;
            last = last->next;
            if(last)
                last->next = nullptr;
        }

        if(first == nullptr)
            last = nullptr;

        size--;
        return r->item;
    }
    
    size_t  getsize() { return size;}
    class Iterator;

    Iterator iterator() 
    {
        return Iterator(first);
    }

    class Iterator
    {
        std::shared_ptr< Node<TYPE> > node;
    public:
        Iterator(std::shared_ptr<Node<TYPE> > first)
        :node(first)
        {
            std::cout<<"Iterator:\n";
        }

        bool hasNext()
        {
            return node != nullptr;
        }

        TYPE next()
        {
            auto n =  node; 
            node = node->next;
            return n->item;
        }
    };

private:

    std::shared_ptr<Node<TYPE>> first;
    std::shared_ptr<Node<TYPE>> last;
    size_t size;
};


int main()
{
    Deque<int> d;
    d.addFirst(1);
    d.addFirst(2);
    d.addLast(3);
    d.addLast(4);

    d.addFirst(5);
    d.removeFirst();
    auto itr = d.iterator();
    while(itr.hasNext())
        std::cout<<itr.next()<<"\n";
}
