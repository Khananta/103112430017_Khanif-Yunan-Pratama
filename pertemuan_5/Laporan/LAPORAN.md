# <h1 align="center">Laporan Praktikum Modul 5 - SINGLY LINKED LIST (BAGIAN KEDUA)</h1>
<p align="center">Khanif Yunan Pratama - 103112430017</p>

## Dasar Teori
Pencarian linear adalah metode pencarian yang paling sederhana dalam struktur data. Proses ini melibatkan pemeriksaan setiap elemen dalam list secara berurutan untuk mencari elemen yang sesuai dengan kunci pencarian. Keunggulan dari pencarian linear adalah kesederhanaannya dan kemampuannya untuk digunakan pada data yang tidak terurut. Namun, kekurangannya adalah efisiensi waktu yang rendah, karena waktu yang diperlukan untuk menemukan elemen sebanding dengan ukuran list. Dalam implementasinya, pencarian linear dilakukan dengan menelusuri setiap elemen hingga elemen yang dicari ditemukan atau list berakhir [2].

Kemudian pencarian binary merupakan algoritma pencarian yang lebih efisien, namun hanya dapat digunakan pada struktur data yang terurut. Pencarian dilakukan dengan membagi list menjadi dua bagian yang lebih kecil dan membandingkan elemen tengah dengan elemen yang dicari. Berdasarkan perbandingan tersebut, pencarian dilanjutkan pada bagian kiri atau kanan list. Pencarian binary memiliki waktu eksekusi yang lebih cepat dengan kompleksitas O(log n), di mana n adalah jumlah elemen dalam list. Keunggulan utama dari algoritma ini adalah efisiensinya dalam mencari elemen pada data yang sudah terurut [2].

Dalam implementasi algoritma pencarian pada aplikasi berbasis kamus bahasa, perbandingan antara Linear Search dan Binary Search dapat menunjukkan perbedaan signifikan dalam hal kecepatan eksekusi. Pencarian linear lebih mudah diimplementasikan karena tidak memerlukan struktur data yang terurut, namun kurang efisien jika digunakan pada data yang besar. Sementara itu, Binary Search, meskipun lebih kompleks dalam implementasinya karena membutuhkan pengurutan data terlebih dahulu, menawarkan efisiensi yang lebih baik pada data terurut. Kelemahan Binary Search terletak pada kebutuhan untuk pengurutan data terlebih dahulu, yang dapat memakan waktu, sementara Linear Search dapat langsung diterapkan pada data yang tidak terurut [1].
## Guided 

### 1. Guided 1
a. listBuah.cpp
```C++
#include "listBuah.h"
#include <iostream>
using namespace std;

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {
    List.first = Nil;
}
//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, int jumlah, float harga) { 
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jumlah = jumlah; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(linkedlist &List){
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "Node pertama berhasil terhapus!" << endl;
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List){
    address nodeHapus, nodePrev;
    if(isEmpty(List) == false){
        nodeHapus = List.first;
        if(nodeHapus->next == Nil){
            List.first->next = Nil;
            dealokasi(nodeHapus);
        } else { 
            while(nodeHapus->next != Nil){
                nodePrev = nodeHapus; 
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil; 
            dealokasi(nodeHapus);
        }
        cout << "Node terakhir berhasil terhapus!" << endl;
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
            cout << "Node setelah node " << nodePrev->isidata.nama << " berhasil terhapus!" << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedlist List) {
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

//prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedlist &List){
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
    cout << "List berhasil terhapus!" << endl;
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - PART 1 (UPDATE) -----*/
//prosedur-prosedur untuk melakukan update data node
void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama buah : ";
        cin >> List.first->isidata.nama;
        cout << "Jumlah : ";
        cin >> List.first->isidata.jumlah;
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateLast(linkedlist List){
    if (isEmpty(List) == true) {
        cout << "List Kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        cout << "masukkan update data node terakhir : " << endl;
        cout << "Nama buah : ";
        cin >> nodeBantu->isidata.nama;
        cout << "Jumlah : ";
        cin >> nodeBantu->isidata.jumlah;
        cout << "Harga : ";
        cin >> nodeBantu->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama buah : ";
            cin >> nodeBantu->isidata.nama;
            cout << "Jumlah : ";
            cin >> nodeBantu->isidata.jumlah;
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}```

