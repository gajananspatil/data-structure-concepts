#include <iostream>
#include "avltree.hxx"

namespace{

    void inOrder( AVLNode *node )
    {

        if(!node)
            return;
        inOrder(node->getLeft());
        std::cout<<node->getKey()<<",";
        inOrder(node->getRight());
    
    }

    void preOrder( AVLNode *node )
    {
        if(!node)
            return;
        std::cout<<node->getKey()<<",";
        preOrder(node->getLeft());
        preOrder(node->getRight());
    
    }

    void postOrder( AVLNode *node )
    {
        if(!node)
            return;
        postOrder(node->getLeft());
        postOrder(node->getRight());
        std::cout<<node->getKey()<<",";
    }    

    void swapData( AVLNode *node1, AVLNode *node2 )
    {
        int temp = node1->getKey();
        node1->setKey( node2->getKey() );
        node2->setKey( temp );
    }

    void removeLeaf( AVLNode *node )
    {
        AVLNode *parent = node->getParent();
        if( parent->getLeft() == node )
            parent->setLeft( NULL );
        else
            parent->setRight( NULL );
    }

    void removeSingleChildNode( AVLNode *node )
    {
        
        AVLNode *exchangeNode = NULL;
        if( node->getLeft() )
            exchangeNode = node->getPrevNode();
        else
            exchangeNode = node->getNextNode();

        swapData( exchangeNode, node );

        if( exchangeNode->isLeaf() )
            removeLeaf( exchangeNode );
        else
            removeSingleChildNode( exchangeNode );

    }

    void removeTwoChildNode( AVLNode *node )
    {
        AVLNode *exchangeNode = node->getNextNode();

        swapData( exchangeNode, node ); 

        if( exchangeNode->isLeaf() )
            removeLeaf( exchangeNode );
        else
            removeSingleChildNode( exchangeNode );

    }
}

void BTree::deleteTree( AVLNode *node )
{
    if( !node )
        return;
    /*
    if( !node->getLeft() && !node->getRight() )
    {
        cout<<node->getKey()<<" ";
        delete node;
        return;
    }
    */

    deleteTree( node->getLeft() );
    deleteTree( node->getRight() );

    std::cout<<node->getKey()<<" ";
    delete node;
}


void BTree::insert( int key )
{
    if( !root )
    {
        std::cout<<"Added Root"<<key<<std::endl;
        root = new AVLNode( key );
        size++;
        return; 
    }

    AVLNode *node = root;
    AVLNode *after = 0;
    while(node)
    {
        after = node;
        if( key > node->getKey() )
            node = node->getRight();
        else
            node = node->getLeft();
    }

    AVLNode *child = new AVLNode ( key );
    child->setParent( after );

    if( key > after->getKey() )
        after->setRight( child );
    else
        after->setLeft( child );
    size++;
} 

AVLNode* BTree::find( int key )
{
    AVLNode * node = root;
    bool isfound = false;
    while( node )
    {
        if( key > node->getKey() )
        {
            node = node->getRight();
        }
        else if( node->getKey() == key )
        {
            isfound = true;
            break;
        }
        else
        {
            node = node->getLeft();
        }
    }
    return isfound == true? node:NULL;
}

/**
  * delete the node having input key can lead to handle complex scenarios. 
  * i.e. if root node has only right child and delete of root need to checked and many other cases.
  *
  * Its observed that every time for delete we get the either prev or next value. Only exchnage 
  * values. Hence delete will happen every time at leaf or leaf with single child. Easy to handle.
  * TODO not yet implemented this logic.
  */
void BTree::remove( int key )
{

    AVLNode *node = find( key );
    if( !node )
    {
        std::cout<<"Key Not Present"<<std::endl;
        return;
    }
    if( node->isLeaf() ) // Leaf Node
    {
        removeLeaf( node);
    }
    else if( node->hasSingleChild() )   // Intermediate node with only one child
    {

        removeSingleChildNode( node );
    }
    else
    {
        removeTwoChildNode( node );
    }
    size--;
    if( size == 0 )
        root = 0;

}
/**
void BTree::remove( int key )
{
    AVLNode *node = find( key );
    if( !node )
    {
        std::cout<<"Key Not Present"<<std::endl;
        return;
    }

    bool isleftchild = false;
    AVLNode *parent = node->getParent();
    if( parent->getLeft() == node ) // update parent node
    {
        parent->setLeft( NULL );
        isleftchild = true;
    }
    else
    {
        parent->setRight( NULL );
    }

    if( node->isLeaf() ) // Leaf Node
    {
        removeLeaf( node);
    }
    else if( node->hasSingleChild() )   // Intermediate node with only one child
    {

        removeSingleChildNode( node );
            
        // delete actual node and update parent
        if( node->getLeft() )
        {
            if( isleftchild )  // 
                parent->setLeft( node->getLeft() );
            else 
                parent->setRight( node->getLeft() );
        }
        else
        {
            if( isleftchild )  // 
                parent->setLeft( node->getRight() );
            else 
                parent->setRight( node->getRight() );
        }

        node->getLeft()->setParent(parent);

        // another approach can be tried to get the prev node and exchange keys 
        // then delete the leaf node i.e. prev node found. This is used in below case
        delete node ;
    }
    else                                                // Intermediate node with both child
    {
        std::cout<<"complex case"<<std::endl;  

    }

    size--;
    if( size == 0)
        this->root = NULL;

}
 */

void BTree::printInOrder( )
{
    std::cout<<"InOrder :";
    inOrder(root);
    std::cout<<std::endl;
}


void BTree::printPostOrder( )
{
    std::cout<<"PostOrder :";
    postOrder(root);
    std::cout<<std::endl;

}

void BTree::printPreOrder( )
{
    std::cout<<"PreOrder :";
    preOrder(root);
    std::cout<<std::endl;

}
