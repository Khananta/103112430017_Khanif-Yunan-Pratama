#include "Singlylist.h"
#include <iostream>
using namespace std;

int main() {
    LinkedList L;
    createList(L);

    Node *P1, *P2, *P3, *P4, *P5;
    P1 = alokasi(9);
    P2 = alokasi(8);
    P3 = alokasi(2);
    P4 = alokasi(12);
    P5 = alokasi(0);

    insertFirst(L, P1);
    insertAfter(P1, P2);
    insertAfter(P1, P4);
    insertLast(L, P5);
    insertLast(L, P3);

    deleteFirst(L);
    deleteLast(L);
    deleteAfter(P4);

    printList(L);
    cout << "Jumlah node: " << nbList(L) << endl << endl;

    deleteList(L);
    cout << "- List Berhasil Terhapus -" << endl;
    cout << "Jumlah node: " << nbList(L) << endl;

    return 0;
}