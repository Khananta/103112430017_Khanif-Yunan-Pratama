# <h1 align="center">Laporan Praktikum Modul 3 - ABSTRACT DATA TYPE (ADT)</h1>
<p align="center">Khanif Yunan Pratama - 103112430017</p>

## Dasar Teori
Abstract Data Type(ADT) adalah tipe data yang hanya bisa di definisikan oleh operasi yang dapat dilakukan oleh data tersebut, tanpa menjelaskan cara mengimplementasikannya. Perumpamaannya adalah ketika kita di restoran, kita bisa memilih menu, memesan menu, dan sebagainya. Tetapi ketika sudah memilih menu, kita tidak diberi tahu cara memasak menu tersebut. Proses yang dilakukan akan di sembunyikan.

Dijelaskan bahwa ADT merupakan sebuah model matematika yang merujuk pada sejumlah data yang memiliki kegunaan atau perilaku yang sama[1]. Salah satu manfaat penggunaan ADT adalah kemudahan dalam pemeliharaan dan pengembangan kode, kemudian kerahasiaan kode lebih terjaga. Selain itu pastinya kode menjadi lebih terstruktur. 

Walaupun kesannya hampir sama dengan OOP, ternyata ADT berbeda dengan OOP. Operasi yang dilakukan ADT lebih terbatas. Pada ADT akan dikelompokan mana data yang bisa kelompokan. Maka user tidak akan mengakses objek dari type secara langsung[2].

## Guided 

### 1. mahasiswa.h

```C++
#ifndef MAHASISWA_H
#define MAHASISWA_H

struct mahasiswa {
    char nim[10];
    int nilai1, nilai2;
};

void inputMhs(mahasiswa &m);
float rata2(mahasiswa m);

#endif
```
Program mahasiswa.h ini adalah salah satu bagian dari beberapa bagian program mahasiswa. Nah program mahasiswa.h digunakan untuk mendeklarasikan sebuah tipe data bentukan yaitu mahasiswa yang isinya adalah NIM dan Nilai. Kemudian program meminta agar memasukan data mahasiswa kemudian menampilkan rata-ratanya.
### 2. mahasiswa.cpp

```C++
#include <iostream>
#include "mahasiswa.h"

using namespace std;

void inputMhs(mahasiswa &m) {
    cout << "Input NIM: "; 
    cin >> m.nim;
    cout << "Input Nilai 1: "; 
    cin >> m.nilai1;
    cout << "Input Nilai 2: "; 
    cin >> m.nilai2;
}

float rata2(mahasiswa m) {
    return (float)(m.nilai1 + m.nilai2) / 2;
}
```
Kemudian ini masih terkait code sebelumnya, bedanya ini berisikan fungsi dan prosedur yang digunakan/dipanggil sebelumnya. Terdapat prosedur inputMhs untuk input NIM, Nilai 1, dan Nilai 2. Kemudian terdapat fungsi rata2 yaitu untuk menghitung nilai rata-rata yang telah dimasukan. 

### 3. main.cpp

```C++
#include <iostream>
#include "mahasiswa.h"
#include <cstdlib>

using namespace std;

int main() {
    mahasiswa mhs;

    inputMhs(mhs);

    cout << "Rata-rata nilai adalah: " << rata2(mhs) << endl;

    system("pause");
    return 0;
}
```
Terakhir ini merupakan program utama, yaitu digunakan untuk memanggil/menjalankan seluruh proses yang sudah dibuat. Di program ini menggabungkan semua fungsionalitas yang telah di buat pada beberapa program sebelumnya. 
### 4. struct.cpp

