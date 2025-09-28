#include<iostream>
using namespace std;

int main() {
    int angka;
    cout << "Masukan angka : ";
    cin >> angka;

    for (int i = 0; i < angka; i++) {
        cout << i << " - ";
    }

    cout << endl;

    int j = 10;
    while (j > angka) {
        cout << j << " - ";
        j--;
    }

    cout << endl;

    int k = 10;
    do {
        cout << k << " - ";
    } while (k < angka);

    return 0;
}