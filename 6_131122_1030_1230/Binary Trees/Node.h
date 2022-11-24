#ifndef NODE_HPP
#define NODE_HPP

class Node{
    public:
           int data;
           Node* left;
           Node* right;
           int parent;
           int level;

           Node(int data);
           ~Node();
};

#endif