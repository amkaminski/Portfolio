//
// Header file describing 'BSTree' members and features
//
// Created by am_ka on 2021-03-01.
//

#ifndef ASSIGNMENT_3_BSTREE_H
#define ASSIGNMENT_3_BSTREE_H

#include "Node.h"
#include <vector>

// Console Output Color Values
const int RED_TEXT = 4;
const int WHITE_TEXT = 7;

class BSTree {
private:
    NodePtr root; // Head of the Binary Search Tree
    vector<string> allWords; // Vector to store the ordered data

public:
    BSTree() : root(nullptr) {} // Constructor
    virtual ~BSTree(); // Destructor

    void Delete(); // Invoke DeleteTree
    void DeleteTree(NodePtr node); // Remove Tree Contents
    void Insert(string word);
    void Insert(string word, NodePtr& node);
    void Remove(string word);

    void LoadTree(string filename); // Load File Contents into Tree

    void Balance(); // Invoke Recursive Balancing Function
    void Balance(vector<string> aList);

    void CheckFile(string filename); // Check File Contents against Tree
    bool CheckIfNodeExists(string key);
    bool CheckIfNodeExists(NodePtr node, string key);

    void Color(int c); // Coloring Function
    string toLower(string word); // Bring a given string to all lower case

    void PrintTree(ostream& output, NodePtr& node, int indent);

    // Output Operator Friend Function
    friend ostream& operator<< (ostream& output, BSTree& tree);

};
#endif //ASSIGNMENT_3_BSTREE_H
