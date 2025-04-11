#include <iostream>
using namespace std;

struct Alamat 
{
    string jalan;
    string kota;
};

struct Mahasiswa 
{
    string nama;
    string nim;
    float ipk;
    Alamat alamat;
};

#DEFINE MAX_MAHASISWA 5

int main() 
{
    int panjang = 0;

    Mahasiswa mhs[MAX_MAHASISWA]
    int pilihan;

    mhs1.nama = "Dimas"
    mhs1.nim = "2468";
    mhs1.prodi = "Infornatika":
    mhs1.ipk = 4.1;
    mhs1.angkatan = 2024;

    for (int i = 0; i < 2; i++)

    cout << "Nama\t: " << mhs[i].nama << endl; 
    cout << "NIM\t: " << mhs[i].nim << endt;
    cout << "Prodi\t:" << mhs[i].prodi « endi;
    cout << "IPK\t: " << mhs[i].ipk << endl;
    cout << "Jalan\t: " << mhs[i].alamat.jalan << end;
    cout << "Kota\t: " << mhs[i].alamat.kota << end;
}

int main()
{
    int pilihan;

    do
    {
        cout << "Menu Program" << endl;
        cout << "1. Tampilkan Data" << endl;
        cout << "2. Tambah Data" << endl;
        cout << "3. Ubah Data" << endl;
        cout << "4. Hapus Data" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
        if (panjang = )
        cout << "belum ada data" << endl;
        else {
            cout << "Data Mahasiswa" << endl;
            for (int i=0; i < panjang; i++) {
                cout << "Nama\t: " << mhs[i].nama << endl; 
                cout << "NIM\t: " << mhs[i].nin << endt;
                cout << "Prodi\t:" << mhs[i].prodi « endi;
                cout << "IPK\t: " << mhs[i].ipk << endl;
                cout << "Jalan\t: " << mhs[i].alamat.jalan << end;
                cout << "Kota\t: " << mhs[i].alamat.kota << end;
            }
        }
            break;

        case 2:
        if (panjang < MAX_MAHASISWA)
        {
            cout << "Masukan Nama : ";
            cin.ignore ();
            getline(cin, mhs[panjang].nama);

            cout << "Masukan NIM : ";
            cin.ignore ();
            getline(cin, mhs[panjang].nim);

            cout << "Masukan IPK : ";
            getline(cin, mhs[panjang].ipk);

            cout << "Masukan Jalan : ";
            cin.ignore ();
            getline(cin, mhs[panjang].jalan);

            cout << "Masukan Kota : ";
            cin.ignore ();
            getline(cin, mhs[panjang].kota); 

            panjang++;
            cout << "Mahasiswa berhail ditambahkan" << end;
        }

            break;

        case 3:
            break;

        case 4:
            cout << "Daftar Mahasiswa" << endl;
            for (int i = 0; i < panjang; i++)
            {
                cout << i + 1 << ". Nama\t: " << mhs[i].nama << endl;
            }

            int index;
            cout "Masukkan nomor mahasiswa yang inginn dihapus : "
            cin >> index
            for  (int i = index -1; i < pannjan - 1)
            break;
        case 5:
            cout << "Program selesai" << endl;
            break;
        default:
            cout << "Pilihan tidak valid" << endl;
            break;
        }
    } while (pilihan != 5);
}