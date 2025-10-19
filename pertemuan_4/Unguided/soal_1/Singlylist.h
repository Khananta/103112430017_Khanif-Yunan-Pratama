    #ifndef SINGLYLIST_H
    #define SINGLYLIST_H

    #include <iostream>
    using namespace std;

    struct Node {
        int info;
        Node* next;
    };

    struct LinkedList {
        Node* first;
    };

    void createList(LinkedList &L);
    bool isEmpty(LinkedList L);
    Node* alokasi(int x);
    void insertFirst(LinkedList &L, Node* P);
    void insertAfter(Node* Prec, Node* P);
    void insertLast(LinkedList &L, Node* P);
    void printList(LinkedList L);

    #endif