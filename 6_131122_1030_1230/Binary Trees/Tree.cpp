#include "Tree.h"
#include<queue>
#include<iostream>
#include<stack>

Tree::Tree(){
    root = nullptr;
}


void Tree::levelOrderTraversal(){

    // first initialized queue of Node*
    std::queue<Node*> q;
    std::vector<Node*> leafNodes;
    std::vector<Node*> internalNodes;
    
    // push root first
    q.push(root);
    
    // traverse tree 
    while(!q.empty()){
        Node* node = q.front();
        q.pop();
        std::cout<<node->data<<" ";
        
        bool hasLeftChild = false;
        bool hasRightChild = false;
        
        if(node->left){
            q.push(node->left);
            hasLeftChild = true;
            node->left->parent = node->data;
            node->left->level = node->level + 1;
        }
        
        if(node->right){
            q.push(node->right);
            hasRightChild = true;
            node->right->parent = node->data;
            node->right->level = node->level + 1;
        }

        if(!hasLeftChild && !hasRightChild)
            leafNodes.push_back(node);
        else
            internalNodes.push_back(node);
    }
    
    std::cout<<"\nLeaf Nodes:  ";
    for(auto& node : leafNodes)
        std::cout<<node->data<<" ";

    std::cout<<"\nInternal Nodes:  ";
    for(auto& node : internalNodes)
        std::cout<<node->data<<" ";
}


void Tree::preOrderTraversal(Node* root){
    if(root == nullptr)
        return;
    std::cout<<root->data<<" ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}


void Tree::postOrderTraversal(Node* root){
    if(root == nullptr)
        return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    std::cout<<root->data<<" ";
}


void Tree::inOrderTraversal(Node* root){
    if(root == nullptr)
        return;
    inOrderTraversal(root->left);
    std::cout<<root->data<<" ";
    inOrderTraversal(root->right);
}


void Tree::preOrderTraversalIterative(){
    std::stack<Node*> leftStack;
    std::stack<Node*> rightStack;

    // push root in left
    leftStack.push(this->root);
    

    while(!leftStack.empty() || !rightStack.empty()){

        // traverse left first
        while(!leftStack.empty()){
            Node* node = leftStack.top();
            leftStack.pop();

            std::cout<<node->data<<" ";

            if(node->left)
                leftStack.push(node->left);
            
            if(node->right)
                rightStack.push(node->right);
        }

        // traverse right now
        while(!rightStack.empty()){
            Node* node = rightStack.top();
            rightStack.pop();

            std::cout<<node->data<<" ";

            if(node->left)
                leftStack.push(node->left);
            
            if(node->right)
                rightStack.push(node->right);
            
            if(!leftStack.empty())
                break;
        }
    }
}



Node* Tree::binarySearchTreeInsert(Node* root, int data){
    // base condition
    if(root == nullptr){
        Node* node = new Node(data);
        return node;
    }

    // check left condition
    if(data < root->data){
        root->left = binarySearchTreeInsert(root->left, data);
        return root;
    }

    // check right condition
    if(data > root->data){
        root->right = binarySearchTreeInsert(root->right, data);
        return root;
    }

    return root;
}