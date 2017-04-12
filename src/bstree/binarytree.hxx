#ifndef __BINARY_TREE__
#define __BINARY_TREE__

#include <iostream>
#include "treenode.hxx"

class BTree
{

public:

    BTree():
        root(0),
        size(0)
    { }

    BTree( Node *node, int count ):
        root(node),
        size(count)
    { }

    ~BTree()
    {
        std::cout<<"Destory Tree-";
        deleteTree(root);
        std::cout<<std::endl;
    }

    void insert( int key );
    void remove( int key );
    Node * find( int key );

    void printInOrder( );
    void printPreOrder( );
    void printPostOrder( );
private:
    Node *root;
    void deleteTree( Node *node);
    unsigned long size;
};
    
#endif