b. listBuah.h
```c++
#ifndef LISTBUAH_H
#define LISTBUAH_H

#define Nil NULL
#include <iostream>
using namespace std;

struct buah {
    string nama;
    int jumlah;
    float harga;
};

typedef buah dataBuah;
typedef struct node *address;

struct node {
    dataBuah isidata;
    address next;
};

struct linkedlist {
    address first;
};

// ==== DEKLARASI / PROTOTYPE ====
bool isEmpty(linkedlist List);
void createList(linkedlist &List);

address alokasi(string nama, int jumlah, float harga);
void dealokasi(address &node);

void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);

void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);

void printList(linkedlist List);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

// === Fungsi update data ===
void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address nodePrev);

#endif
```

c. main.cpp
```go
#include "listBuah.h"

#include <iostream>
using namespace std;

int main() {
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataBuah dtBuah;

    nodeA = alokasi("Jeruk", 100, 3000);
    nodeB = alokasi("Apel", 75, 4000);
    nodeC = alokasi("Pir", 87, 5000);
    nodeD = alokasi("Semangka", 43, 11500);
    nodeE = alokasi("Durian", 15, 31450);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout <<"--- ISI LIST SETELAH DILAKUKAN INSERT---" << endl;
    printList(List);
    cout <<"jumlah node:" << nbList(List) << endl;
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateAfter(List, nodeD);

    cout <<"--- ISI LIST SETELAH DILAKUKAN UPDATE---" << endl;
    printList(List);
    cout << "jumlah node:" << nbList(List) << endl;
    cout << endl;

    return 0;

}
```
Program ini mengimplementasikan struktur data linked list untuk mengelola daftar buah dengan informasi nama, jumlah, dan harga. Program terdiri dari beberapa bagian. Pertama, mendeklarasikan dan membuat linked list kosong, kemudian menambahkan node baru ke dalam list menggunakan operasi seperti insertFirst, insertLast, dan insertAfter. Selanjutnya, program menyediakan prosedur untuk menghapus node (delFirst, delLast, delAfter) dan memperbarui data pada node tertentu (updateFirst, updateLast, updateAfter). Akhirnya, data dalam list ditampilkan menggunakan printList dan jumlah node dihitung menggunakan nbList. Program ini juga memungkinkan pengguna untuk memperbarui data buah yang ada di list dan menampilkan perubahan tersebut.
### 2. Guided 2 
```C++
	#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void append(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};
    if (!head) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }
}

// Fungsi untuk mencari node tengah antara start dan end
Node* getMiddle(Node* start, Node* end) {
    if (start == nullptr) return nullptr;
    Node* slow = start;
    Node* fast = start->next;

    while (fast != end) {
        fast = fast->next;
        if (fast != end) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    return slow;
}

// Binary Search di linked list yang terurut
Node* binarySearch(Node* head, int key) {
    Node* start = head;
    Node* end = nullptr;

    do {
        Node* mid = getMiddle(start, end);
        if (mid == nullptr) return nullptr;

        if (mid->data == key)
            return mid;
        else if (mid->data < key)
            start = mid->next;
        else
            end = mid;
    } while (end == nullptr || end != start);

    return nullptr;
}

int main() {
    Node* head = nullptr;
    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);

    Node* result = binarySearch(head, 50);
    cout << (result ? "Found" : "Not Found") << endl;

    return 0;
}
```
Program ini mengimplementasikan pencarian binary pada linked list terurut. Dimulai dengan mendeklarasikan struktur Node dan fungsi append untuk menambahkan nilai ke list. Fungsi getMiddle mencari node tengah untuk digunakan dalam binary search. Fungsi binarySearch mencari nilai tertentu dengan membagi list menggunakan node tengah hingga menemukan nilai yang dicari. Pada main, program menambahkan nilai ke linked list dan mencari nilai 50, kemudian mencetak hasil pencarian.
### 3. Guided 3
```c++
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node*linearSearch(Node* head, int key) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == key)
            return current;
        current = current->next;
    }
    return nullptr;
}
void append(Node* &head, int value) {
    Node* newNode = new Node{value, nullptr};
    if (!head) head = newNode;
    else {
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }
}
int main() {
    Node* head = nullptr;
    append(head, 10); append(head, 20); append(head, 30);
    Node* result = linearSearch(head, 30);

    cout << (result ? "Found" : "Not Found") << endl;
    return 0;  
}
```
Program ini mengimplementasikan pencarian linear pada linked list. Dimulai dengan mendeklarasikan struktur Node yang berisi data dan pointer next ke node berikutnya. Fungsi linearSearch mencari nilai dalam list dengan memeriksa setiap node satu per satu hingga nilai ditemukan atau list berakhir. Fungsi append digunakan untuk menambahkan nilai ke dalam linked list. Pada main, program menambahkan beberapa nilai ke linked list dan mencari nilai 30 menggunakan linearSearch, lalu mencetak apakah nilai tersebut ditemukan atau tidak.
## Unguided 

