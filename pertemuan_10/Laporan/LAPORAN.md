# <h1 align="center">Laporan Praktikum Modul 10 - Tree (Bagian Pertama)</h1>
<p align="center">Khanif Yunan Pratama - 103112430017</p>

## Dasar Teori
Pohon biner merupakan struktur data tidak linear yang digunakan untuk menyimpan dan mengelola data secara lebih efisien. Operasi seperti pencarian, penyisipan, dan penghapusan dapat dilakukan lebih cepat dibandingkan struktur linear, sehingga pohon biner banyak dimanfaatkan pada sistem besar dan kompleks. Salah satu bentuknya adalah Binary Search Tree (BST), yaitu pohon biner yang menjaga data tetap terurut sehingga proses pencarian dapat dilakukan secara lebih optimal. Struktur pohon juga bersifat hierarkis sehingga mudah dikembangkan menjadi bentuk yang lebih seimbang seperti AVL Tree atau Red-Black Tree untuk menjaga stabilitas performa. Dalam bidang praktis, pohon biner digunakan pada basis data, sistem file, jaringan komputer, dan algoritma komputasi karena kemampuannya menangani data dalam jumlah besar secara efisien[1].

Selain itu, konsep pohon dalam ilmu komputer digambarkan sebagai graf terhubung tanpa sirkuit yang memiliki hubungan hirarkis antar simpul. Salah satu pengembangannya adalah B-Tree, yaitu pohon pencarian seimbang yang dirancang untuk penyimpanan pada media disk. B-Tree digunakan dalam sistem basis data karena mampu memproses penyisipan, pencarian, dan penghapusan dengan waktu akses yang stabil meskipun data berukuran besar. Struktur ini memastikan setiap simpul daun berada pada tingkat yang sama sehingga menjaga keseimbangan dan efisiensi selama pengolahan data berlangsung[2].

