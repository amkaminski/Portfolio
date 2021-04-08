//
// Header file describing 'Node' members and features
//
// Created by am_ka on 2021-03-01.
//

#ifndef ASSIGNMENT_3_NODE_H
#define ASSIGNMENT_3_NODE_H

#include <iostream>
#include <iomanip>

using namespace std;

// forward declaration
class Node;

typedef Node* NodePtr;

class Node {
public:
    string data; // Value held

    // Pointers to subsequent Nodes branching off
    // current Node
    NodePtr left;
    NodePtr right;

    // Default Node Constructor
    Node() : data(""), left(nullptr), right(nullptr) {}
};

#endif //ASSIGNMENT_3_NODE_H
