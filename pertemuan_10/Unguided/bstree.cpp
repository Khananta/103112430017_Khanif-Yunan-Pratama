#include "bstree.h"
#include <iostream>

using namespace std;

void alokasi(infotype x, address &root) {
    root = new Node;
    root->info = x;
    root->left = NULL;
    root->right = NULL;
}

void insertNode(address &root, infotype x) {
    if (root == NULL) {
        alokasi(x, root);
    } else {
        if (x < root->info) {
            insertNode(root->left, x);
        } else if (x > root->info) {
            insertNode(root->right, x);
        }
    }
}

address findNode(infotype x, address root) {
    if (root == NULL) {
        return NULL;
    } else {
        if (x < root->info) {
            return findNode(x, root->left);
        } else if (x > root->info) {
            return findNode(x, root->right);
        } else {
            return root;
        }
    }
}

void inOrder(address root) {
    if (root != NULL) {
        inOrder(root->left);
        cout << root->info << " - ";
        inOrder(root->right);
    }
}

int hitungJumlahNode(address root) {
    if (root == NULL) {
        return 0;
    } else {
        return 1 + hitungJumlahNode(root->left) + hitungJumlahNode(root->right);
    }
}

int hitungTotalInfo(address root) {
    if (root == NULL) {
        return 0;
    } else {
        return root->info + hitungTotalInfo(root->left) + hitungTotalInfo(root->right);
    }
}

int hitungKedalaman(address root, int level) {
    if (root == NULL) {
        return level;
    } else {
        return max(hitungKedalaman(root->left, level + 1), hitungKedalaman(root->right, level + 1));
    }
}