### 1. Tugas 1

```C++
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void append(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};
    if (!head) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }
}

Node* getMiddle(Node* start, Node* end) {
    if (start == nullptr) return nullptr;
    Node* slow = start;
    Node* fast = start;

    while (fast != end && fast->next != end) {
        slow = slow->next; 
        fast = fast->next->next;
    }
    return slow;
}

Node* binarySearch(Node* head, int key) {
    Node* start = head;
    Node* end = nullptr;
    int iter = 1;

    cout << "\nProses Pencarian:\n";

    while (start != end && start != nullptr) {
        Node* mid = getMiddle(start, end);
        if (!mid) break;

        cout << "Iterasi " << iter++ << ": Mid = " << mid->data << " (indeks tengah)";

        if (mid->data == key) {
            cout << " -> DITEMUKAN!\n";
            cout << "\nHasil: Nilai " << key << " DITEMUKAN pada linked list!\n";
            cout << "Alamat node : " << mid << endl;
            cout << "Data node   : " << mid->data << endl;
            if (mid->next)
                cout << "Node berikutnya : " << mid->next->data << endl;
            else
                cout << "Node berikutnya : NULL\n";
            return mid;
        }

        else if (mid->data < key) {
            cout << " -> Cari di bagian kanan\n";
            start = mid->next;
        }

        else {
            cout << " -> Cari di bagian kiri\n";
            end = mid;
        }

        if (start == end || (start && start->next == end))
            break;
    }

    cout << "Tidak ada elemen tersisa\n";
    cout << "\nHasil: Nilai " << key << " TIDAK DITEMUKAN dalam linked list!\n";
    return nullptr;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data;
        if (temp->next) cout << " -> ";
        temp = temp->next;
    }
    cout << " -> NULL\n";
}

int main() {
    Node* head = nullptr;
    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);
    append(head, 60);

    cout << "BINARY SEARCH PADA LINKED LIST\n";
    cout << "Linked List yang dibuat: ";
    printList(head);

    cout << "Mencari nilai: " << 40 << endl;
    Node* result = binarySearch(head, 40);
    cout << endl;

    cout << "Mencari nilai: " << 25 << endl;
    result = binarySearch(head, 25);
    return 0;
}
```
### Output Unguided 1 :
![](gambar/gambar_1.png)
Program dimulai dengan membentuk linked list dari beberapa nilai yang sudah terurut, kemudian menggunakan fungsi getMiddle() untuk mencari elemen tengah dari daftar tersebut melalui metode slow-fast pointer. Fungsi binarySearch() kemudian membandingkan nilai tengah dengan data yang dicari (key) dan menentukan apakah pencarian dilanjutkan ke bagian kiri atau kanan list, mirip seperti binary search pada array. Setiap langkah pencarian ditampilkan di layar agar proses dapat dipantau. Hasil akhir menunjukkan apakah nilai yang dicari ditemukan atau tidak dalam linked list.

### 2. Tugas 2

