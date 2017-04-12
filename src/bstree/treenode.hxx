/*
    Node structure for Tree DS
 */

#ifndef __TREE_NODE__
#define __TREE_NODE__

class Node
{
    Node *parent;
    Node *left;
    Node *right;
    int  key;

public:
    Node(int nodekey):
        parent(0),
        left(0),
        right(0),
        key(nodekey)
    {
    }

    void setParent(Node *parent)    { this->parent = parent;}
    void setLeft(Node *left)        { this->left = left;    }
    void setRight(Node *right)      { this->right = right;  }
    void setKey( int keyval )       { this->key = keyval;   }

    Node* getParent()   { return parent;    }
    Node* getLeft()     { return left;      } 
    Node *getRight()    { return right;     }
    int getKey()        { return key;       }

    bool isLeaf() { return (!left && !right)? true:false; }
    bool hasSingleChild() 
    {  
        bool result = false;
        if( (!left && right) ||
                (left && !right) )
            result = true;

        return result;
    }

    // Traverse the left subtree to get the immediate prev node by key
    Node* getPrevNode();

    // Traverse the right subtree to get the immediate next node by key
    Node* getNextNode();
};

#endif
