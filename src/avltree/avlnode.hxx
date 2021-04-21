/*
    Node structure for Tree DS
 */

#ifndef __AVL_NODE__
#define __AVL_NODE__

class AVLNode
{
    AVLNode *parent;
    AVLNode *left;
    AVLNode *right;
    int  key;

public:
    AVLNode(int nodekey):
        parent(0),
        left(0),
        right(0),
        key(nodekey)
    {
    }

    void setParent(AVLNode *parent)    { this->parent = parent;}
    void setLeft(AVLNode *left)        { this->left = left;    }
    void setRight(AVLNode *right)      { this->right = right;  }
    void setKey( int keyval )       { this->key = keyval;   }

    AVLNode* getParent()   { return parent;    }
    AVLNode* getLeft()     { return left;      } 
    AVLNode *getRight()    { return right;     }
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
    AVLNode* getPrevNode();

    // Traverse the right subtree to get the immediate next node by key
    AVLNode* getNextNode();
};

#endif
