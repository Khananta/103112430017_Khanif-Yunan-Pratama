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

Node* binarySearch(Node* head, int key) {
    Node* start = head;
    Node* end = nullptr;
    int iteration = 1;

    while (end == nullptr || end != start) {
        Node* mid = getMiddle(start, end);
        if (mid == nullptr) return nullptr;

        cout << "Iterasi " << iteration << ": Mid = " << mid->data << " (indeks tengah) ";
        
        if (mid->data == key) {
            cout << "- DITEMUKAN!" << endl;
            return mid;
        } else if (mid->data < key) {
            cout << "-> Cari di bagian kanan" << endl;
            start = mid->next;
        } else {
            cout << "-> Cari di bagian kiri" << endl;
            end = mid;
        }

        iteration++;
    }

    cout << "Tidak ada elemen tersisa" << endl;
    return nullptr;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void hasil(Node* head, int value) {
    cout << "Mencari nilai " << value << ":" << endl;
    cout << "\nProses Pencarian:" << endl;
    Node* result = binarySearch(head, value);
    if (result) {
        cout << "\nHasil: Nilai " << value << " DITEMUKAN pada linked list!" << endl;
        cout << "Alamat node: " << result << endl;
        cout << "Data node: " << result->data << endl;
        if (result->next)
            cout << "Node berikutnya: " << result->next->data << endl;
        else
            cout << "Tidak ada node berikutnya." << endl;
    } else {
        cout << "\nHasil: Nilai " << value << " TIDAK DITEMUKAN dalam linked list!" << endl;
    }
}

int main() {
    Node* head = nullptr;

    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);
    append(head, 60);

    cout << "BINARY SEARCH PADA LINKED LIST";
    cout << "Linked List yang dibuat: ";
    printList(head);

    hasil(head, 40);
    hasil(head, 25);

    return 0;
}