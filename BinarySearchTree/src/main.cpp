#include <iostream>
#include <fstream>

#include "Node.h"
#include "BSTree.h"

using namespace std;

void TreeToFile(BSTree aTree); // File writing prototype

int main() {

    BSTree tree; // Declare tree
    tree.LoadTree("dictionary.txt"); // Load file contents into tree

    // Test 1
    cout << "\n\nDictionary Tree (Unbalanced)" << endl;
    cout << "----------------------------" << endl;
    cout << tree << endl;

    // Test 2
    cout << "\n\nDictionary Tree (Balanced)" << endl;
    cout << "--------------------------" << endl;
    tree.Balance();
    cout << tree << endl;

    // Test 3
    cout << "\n\nSpell Check Test" << endl;
    cout << "----------------" << endl;
    tree.CheckFile("mispelled.txt");

    TreeToFile(tree); // Write Tree to File
    

    return 0;

} // End Main


void TreeToFile(BSTree aTree) { // Redirect BST output to a text file

    fstream treeFile;
    treeFile.open("..\\output\\test.txt", ios::out);
    string branch;

    // Back up stream buffer
    streambuf* stream_buffer_cout = cout.rdbuf();

    // Get stream buffer of file
    streambuf* stream_buffer_file = treeFile.rdbuf();
    cout.rdbuf(stream_buffer_file);

    cout << aTree;

    cout.rdbuf(stream_buffer_cout); // Redirect output to console
    treeFile.close();

} // End TreeToFile()