```C++
#include <iostream>
using namespace std;

struct mahasiswa {
    char nim[10];
    int nilai1, nilai2;
};

void inputMhs(mahasiswa &m) {
    cout << "Input NIM: "; 
    cin >> m.nim;
    cout << "Input Nilai 1: "; 
    cin >> m.nilai1;
    cout << "Input Nilai 2: "; 
    cin >> m.nilai2;
}

float rata2(mahasiswa m) {
    return (float)(m.nilai1 + m.nilai2) / 2;
}

int main() {
    mahasiswa mhs;
    inputMhs(mhs);
    cout << "Rata-rata nilai adalah: " << rata2(mhs) << endl;
    system("pause");
    return 0;
}
```
Program ini digunakan untuk mengelola data mahasiswa, termasuk memasukkan nilai dan menghitung rata-rata nilai. Program ini memiliki struktur data mahasiswa yang menyimpan NIM dan dua nilai mahasiswa. Fungsi inputMhs digunakan untuk meminta input NIM dan nilai mahasiswa, sedangkan fungsi rata2 digunakan untuk menghitung rata-rata dari kedua nilai yang dimasukkan. Sebenarnya ini sama seperti code sebelumnya, bedanya ini digabung dalam satu file program.

## Unguided 

### 1. Buat program yang dapat menyimpan data mahasiswa (max. 10) ke dalam sebuah array dengan field nama, nim, uts, uas, tugas, dan nilai akhir. Nilai akhir diperoleh dari FUNGSI dengan rumus 0.3*uts+0.4*uas+0.3*tugas.


```C++
#include <iostream>
using namespace std;

struct mahasiswa {
    string nama;
    int nim;
    float uts;
    float uas;
    float tugas;
    float nilaiAkhir;
};

int rumus(float uts, float uas, float tugas) {
    return (0.3 * uts) + (0.4 * uas) + (0.3 * tugas);
}

void input(mahasiswa mhs[], int jumlah) {
    for (int i = 0; i < jumlah; i++) {
        cout << "\nMahasiswa ke-" << i + 1 << endl;
        cout << "Nama: ";
        cin >> mhs[i].nama;

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
```
### Output
##### Output 1
![](gambar_1.png)
#### Output 2
![](gambar/gambar_2.png)
Program ini berfungsi untuk menginput dan menampilkan data maksimal 10 mahasiswa, yang terdiri dari nama, NIM, nilai UTS, UAS, dan tugas. Setiap nilai yang dimasukkan akan diolah menggunakan rumus perhitungan nilai akhir yaitu 0.3 × UTS + 0.4 × UAS + 0.3 × Tugas. Selain itu, program juga membatasi jumlah input agar tidak kurang dari 1 dan tidak lebih dari 10 mahasiswa. 
### 2. Membuat ADT
Buatlah ADT pelajaran sebagai berikut di dalam file "pelajaran.h":
```
Type pelajaran <
	namaMapel : string 
	kodeMapel : string
function create_pelajaran( 
	namapel : string, 
	kodepel: string ) → pelajaran
procedure tampil_pelajaran( input pel: pelajaran
```

Buatlah implementasi ADT pelajaran pada file "pelajaran.cpp" Cobalah hasil implementasi ADT pada file "main.cpp"
```
using namespace std; int main() { 
	string namapel = "Struktur Data"; 
	string kodepel = "STD"; 
	pelajaran pel = create_pelajaran (namapel,kodepel); 
	tampil_pelajaran(pel); 
	return 0; 
}
```

#### Berikut beberapa code dari penerapan ADT

pelajaran.h
```C++
#ifndef PELAJARAN_H
#define PELAJARAN_H
#include <string>

using namespace std;

struct pelajaran {
    string namapel;
    string kodepel;
};


pelajaran create_pelajaran(string namapel, string kodepel);
void tampil_pelajaran(pelajaran pel);

#endif2
```

pelajaran.cpp
```C++
#include <iostream>
#include "pelajaran.h"

using namespace std;

pelajaran create_pelajaran(string namapel, string kodepel) {
    pelajaran pel;
    pel.namapel = namapel;
    pel.kodepel = kodepel;
    return pel;
}

void tampil_pelajaran(pelajaran pel) {
    cout << "nama pelajaran : " << pel.namapel << endl;
    cout << "nilai : " << pel.kodepel << endl;
}
```

