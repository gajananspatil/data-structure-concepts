#include "bintreeutils.hxx"


namespace {

    int getIndexOfFirstMax(int size,int refNo, int *elements )
    {
        int index = 0;
        for( ; index <size;index++)
        {
            if( refNo < elements[index] )
                return index; 
        }
        return -1;
    }

    /*
        In Pre Order Traversal first element is the ROOT element.
        create root with first element.
        Then find first element greater than root, all the elements right to this form right subtree.
        all the elements left of it forms left subtree.

        This is done recursively.
    */
    Node* createTreeUsingPreOrder( int size, int *elements )
    {
        if( size == 0 )
            return 0;

        if( size == 1 )
        {
            return new Node( elements[0] );
        }

        Node *root = new Node( elements[0] );

        int index = getIndexOfFirstMax( size,elements[0],elements );

        // create left subtree
        int ltreeindex = index > 0 ?index-1:size-1; 
        Node *lnode = createTreeUsingPreOrder( ltreeindex, &elements[1] );
        if( lnode )
        {
            root->setLeft( lnode );
            lnode->setParent( root );
        }

        // create right subtree
        if( index > 0 )
        {
            int rtreeindex = (size - index);
            Node *rnode = createTreeUsingPreOrder( rtreeindex , &elements[index] );
            if( rnode )
            {
                root->setRight( rnode );
                rnode->setParent( root );
            }
        }
        return root;
    }

} // namespace

BTree* BTreeUtils::createTreeFromPreOrder( int size, int *elements )
{
    BTree *tree = NULL;
    Node *root = createTreeUsingPreOrder( size, elements );
    if( root )
    {
        tree = new BTree(root, size);
    }

    return tree;

}
