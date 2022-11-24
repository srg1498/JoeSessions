#include "./node.h"

Node::Node(int data){
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
    this->level = 0;
    this->parent = -1;
}


Node::~Node(){
    if(left)
        delete left;
    if(right)
        delete right;
}