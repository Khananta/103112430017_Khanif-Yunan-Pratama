#include<iostream>
using namespace std;

void jumlahMatriks(int matriksA[3][3], int matriksB[3][3], int matriksHasil[3][3]) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            matriksHasil[i][j] = matriksA[i][j] + matriksB[i][j];
        }
    }
}

void kurangMatriks(int matriksA[3][3], int matriksB[3][3], int matriksHasil[3][3]) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            matriksHasil[i][j] = matriksA[i][j] - matriksB[i][j];
        }
    }
}

void kaliMatriks(int matriksA[3][3], int matriksB[3][3], int matriksHasil[3][3]) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            matriksHasil[i][j] = 0; 
            for (int k = 0; k < 3; k++) {
                matriksHasil[i][j] += matriksA[i][k] * matriksB[k][j];
            }
        }
    }
}

void tampilkanHasil(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void pilihan() {
    cout << "Menu Operasi Matriks" << endl;
    cout << "1. Penjumlahan matriks" << endl;
    cout << "2. Pengurangan matriks" << endl;
    cout << "3. Perkalian matriks" << endl;
    cout << "4. Keluar" << endl;
}

int main() {
    int matriksA[3][3] = { 
        {7, 12, 22}, 
        {31, 6, 41}, 
        {15, 19, 36} 
    };
    
    int matriksB[3][3] = { 
        {11, 34, 7}, 
        {3, 25, 41}, 
        {5, 18, 33} };
    int matriksHasil[3][3] = {0};
    
    int menu;
    
    do {
        pilihan();
        cout << "Masukan pilihan: "; 
        cin >> menu;
        
        switch (menu) {
        case 1:
            jumlahMatriks(matriksA, matriksB, matriksHasil);
            cout << endl;
            cout << "Hasil Penjumlahan Matriks: " << endl;
            tampilkanHasil(matriksHasil);
            cout << endl;
            break;
        case 2:
            kurangMatriks(matriksA, matriksB, matriksHasil);
            cout << endl;
            cout << "Hasil Pengurangan Matriks: " << endl;
            tampilkanHasil(matriksHasil);
            cout << endl;
            break;
        case 3:
            kaliMatriks(matriksA, matriksB, matriksHasil);
            cout << endl;
            cout << "Hasil Perkalian Matriks: " << endl;
            tampilkanHasil(matriksHasil);
            cout << endl;
            break;
        case 4:
            cout << endl;
            cout << "-------- Keluar dari program --------" << endl;
            break;
        default:
            cout << endl;
            cout << "Pilihan tidak ada di menu!" << endl;
    }
    } while(menu != 4);

    return 0;
}