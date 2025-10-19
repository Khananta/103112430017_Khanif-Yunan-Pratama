#include "Singlylist.h"

void createList(LinkedList &L) {
    L.first = nullptr;
}

bool isEmpty(LinkedList L) {
    return (L.first == nullptr);
}

Node* alokasi(int x) {
    Node* P = new Node;
    P->info = x;
    P->next = nullptr;
    return P;
}

void insertFirst(LinkedList &L, Node* P) {
    P->next = L.first;
    L.first = P;
}

void insertAfter(Node* Prec, Node* P) {
    if (Prec != nullptr) {
        P->next = Prec->next;
        Prec->next = P;
    }
}

void insertLast(LinkedList &L, Node* P) {
    P->next = nullptr;
    if (isEmpty(L)) {
        L.first = P;
    } else {
        Node* Q = L.first;
        while (Q->next != nullptr) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

void printList(LinkedList L) {
    if (isEmpty(L)) {
        cout << "List kosong." << endl;
    } else {
        Node* P = L.first;
        while (P != nullptr) {
            cout << P->info;
            if (P->next != nullptr) cout << " ";
            P = P->next;
        }
        cout << endl;
    }
}