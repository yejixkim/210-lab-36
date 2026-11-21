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

    int choice;

    do {
        cout << "\n===== CODE DATABASE MENU =====" << endl;
        cout << "1. Add a code" << endl;
        cout << "2. Remove a code" << endl;
        cout << "3. Search for a code" << endl;
        cout << "4. Modify a code" << endl;
        cout << "5. Display all codes" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter code to add: ";
                cin >> code;

                if (tree.searchNode(code)) {
                    cout << "Code already exists." << endl;
                }
                else {
                    tree.insertNode(code);
                    cout << "Code added successfully." << endl;
                }
                break;

            case 2:
                cout << "Enter code to remove: ";
                cin >> code;

                if (tree.searchNode(code)) {
                    tree.remove(code);
                    cout << "Code removed successfully." << endl;
                }
                else {
                    cout << "Code not found." << endl;
                }
                break;

            case 3:
                cout << "Enter code to search for: ";
                cin >> code;

                if (tree.searchNode(code))
                    cout << "Code found." << endl;
                else
                    cout << "Code not found." << endl;
                break;

            case 4: {
                string oldCode, newCode;

                cout << "Enter the code you want to modify: ";
                cin >> oldCode;

                if (tree.searchNode(oldCode)) {
                    cout << "Enter the new code: ";
                    cin >> newCode;

                    if (newCode != oldCode && tree.searchNode(newCode)) {
                        cout << "That code already exists. Modification cancelled." << endl;
                    }
                    else {
                        tree.remove(oldCode);
                        tree.insertNode(newCode);
                        cout << "Code successfully modified." << endl;
                    }
                }
                else {
                    cout << "Code not found. Nothing to modify." << endl;
                }

                break;
            }

            case 5:
                cout << "Inorder traversal:" << endl;
                tree.displayInOrder();
                break;

            case 6:
                cout << "Exiting program." << endl;
                break;

            default:
                cout << "Invalid choice. Try again." << endl;
        }

    } while (choice != 6);

    return 0;
}
