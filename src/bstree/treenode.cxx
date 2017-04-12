#include <treenode.hxx>

Node* Node::getPrevNode()
{
    // Prev Node is in left sub tree.
    // Go to left child and then right most leaf node.
    Node* prev = this->left;

    while( prev->right)
    {
        prev = prev->right;
    }
    return prev;

}

Node* Node::getNextNode()
{
    // Next Node is in right sub tree.
    // Go to right child and then left most leaf node.

    Node *next = this->right;

    while( next->left )
    {
       next = next->left; 
    }

    return next;

}