## Guided 
### 1. Guided 1
##### BST1.cpp
```C++
#include "BST1.h"
#include <iostream>

using namespace std;

//isEmpty & createTree
bool isEmpty(address root) { //function untuk mengecek apakah BST kosong atau tidak
    if(root == NULL){
        return true;
    } else {
        return false;
    }
}

void createTree(address &root) { //function untuk membuat BST nya (root di-set sebagai NULL)
    root = NULL;
}


//alokasi & insert
address newNode(infotype x) { //function untuk memasukkan data (infotype) kedalam node
    address temp = new Node;
    temp->info = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

address insertNode(address root, infotype x) { //function untuk memasukkan node kedalam BST
    if (root == NULL) {
        return newNode(x);
    }

    if (x < root->info) {
        root->left = insertNode(root->left, x);
    } else if (x > root->info) {
        root->right = insertNode(root->right, x);
    }

    return root;
}


//Traversal
void preOrder(address root) { //function traversal tree secara pre-order (tengah - kiri - kanan atau root - child kiri - child kanan)
    if (root != NULL) {
        cout << root->info << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(address root) { //function traversal tree secara in-order (kiri - tengah - kanan atau child kiri - root - child kanan)
    if (root != NULL) {
        inOrder(root->left);
        cout << root->info << " ";
        inOrder(root->right);
    }
}

void postOrder(address root) { //function traversal tree secara post-order (kiri - kanan - tengah atau child kiri - child kanan - root)
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->info << " ";
    }
}


//Utilities
int countNodes(address root) { //function untuk menghitung size atau ukuran atau jumlah node yang ada didalam tree
    if (isEmpty(root) == true) {
        return 0;
    } else {
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
}

int treeDepth(address root) { //function untuk menghitung height atau kedalaman atau level tree
    if (isEmpty(root) == true) {
        return -1; //tree kosong jika depth = -1
    } else {
        int leftDepth = treeDepth(root->left);
        int rightDepth = treeDepth(root->right);
    
        return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
    }
}
```
##### BST1.h
```c++
#ifndef BST1_H
#define BST1_H

#include <iostream>

using namespace std;

typedef int infotype;
typedef struct Node *address;

struct Node{
    infotype info;
    address left;
    address right;
};

bool isEmpty(address root);
void createTree(address &root);
address newNode(infotype x);
address insertNode(address root, infotype x);
void preOrder(address root);
void inOrder(address root);
void postOrder(address root);
int countNodes(address root);
int treeDepth(address root);

#endif
```
##### main.cpp
```c++
#include <iostream>
#include "BST1.h"

using namespace std;

int main(){
    address root;
    createTree(root);

    cout << "Binary Search Tree Insert & Traversal" << endl;
    cout << endl;

    root = insertNode(root, 20); // Root awal
    insertNode(root, 10);
    insertNode(root, 35);
    insertNode(root, 5);
    insertNode(root, 18);
    insertNode(root, 40);

    cout << "Hasil InOrder Traversal : ";
    inOrder(root);
    cout << endl;

    cout << "Hasil PreOrder Traversal : ";
    preOrder(root);
    cout << endl;

    cout << "Hasil PostOrder Traversal : ";
    postOrder(root);
    cout << endl;

    cout << endl;
    cout << "Jumlah Node : " << countNodes(root) << endl;
    cout << "Kedalaman Tree : " << treeDepth(root) << endl;


    return 0;
}
```
Program ini merupakan implementasi struktur data Binary Search Tree (BST) menggunakan bahasa C++. Program menyediakan fitur untuk membuat tree, menambahkan node menggunakan aturan BST (nilai lebih kecil masuk ke kiri, lebih besar ke kanan), serta melakukan tiga jenis traversal: in-order, pre-order, dan post-order. Selain itu, program juga memiliki fungsi untuk menghitung jumlah node dan kedalaman tree. Pada fungsi main, tree dibuat kosong terlebih dahulu, kemudian beberapa nilai dimasukkan secara berurutan sehingga terbentuk sebuah BST. Setelah itu, program menampilkan hasil traversal serta informasi jumlah node dan kedalaman tree. Program ini menunjukkan bagaimana BST digunakan untuk mengorganisasi data secara terstruktur dan melakukan operasi rekursif pada setiap node.
### 2. Guided 2
##### BST2.cpp
```C++
#include "BST2.h"
#include <iostream>

using namespace std;

//FUNCTION & PROSEDUR SEBELUMNYA
//isEmpty & createTree
bool isEmpty(address root) { //function untuk mengecek apakah BST kosong atau tidak
    if(root == NULL){
        return true;
    } else {
        return false;
    }
}

void createTree(address &root) { //function untuk membuat BST nya (root di-set sebagai NULL)
    root = NULL;
}


//alokasi & insert
address newNode(infotype x) { //function untuk memasukkan data (infotype) kedalam node
    address temp = new Node;
    temp->info = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

address insertNode(address root, infotype x) { //function untuk memasukkan node kedalam BST
    if (root == NULL) {
        return newNode(x);
    }

    if (x < root->info) {
        root->left = insertNode(root->left, x);
    } else if (x > root->info) {
        root->right = insertNode(root->right, x);
    }

    return root;
}


//Traversal
void preOrder(address root) { //function traversal tree secara pre-order (tengah - kiri - kanan atau root - child kiri - child kanan)
    if (root != NULL) {
        cout << root->info << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(address root) { //function traversal tree secara in-order (kiri - tengah - kanan atau child kiri - root - child kanan)
    if (root != NULL) {
        inOrder(root->left);
        cout << root->info << " ";
        inOrder(root->right);
    }
}

void postOrder(address root) { //function traversal tree secara post-order (kiri - kanan - tengah atau child kiri - child kanan - root)
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->info << " ";
    }
}


//Utilities
int countNodes(address root) { //function untuk menghitung size atau ukuran atau jumlah node yang ada didalam tree
    if (isEmpty(root) == true) {
        return 0;
    } else {
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
}

int treeDepth(address root) { //function untuk menghitung height atau kedalaman atau level tree
    if (isEmpty(root) == true) {
        return -1; //tree kosong jika depth = -1
    } else {
        int leftDepth = treeDepth(root->left);
        int rightDepth = treeDepth(root->right);
    
        return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
    }
}


//FUNCTION & PROSEDUR BARU
//searching
void searchByData(address root, infotype x) { //function untuk melakukan searching data tertentu
    if(isEmpty(root) == true){
        cout << "BST kosong!" << endl;
    } else {
        address nodeBantu = root;
        address parent = NULL;
        bool ketemu = false;
        while(nodeBantu != NULL){
            if(x < nodeBantu->info){
                parent = nodeBantu;
                nodeBantu = nodeBantu->left;
            } else if(x > nodeBantu->info){
                parent = nodeBantu;
                nodeBantu = nodeBantu->right;
            } else if(x == nodeBantu->info){
                ketemu = true;
                break;
            }
        }
        if(ketemu == false){
            cout << "Data tidak ditemukan" << endl;
        } else if(ketemu == true){
            cout << "Data ditemukan didalam BST!" << endl;
            cout << "Data Angka : " << nodeBantu->info << endl;

            //menampilkan parentnya & pengecekan sibling
            address sibling = NULL;
            if(parent != NULL){
                cout << "Parent : " << parent->info << endl;
                if(parent->left == nodeBantu){
                    sibling = parent->right;
                } else if(parent->right == nodeBantu){
                    sibling = parent->left;
                }
            } else {
                cout << "Parent : - (node root)"<< endl;
            }

            //menampilkan siblingnya
            if(sibling != NULL){
                cout << "Sibling : " << sibling->info << endl;
            } else {
                cout << "Sibling : - " << endl;
            }

            //menampilkan childnya
            if(nodeBantu->left != NULL){
                cout << "Child kiri : " << nodeBantu->left->info << endl;
            } else if(nodeBantu->left == NULL){
                cout << "Child kiri : -" << endl;
            }
            if(nodeBantu->right != NULL){
                cout << "Child kanan : " << nodeBantu->right->info << endl;
            } else if(nodeBantu->right == NULL){
                cout << "Child kanan : -" << endl;
            }
        }
    }
}


//mostleft & mostright
address mostLeft(address root) { //function untuk menampilkan mostleft atau node paling kiri (node dengan nilai terkecil) didalam BST
    while (root->left != NULL){
        root = root->left;
    }
    return root;
}

address mostRight(address root) { //function untuk menampilkan mostright atau node paling kanan (node dengan nilai terbesar) didalam BST
    while (root->right != NULL){
        root = root->right;
    }
    return root;
}


//delete
bool deleteNode(address &root, infotype x) { //function untuk menghapus node tertentu didalam BST (menghapus berdasarkan parameter infotype)
    if (root == NULL) {
        return false; //data tidak ditemukan di subtree ini
    } else {
        if (x < root->info) {
            return deleteNode(root->left, x);
        } else if (x > root->info) {
            return deleteNode(root->right, x);
        } else {
            //jika node yang mau dihapus ditemukan
            //Case 1 : node yang mau dihapus adalah leaf
            if (root->left == NULL && root->right == NULL) {
                address temp = root;
                root = NULL;
                delete temp;
            }
            //Case 2 : node yang mau dihapus hanya punya right child
            else if (root->left == NULL) {
                address temp = root;
                root = root->right;
                delete temp;
            }
            //Case 3 : node yang mau dihapus hanya punya left child
            else if (root->right == NULL) {
                address temp = root;
                root = root->left;
                delete temp;
            }
            // Case 4 : jika node yang mau dihapus punya dua child, maka ambil mostleft dari subtree kanan untuk menggantikan node yang mau dihapus
            else {
                //mostleft dari subtree kanan = node successor (node penerus)
                address successor = mostLeft(root->right);
                //salin data successor ke node saat ini
                root->info = successor->info;
                //hapus successor pada subtree kanan
                return deleteNode(root->right, successor->info);
            }
            return true; //berhasil dihapus
        }
    }
}

void deleteTree(address &root) { //prosedur untuk menghapus BST (menghapus seluruh node BST)
    if(root == NULL){
        return;
    } else {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
        root = NULL;
    }
}
```

