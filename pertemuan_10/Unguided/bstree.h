#ifndef BSTREE_H
#define BSTREE_H

#include <iostream>

using namespace std;

typedef int infotype;
typedef struct Node *address;

struct Node {
    infotype info;
    address left;
    address right;
};

void alokasi(infotype x, address &root);
void insertNode(address &root, infotype x);
address findNode(infotype x, address root);
void inOrder(address root);
int hitungJumlahNode(address root);
int hitungTotalInfo(address root);
int hitungKedalaman(address root, int start);

#endif