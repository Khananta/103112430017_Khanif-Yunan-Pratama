#include<iostream>
using namespace std;

void luasPersegiPanjang(int* ptrPanjang, int* ptrLebar, int* luas) {
    *luas = (*ptrPanjang) * (*ptrLebar);
}

void kelilingPersegiPanjang(int* ptrPanjang, int* ptrLebar, int* keliling) {
    *keliling = 2 * ((*ptrPanjang) + (*ptrLebar));
}

int main() {
    int panjang, lebar, luas, keliling;
    
    panjang = 10;
    lebar = 5;
    luas = 0;
    keliling = 0;

    int* ptrPanjang = &panjang;
    int* ptrLebar = &lebar;

    cout << "--- Nilai Awal ---" << endl;
    cout << "Panjang : " << panjang << endl;
    cout << "Lebar : " << lebar << endl;

    luasPersegiPanjang(ptrPanjang, ptrLebar, &luas);
    kelilingPersegiPanjang(ptrPanjang, ptrLebar, &keliling);

    cout << endl;
    cout << "--- Hasil Perhitungan ---" << endl;
    cout << "Luas Persegi Panjang : " << luas << endl;
    cout << "Keliling Persegi Panjang : " << keliling << endl;

    *ptrPanjang = 12;
    *ptrLebar = 6;

    luasPersegiPanjang(ptrPanjang, ptrLebar, &luas);
    kelilingPersegiPanjang(ptrPanjang, ptrLebar, &keliling);

    cout << endl;
    cout << "--- Nilai Setelah Diubah Melalui Pointer ---" << endl;
    cout << "Panjang Baru : " << panjang << endl;
    cout << "Lebar Baru : " << lebar << endl;
    cout << "Luas Baru : " << luas << endl;
    cout << "Keliling Baru : " << keliling << endl;
    
    return 0;
}