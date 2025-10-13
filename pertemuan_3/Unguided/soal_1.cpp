#include <iostream>
using namespace std;

struct mahasiswa {
    string nama;
    string nim;
    float uts;
    float uas;
    float tugas;
    float nilaiAkhir;
};

float rumus(float uts, float uas, float tugas) {
    return (0.3 * uts) + (0.4 * uas) + (0.3 * tugas);
}

void input(mahasiswa mhs[], int jumlah) {
    for (int i = 0; i < jumlah; i++) {
        cout << "\nMahasiswa ke-" << i + 1 << endl;
        
        cin.ignore();
        cout << "Nama: ";
        getline(cin, mhs[i].nama);

        cout << "NIM: ";
        cin >> mhs[i].nim;
            
        cout << "Nilai UTS: ";
        cin >> mhs[i].uts;
            
        cout << "Nilai UAS: ";
        cin >> mhs[i].uas;

        cout << "Nilai Tugas: ";
        cin >> mhs[i].tugas;
            
        mhs[i].nilaiAkhir = rumus(mhs[i].uts, mhs[i].uas, mhs[i].tugas);
    }
}

void tampilkanData(mahasiswa mhs[], int jumlah) {
    for (int i = 0; i < jumlah; i++) {
        cout << "\nData Mahasiswa ke-" << i + 1 << endl;
        cout << "Nama: " << mhs[i].nama << endl;
        cout << "NIM: " << mhs[i].nim << endl;
        cout << "Nilai UTS: " << mhs[i].uts << endl;
        cout << "Nilai UAS: " << mhs[i].uas << endl;
        cout << "Nilai Tugas: " << mhs[i].tugas << endl;
        cout << "Nilai Akhir: " << mhs[i].nilaiAkhir << endl;
    }
}

int main() {
    int jumlah;
    mahasiswa mhs[10];

    cout << "Masukkan jumlah mahasiswa: ";
    cin >> jumlah;

    if (jumlah >= 1 && jumlah <= 10) {
        input(mhs, jumlah);
        tampilkanData(mhs, jumlah);
    } else {
        cout << "Jumlah mahasiswa harus antara 1 sampai 10" << endl;
    }

    return 0;
}