##### BST2.h
```c++
#ifndef BST1_H
#define BST1_H

#include <iostream>

using namespace std;

typedef int infotype;
typedef struct Node *address;

struct Node{
    infotype info;
    address left;
    address right;
};

bool isEmpty(address root);
void createTree(address &root);
address newNode(infotype x);
address insertNode(address root, infotype x);
void preOrder(address root);
void inOrder(address root);
void postOrder(address root);
int countNodes(address root);
int treeDepth(address root);
void searchByData(address root, infotype x);
address mostLeft(address root);
address mostRight(address root);
bool deleteNode(address &root, infotype x);
void deleteTree(address &root);

#endif
```

##### main.cpp
```c++
#include <iostream>
#include "BST2.h"

using namespace std;

int main(){
    address root;
    createTree(root);

    cout << "=== Binary Search Tree ==" << endl;
    cout << endl;

    root = insertNode(root, 30); // Root awal
    insertNode(root, 15);
    insertNode(root, 35);
    insertNode(root, 11);
    insertNode(root, 17);
    insertNode(root, 20);
    insertNode(root, 38);
    insertNode(root, 16);
    insertNode(root, 22);
    insertNode(root, 33);
    insertNode(root, 18);

    cout << "Hasil InOrder Traversal : ";
    inOrder(root);
    cout << endl;

    cout << endl;
    cout << "Jumlah Node : " << countNodes(root) << endl;
    cout << "Kedalaman Tree : " << treeDepth(root) << endl;

    cout << endl;
    searchByData(root, 17);
    
    cout << endl;
    cout << "Node mostleft : " << mostLeft(root)->info << endl;
    cout << "Node mostright : " << mostRight(root)->info << endl;

    cout << endl;
    infotype angkaHapus;
    cout << "Masukkan angka yang ingin dihapus: ";
    cin >> angkaHapus;
    //misal angka yang dihapus adalah angka 17
    if(deleteNode(root, angkaHapus)){
        cout << "Data " << angkaHapus << " berhasil dihapus!" << endl;
    } else {
        cout << "Data " << angkaHapus << " tidak ditemukan!" << endl;
    }
    cout << endl;

    searchByData(root, 17);
    cout << endl;
    searchByData(root, 18);

    cout << endl;
    cout << "Hasil InOrder Traversal : ";
    inOrder(root);
    cout << endl;

    cout << endl;
    deleteTree(root);
    cout << "Seluruh tree berhasil dihapus!" << endl;

    cout << endl;
    if(isEmpty(root) == true){
        cout << "BST kosong!" << endl;
    } else {
        cout << "Hasil InOrder Traversal : ";
        inOrder(root);
    }

    return 0;
}
```
Program ini adalah implementasi sederhana dari Binary Search Tree (BST) yang dapat melakukan berbagai operasi dasar seperti menambah data, menampilkan isi tree dengan traversal inorder, mencari nilai tertentu beserta informasi parent–sibling–child, menampilkan nilai terkecil serta terbesar, menghapus node tertentu, hingga menghapus seluruh isi tree. Setiap operasi dilakukan menggunakan fungsi rekursif sehingga proses penelusuran dan manipulasi node menjadi lebih efisien. Program ini menunjukkan cara kerja struktur data tree dalam mengelola data secara terurut dan bagaimana setiap operasi dilakukan dengan aturan dasar BST.
## Guided 3
```cpp
#include <iostream>

using namespace std;

int pangkat_2(int x){
    if (x == 0){
        return 1;
    } else if (x > 0){
        return 2 * pangkat_2(x-1);
    }
}

int main(){
    cout << "=== REKURSIF PANGKAT 2 ===" << endl;

    int x;
    cout << "Masukan nilai x:";
    cin >> x;
    cout << endl;
    cout << "Pangkat 2 dari " << x << " adalah " << pangkat_2(x) << endl;

    return 0;
}
```
Program di atas merupakan implementasi sederhana untuk menghitung nilai 2 pangkat x menggunakan fungsi rekursif. Fungsi pangkat_2(x) akan mengembalikan nilai 1 jika x bernilai 0 sebagai basis rekursi, sedangkan untuk x lebih besar dari 0, fungsi memanggil dirinya sendiri dengan mengurangi nilai x sebanyak 1 sambil mengalikan hasilnya dengan 2. Di dalam fungsi main, program meminta input nilai x dari pengguna, lalu menampilkan hasil perhitungan 2^x menggunakan fungsi rekursif tersebut.
## Unguided 