main.cpp
```C++
#include <iostream>
#include "pelajaran.h"
#include <cstdlib>

int main() {
    string namapel = "Struktur Data";
    string kodepel = "STD";
    pelajaran pel = create_pelajaran(namapel, kodepel);
    tampil_pelajaran(pel);

    return 0;
}
```
### Output Unguided :
![](gambar/gambar_3.png)
Program di atas merupakan contoh penerapan Abstract Data Type dalam C++ yang digunakan untuk mengelola data pelajaran. Struktur pelajaran memiliki dua atribut, yaitu namapel dan kodepel. Fungsi create_pelajaran() digunakan untuk membuat data pelajaran baru dengan nilai yang ditentukan, sedangkan tampil_pelajaran() berfungsi menampilkan data tersebut ke layar. Program utama (main.cpp) menggunakan kedua fungsi untuk membuat dan menampilkan data pelajaran "Struktur Data" dengan kode "STD".
### 3. Program Array
Buatlah program dengan ketentuan : 
- 2 buah array 2D integer berukuran 3x3 dan 2 buah pointer integer 
- fungsi/prosedur yang menampilkan isi sebuah array integer 2D 
- fungsi/prosedur yang akan menukarkan isi dari 2 array integer 2D pada posisi tertentu
- fungsi/prosedur yang akan menukarkan isi dari variabel yang ditunjuk oleh 2 buah pointer

```C++
#include <iostream>
using namespace std;

void tampilkanArray(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void tukarPosisi(int arr1[3][3], int arr2[3][3], int x1, int y1, int x2, int y2) {
    int temp = arr1[x1][y1];
    arr1[x1][y1] = arr2[x2][y2];
    arr2[x2][y2] = temp;
}

void tukarPointer(int* ptr1, int* ptr2) {
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

int main() {
    int array1[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int array2[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    
    cout << "Array 1 sebelum ditukar:" << endl;
    tampilkanArray(array1);

    cout << "Array 2 sebelum ditukar:" << endl;
    tampilkanArray(array2);

    tukarPosisi(array1, array2, 0, 0, 2, 2);

    cout << "\nArray 1 setelah ditukar:" << endl;
    tampilkanArray(array1);

    cout << "Array 2 setelah ditukar:" << endl;
    tampilkanArray(array2);

    int a = 10, b = 20;
    int* ptr1 = &a;
    int* ptr2 = &b;

    cout << "\nNilai sebelum ditukar: a = " << a << ", b = " << b << endl;
    tukarPointer(ptr1, ptr2);

    cout << "Nilai setelah ditukar: a = " << a << ", b = " << b << endl;

    return 0;
}
```
### Output Unguided 3 :
![](gambar_4.png)
Program di atas merupakan program array 2 dimensi dan pointer dalam C++. Program ini menggunakan dua array 3x3 dan dua pointer integer. Fungsi tampilkanArray() digunakan untuk menampilkan isi array ke layar. Fungsi tukarPosisi() berfungsi untuk menukarkan elemen pada posisi tertentu antara dua array, sedangkan fungsi tukarPointer() digunakan untuk menukarkan nilai dari dua variabel yang ditunjuk oleh pointer. Pada fungsi main(), dua array digunakan dan ditampilkan sebelum dan sesudah penukaran elemen dilakukan. Selain itu, dua variabel a dan b juga ditukar nilainya menggunakan pointer.
## Kesimpulan
Kesimpulannya adalah dala ADT akan dilakukan pemecahan, program akan dipisah menjadi beberapa bagian. Perlu digaris bawahi bahwa ADT berbeda dengan OOP. ADT mempermudah dalam pengembangan program. 

## Referensi
[1] Nugraha, Muhammad Rizky. (2023). "ABSTRACT DATA TYPE". Diakses pada 12 Oktober 2025 melalui https://id.scribd.com/document/683914578/Makalah-Abstrak-Data-Type. 
<br>[2] Binusian. (2016). "TIPE DATA ABSTRAK JAVA".  Diakses pada 12 Oktober 2025 melalui https://allofbzbz.blog.binusian.org/2016/12/14/tipe-data-abstrak-java/.