```C++
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void append(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};
    if (!head) head = newNode;
    else {
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }
}

void printList(Node* head) {
    cout << "Linked List yang dibuat: ";
    Node* temp = head;
    while (temp) {
        cout << temp->data;
        if (temp->next) cout << " -> ";
        temp = temp->next;
    }
    cout << " -> NULL" << endl;
}

Node* linearSearch(Node* head, int key) {
    Node* current = head;
    int i = 1;
    cout << "\nProses Pencarian:\n";
    while (current != nullptr) {
        cout << "Memeriksa node " << i << ": " << current->data;
        if (current->data == key) {
            cout << " (SAMA) - DITEMUKAN!\n";
            return current;
        } else {
            cout << " (tidak sama)\n";
        }
        current = current->next;
        i++;
    }
    cout << "Tidak ada node lagi yang tersisa\n";
    return nullptr;
}

int main() {
    cout << "LINEAR SEARCH PADA LINKED LIST\n";

    Node* head = nullptr;
    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);

    printList(head);

    int key = 30;
    cout << "Mencari nilai: " << key << endl;
    Node* result = linearSearch(head, key);

    if (result) {
        cout << "\nHasil: Nilai " << key << " DITEMUKAN pada linked list!\n";
        cout << "Alamat node: " << result << endl;
        cout << "Data node: " << result->data << endl;
        if (result->next)
            cout << "Node berikutnya: " << result->next->data << endl;
        else
            cout << "Node berikutnya: NULL\n";
    } else {
        cout << "\nHasil: Nilai " << key << " TIDAK DITEMUKAN dalam linked list!\n";
    }

    key = 25;
    cout << "Mencari nilai: " << key << endl;
    result = linearSearch(head, key);

    if (result) {
        cout << "\nHasil: Nilai " << key << " DITEMUKAN pada linked list!\n";
        cout << "Alamat node: " << result << endl;
        cout << "Data node: " << result->data << endl;
        if (result->next)
            cout << "Node berikutnya: " << result->next->data << endl;
        else
            cout << "Node berikutnya: NULL\n";
    } else {
        cout << "\nHasil: Nilai " << key << " TIDAK DITEMUKAN dalam linked list!\n";
    }

    return 0;
}
```
### Output Unguided 2 :
![](gambar/gambar_2.png)
Terdapat fungsi append() yang digunakan untuk menambahkan elemen baru di akhir list, sedangkan printList() digunakan untuk menampilkan seluruh isi linked list dalam urutan. Proses pencarian dilakukan melalui fungsi linearSearch(), yaitu memeriksa setiap node secara berurutan mulai dari kepala list hingga node terakhir untuk mencari nilai yang sesuai dengan key. Jika data ditemukan, maka akan menampilkan alamat node, nilai data, serta node berikutnya. Jika tidak ditemukan, akan memberikan pesan bahwa nilai tidak ada dalam list. Pada fungsi main(), program membuat linked list dengan elemen 10, 20, 30, 40, dan 50, terus melakukan pencarian untuk nilai 30 (ditemukan) dan 25 (tidak ditemukan).
## Kesimpulan
Penerapan Linear Search dan Binary Search pada linked list menunjukkan perbedaan saat pencarian. Linear Search mudah diterapkan karena tidak membutuhkan data terurut, namun kurang efisien pada data berukuran besar, sedangkan Binary Search lebih cepat tetapi hanya dapat digunakan pada linked list yang telah terurut.

## Referensi
[1] Imamah, N., & Bahari, M. I. (2021). Perbandingan Algoritma Sequential Search dan Binary Search pada Aplikasi Kamus Bahasa Indonesia Menggunakan PHP dan jQuery. Jurnal Informatika – COMPUTING, 8(1), 1–6. Diakses pada 26 Oktober 2025 melalui https://ejournal.unibba.ac.id/index.php/computing/article/view/564/468
<br>[2] Pratama, Muhammad Akbar. (2020). Analisis Perbandingan Algoritma Linear dan Binary pada Aplikasi Kamus Bahasa Indonesia-Jawa. Repository UIN Syarif Hidayatullah Jakarta. Diakses pada 26 Oktober 2025 melalui https://repository.uinjkt.ac.id/dspace/bitstream/123456789/53846/1/MUHAMMAD%20AKBAR%20PRATAMA-FST.pdf
