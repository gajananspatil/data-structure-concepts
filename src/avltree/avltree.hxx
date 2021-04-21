#ifndef __AVL_TREE__
#define __AVL_TREE__

#include <iostream>
#include "avlnode.hxx"

class BTree
{

public:

    BTree():
        root(0),
        size(0)
    { }

    BTree( AVLNode *node, int count ):
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
    AVLNode * find( int key );

    void printInOrder( );
    void printPreOrder( );
    void printPostOrder( );
private:
    AVLNode *root;
    void deleteTree( AVLNode *node);
    unsigned long size;
};
    
#endif
