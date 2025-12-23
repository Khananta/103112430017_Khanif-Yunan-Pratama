#include <iostream>
#include "gym.h"

using namespace std;

int main() {
    BST tree;
    tree.createTree();

    tree.insertNode("Rizkina Azizah", 60, "Basic");
    tree.insertNode("Hakan Ismail", 50, "Bronze");
    tree.insertNode("Olivia Saevali", 65, "Silver");
    tree.insertNode("Felix Pedrosa", 47, "Gold");
    tree.insertNode("Gamel Al Ghifari", 56, "Platinum");
    tree.insertNode("Hanif Al Faiz", 70, "Basic");
    tree.insertNode("Mutiara Fauziah", 52, "Bronze");
    tree.insertNode("Davi Ilyas", 68, "Silver");
    tree.insertNode("Abdad Mubarok", 81, "Gold");

    tree.inOrder();

    Node* leftMost = tree.mostLeft();
    Node* rightMost = tree.mostRight();

    cout << "\n";
    cout << "Node MostLeft : " << (leftMost ? (int)leftMost->beratBadan : -1) << "\n";
    cout << "Node MostRight : " << (rightMost ? (int)rightMost->beratBadan : -1) << "\n\n";

    tree.searchByBeratBadan(70);

    return 0;
}