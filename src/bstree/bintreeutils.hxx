#include "binarytree.hxx"

namespace BTreeUtils{

    /*
        In Pre Order Traversal first element is the ROOT element.
        create root with first element.
        Then find first element greater than root, all the elements right to this form right subtree.
        all the elements left of it forms left subtree.
        This is done recursively.
    */

    BTree* createTreeFromPreOrder( int size, int *elements );
}
