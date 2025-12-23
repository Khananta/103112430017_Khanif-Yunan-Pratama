#ifndef GYM_H
#define GYM_H

#include <string>

using std::string;

struct Node {
    string namaMember;
    float beratBadan;
    string tierMember;
    Node* left;
    Node* right;
};

class BST {
private:
    Node* root;

    void inOrder(Node* cur) const;
    void printNodeDetail(const string& header, Node* n) const;

public:
    BST();

    bool isEmpty() const;
    void createTree();

    Node* newNode(const string& nama, float berat, const string& tier);
    void insertNode(const string& nama, float berat, const string& tier);

    Node* mostLeft() const;
    Node* mostRight() const;

    void inOrder() const;
    void searchByBeratBadan(float beratCari) const;
};

#endif