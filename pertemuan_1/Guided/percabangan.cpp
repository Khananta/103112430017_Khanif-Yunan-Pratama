#include<iostream>
using namespace std;

int main () {
    int angka1, angka2;
    cout << "Masukkan angka 1: ";
    cin >> angka1;
    
    cout << "Masukan angka 2: ";
    cin >> angka2;

    if (angka1 == angka2) {
        cout << angka1 << " sama dengan " << angka2 << endl; 
    } else if (angka1 < angka2) {
        cout << angka1 << " lebih kecil dari " << angka2 << endl;
    } else if (angka1 > angka2) {
        cout << angka1 << " lebih besar dari " << angka2 << endl;
    }

    int pilihan;
    cout << "\nMenu Artimatika" << endl;
    cout << "1. Penjumlahan" << endl;
    cout << "2. Pengurangan" << endl;
    cout << "3. Perkalian" << endl;
    cout << "4. Pembagian" << endl;
    cout << "Masukan pilihan (1/2/3):";
    cin >> pilihan;

    switch(pilihan) {
        case 1:
            cout << "Hasil dari penjumlahan: " << angka1 << "+" << angka2 << "=" << angka1 + angka2 << endl;
            break;
        case 2:
            cout << "Hasil dari pengurangan: " << angka1 << "-" << angka2 << "=" << angka1 - angka2 << endl;
            break;
        case 3:
            cout << "Hasil dari perkalian: " << angka1 << "*" << angka2 << "=" << angka1 * angka2 << endl;
            break;
        case 4:
            cout << "Hasil dari pembagian: " << angka1 << "/" << angka2 << "=" << angka1 / angka2 << endl;
            break;
        default:
            cout << "Pilihan tidak ditemukan" << endl;
    }
    
    return 0;
}