#include <iostream>
#include "avltree.hxx"

using namespace std;
int main()
{
    int arr[] = {5,3,2,1,4,7,8,6};
    int size = sizeof(arr)/sizeof(arr[0]);
    BTree btree;

    for(int i=0;i<size;i++)
        btree.insert(arr[i]);

   btree.printInOrder(); 
   btree.printPreOrder(); 
   btree.printPostOrder(); 

   int preOrdArr[]= {5,3,2,1,4,8,7,9};
   size = sizeof( preOrdArr)/sizeof(preOrdArr[0] );

   /*
   cout<< "Create Tree From Pre Order Input: ";
   BTree *tree = BTreeUtils::createTreeFromPreOrder( size, preOrdArr );
   tree->printInOrder(); 
   cout<<"\nRemove 2: ";
   tree->remove(2);
   tree->printInOrder(); 
   cout<<"\nRemove 1: ";
   tree->remove(1);
   tree->printInOrder(); 
   cout<<"\nRemove 4: ";
   tree->remove(4);
   tree->printInOrder(); 
   cout<<"\nRemove 3: ";
   tree->remove(3);
   tree->printInOrder(); 
   cout<<"\nRemove 8: ";
   tree->remove(8);
   tree->printInOrder(); 

   delete tree;
   */

}
