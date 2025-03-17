#include <iostream>
using namespace std;

// int main() {
//     string nama[5] = {"Dimas", "Harahap", "Santoso", "Kalingga", "Ucup"};

//     int angka[3];
//     angka[0];
//     angka[1];
//     angka[2];

//     cout << nama[1] << endl;

//     return 0;


    // double angka[5] = {1, 2, 3, 4, 5,};

    // cout << sizeof(angka);

    // int angka[5] = {1, 2, 3, 4, 5};

    // int panjang1 = sizeof(angka) / sizeof(angka[0]);
    // int panjang2 = sizeof(angka) / sizeof(int);

    // cout << "Panjang 1\t: " << panjang1 << endl;
    // cout << "Panjang 2\t: " << panjang2 << endl;

    int angka[5] = {1, 2, 3, 4, 5};
    int panjang1 = sizeof(angka) / sizeof(angka[0]);

    cout << "Array: " << angka << endl;


    for(int i = 0; i <panjang1; i++) {
        cout << angka[i] << endl;
    }

    // for (int i = 0; i < panjang1; i++) {
    //     cout << angka[i] << endl;
    // }

    // cout << angka << endl;
  
    // for(int i = 0; i <panjang1; i++) {
    //     cout << angka[i] << endl;
    // }

    // cout << "Panjang 1\t: " << panjang1 << endl;
    // cout << "Panjang 2\t: " << panjang2 << endl;


    // cout << "Nama\t:" << nama[1] << endl;
    // cout << "Angka\t:" << angka[2] << endl;
}