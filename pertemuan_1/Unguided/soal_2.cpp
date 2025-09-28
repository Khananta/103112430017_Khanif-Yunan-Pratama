#include <iostream>
#include <string>
using namespace std;

int main() {
    int angka;
    cout << "Masukkan angka (0-100): ";
    cin >> angka;

    string satuan[] = {"nol", "satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan"};
    string puluhan[] = {"sepuluh", "sebelas", "dua belas", "tiga belas", "empat belas", "lima belas", "enam belas", "tujuh belas", "delapan belas", "sembilan belas"};
    string puluhanKata[] = {"", "", "dua puluh", "tiga puluh", "empat puluh", "lima puluh", "enam puluh", "tujuh puluh", "delapan puluh", "sembilan puluh"};

    if (angka >= 0 && angka <= 9) {
        cout << satuan[angka] << endl;
    }
    else if (angka >= 10 && angka <= 19) {
        cout << puluhan[angka - 10] << endl;
    }
    else if (angka >= 20 && angka <= 99) {
        int puluh = angka / 10;
        int satu = angka % 10;
        if (satu == 0) cout << puluhanKata[puluh] << endl;
        else cout << puluhanKata[puluh] << " " << satuan[satu] << endl;
    }
    else if (angka == 100) {
        cout << angka << " seratus" << endl;
    }
    else {
        cout << "Invalid, inputan harus di antara 0-100" << endl;
    }

    return 0;
}