## bstree.h
```c++
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
```

## bstree.cpp
```c++
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
```

## main.cpp
```C++
#include <iostream>
#include "bstree.h"

using namespace std;

int main() {
    cout << "Hello World" << endl;
    address root = nullptr;
    insertNode(root,1);
    insertNode(root,2);
    insertNode(root,6);
    insertNode(root,4);
    insertNode(root,5);
    insertNode(root,3);
    insertNode(root,6);
    insertNode(root,7);
    inOrder(root);
    cout<<"\n";
    cout<<"kedalaman : "<< hitungKedalaman(root,0) << endl;
    cout<<"jumlah Node : "<< hitungJumlahNode(root) << endl;
    cout<<"total : "<< hitungTotalInfo(root) << endl;
    return 0;
}
```
![](gambar/gambar1.png)
Program ini mengimplementasikan struktur data Binary Search Tree (BST) menggunakan tipe data Node yang menyimpan nilai integer serta pointer ke anak kiri dan kanan. Fungsi alokasi digunakan untuk membuat node baru, sementara insertNode menyisipkan data ke dalam tree sesuai aturan BST secara rekursif. Fungsi findNode memungkinkan pencarian node berdasarkan nilai tertentu. Tree dapat ditampilkan secara terurut melalui inOrder, yang menelusuri node dari kiri–root–kanan. Program juga dilengkapi fungsi analisis tree, seperti hitungJumlahNode untuk menghitung total node, hitungTotalInfo untuk menjumlahkan seluruh nilai info di dalam tree, serta hitungKedalaman untuk menentukan kedalaman maksimum tree. Fungsi-fungsi ini bekerja dengan rekursi sehingga memudahkan proses penelusuran struktur tree secara efisien.
## Kesimpulan
BST terbukti mampu mengelola data secara terurut serta memungkinkan proses pencarian, penyisipan, dan penghapusan dilakukan lebih efisien dibanding struktur linear. Melalui implementasi rekursif, setiap operasi dapat berjalan lebih sederhana dan terstruktur. Selain itu, praktikum juga mengenalkan konsep rekursi melalui perhitungan pangkat, serta pembuatan fungsi tambahan seperti menghitung jumlah node, total nilai info, dan kedalaman pohon. Secara keseluruhan, praktikum ini memberikan pemahaman menyeluruh mengenai cara kerja dan manfaat pohon biner dalam pengolahan data.

## Referensi
**[1]** Wijoyo, Agung., Syukur, Abdul., Rabbani, Aditya Rizki., Ramadhan, Fazril., Hermawan, Haris., Christianto, Mikael Immanuel., Tipalahi, Ramadan. (2024). “Pemanfaatan Pohon Biner Untuk Pemrosesan Data Efisien”. _Jurnal Riset Informatika dan Inovasi (JRIIN)_, 2(2), 144–146. Diakses pada 6 Desember 2025 melalui [https://jurnalmahasiswa.com/index.php/jriin/article/view/1264/755](https://jurnalmahasiswa.com/index.php/jriin/article/view/1264/755)
<br>**[2]** Latifah, Fitri. (2016). “Penerapan Algorithma Pohon untuk Operasi Pengolahan dan Penyimpanan Data dalam Teknik Pemrograman (Kajian Algorithma Pohon pada Teknik Pemrograman)”. _Jurnal TECHN O Nusa Mandiri_, 13(2), 111. Diakses pada 6 Desember 2025 melalui  
[https://ejournal.nusamandiri.ac.id/index.php/techno/article/view/203/179](https://ejournal.nusamandiri.ac.id/index.php/techno/article/view/203/179)