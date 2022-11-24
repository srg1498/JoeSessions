#include "Tree.h"
#include<iostream>

int main(){
    Tree tree = Tree();

    // insert some nodes in the tree manually
    tree.root = new Node(1);
    tree.root->left = new Node(2);
    tree.root->right = new Node(3);
    tree.root->left->left = new Node(4);
    tree.root->left->right = new Node(5);
    tree.root->right->left = new Node(6);
    tree.root->right->right = new Node(7);
    tree.root->left->left->left = new Node(8);
    tree.root->left->left->right = new Node(9);
    tree.root->left->right->left = new Node(10);
    tree.root->left->right->right = new Node(11);
    tree.root->right->left->right = new Node(13);
    tree.root->right->right->left = new Node(14);

    
    // level order traversal
    std::cout<<"level order traversal: ";
    tree.levelOrderTraversal();
    std::cout<<"\nparent of 5: "<<tree.root->left->right->parent<<"\n";
    std::cout<<"level of 5: "<<tree.root->left->right->level<<"\n";
    std::cout<<"parent of 13: "<<tree.root->right->left->right->parent<<"\n";
    std::cout<<"level of 13: "<<tree.root->right->left->right->level<<"\n";


    // pre order traversal
    std::cout<<"preorder traversal: ";
    tree.preOrderTraversal(tree.root);
    
    
    // post order traversal
    std::cout<<"\npostorder traversal: ";
    tree.postOrderTraversal(tree.root);


    ///in order traversal
    std::cout<<"\ninorder traversal: ";
    tree.inOrderTraversal(tree.root);


    // pre order traversal iterative
    std::cout<<"\npreorder traversal iterative: ";
    tree.preOrderTraversalIterative();




    // binary search tree
    Tree bst = Tree();
    bst.root = bst.binarySearchTreeInsert(bst.root, 10);
    bst.root = bst.binarySearchTreeInsert(bst.root, 20);
    bst.root = bst.binarySearchTreeInsert(bst.root, 5);
    std::cout<<"\nlevel order traversal: ";
    bst.levelOrderTraversal();
    std::cout<<"\ninorder traversal: ";
    bst.inOrderTraversal(bst.root);

    return 0;
}

