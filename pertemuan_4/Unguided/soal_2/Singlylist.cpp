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

void deleteFirst(LinkedList &L) {
    if (!isEmpty(L)) {
        Node* P = L.first;
        L.first = P->next;
        delete P;
    }
}

void deleteLast(LinkedList &L) {
    if (!isEmpty(L)) {
        if (L.first->next == nullptr) {
            delete L.first;
            L.first = nullptr;
        } else {
            Node* Q = L.first;
            Node* Prev = nullptr;
            while (Q->next != nullptr) {
                Prev = Q;
                Q = Q->next;
            }
            Prev->next = nullptr;
            delete Q;
        }
    }
}

void deleteAfter(Node* Prec) {
    if (Prec != nullptr && Prec->next != nullptr) {
        Node* P = Prec->next;
        Prec->next = P->next;
        delete P;
    }
}

int nbList(LinkedList L) {
    int count = 0;
    Node* P = L.first;
    while (P != nullptr) {
        count++;
        P = P->next;
    }
    return count;
}

void deleteList(LinkedList &L) {
    while (!isEmpty(L)) {
        deleteFirst(L);
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