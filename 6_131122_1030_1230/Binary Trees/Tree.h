#ifndef TREE_HPP
#define TREE_HPP

#include "node.h"

class Tree{
    public:
           Node* root;

           Tree();

           void levelOrderTraversal();  
           void preOrderTraversal(Node* root);
           void postOrderTraversal(Node* root);
           void inOrderTraversal(Node* root);  
           void preOrderTraversalIterative();  

           Node* binarySearchTreeInsert(Node* root, int data);   
};

#endif