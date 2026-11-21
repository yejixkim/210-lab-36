// COMSC 210 | Lab 36 | Yeji Kim
#include <iostream>
#include "IntBinaryTree.h"
using namespace std;

int main() {
    IntBinaryTree tree;

    // Insert some string values
    tree.insertNode("B12");
    tree.insertNode("A25");
    tree.insertNode("C30");
    tree.insertNode("D15");

    cout << "Inorder traversal:" << endl;
    tree.displayInOrder();

    cout << "\nSearching for B12:" << endl;
    cout << (tree.searchNode("B12") ? "Found" : "Not found") << endl;

    cout << "\nSearching for X99:" << endl;
    cout << (tree.searchNode("X99") ? "Found" : "Not found") << endl;

    cout << "\nRemoving B12..." << endl;
    tree.remove("B12");

    cout << "\nInorder traversal after removal:" << endl;
    tree.displayInOrder();

    return 0;
}