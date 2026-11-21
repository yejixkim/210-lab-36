// COMSC 210 | Lab 36 | Yeji Kim
#include <iostream>
#include <fstream>
#include <string>
#include "IntBinaryTree.h"
using namespace std;

int main() {
    IntBinaryTree tree;
    string code;
    int count = 0;
    ifstream inputFile("codes.txt");

    if (!inputFile) {
        cout << "Error opening codes.txt" << endl;
        return 1;
    }

    // Read each code and insert it into the tree.
    while (getline(inputFile, code)) {
        tree.insertNode(code);
        count++;
    }

    inputFile.close();

    cout << "Codes loaded successfully!" << endl;
    cout << "Total codes loaded: " << count << endl;

    return 0;
}