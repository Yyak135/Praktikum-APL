#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#define MAX_RESERVASI 100

struct Studio 
{
    string namaKelas;
    int hargaPerJam;
};

struct Reservasi 
{
    string nama;
    string nim;
    Studio studio;
    int jam;
    int totalHarga;
};

string tampilkanDaftarStudio();
string tampilkanDaftarStudio(Studio *daftarStudio, string (*alatMusik)[7]);

Reservasi daftarReservasi[MAX_RESERVASI];
int jumlahReservasi = 0;

Studio daftarStudio[2] = { {"Kelas A", 80000}, {"Kelas B", 100000} };
string alatMusik[2][7] = 
{
    {"Drum", "Keyboard", "Gitar Akustik", "Gitar Elektrik", "Bass", "Cajon", "Mic"},
    {"Piano", "Violin", "Celo", "Flute", "Terompet", "Saxofon", "Harpa"}
};

string tampilkanDaftarStudio() 
{
    return tampilkanDaftarStudio(daftarStudio, alatMusik);
}

string tampilkanDaftarStudio(Studio *daftarStudio, string (*alatMusik)[7]) 
{
    string output = "\n==================================================================================================\n";
    output += "| No | Kelas   | Alat Musik                                                      | Harga Per Jam |\n";
    output += "==================================================================================================\n";
    for (int i = 0; i < 2; i++) 
    {
        output += "| " + to_string(i + 1) + "  | " + (*(daftarStudio + i)).namaKelas + " | ";
        for (int j = 0; j < 7; j++) 
        {
            output += *(*(alatMusik + i) + j);
            if (j < 6) output += ", ";
        }
        output += " | Rp " + to_string((*(daftarStudio + i)).hargaPerJam) + "      |\n";
    }
    output += "==================================================================================================\n";
    return output;
}

void tambahReservasiAwal(Reservasi *daftar, int *jumlah, Studio *daftarStudio) 
{
    *(daftar + (*jumlah)++) = {"ipeh", "202101", *(daftarStudio), 3, 3 * daftarStudio[0].hargaPerJam};
    *(daftar + (*jumlah)++) = {"aryo", "202102", *(daftarStudio + 1), 2, 2 * daftarStudio[1].hargaPerJam};
    *(daftar + (*jumlah)++) = {"araa", "202103", *(daftarStudio), 5, 5 * daftarStudio[0].hargaPerJam};
    *(daftar + (*jumlah)++) = {"inun", "202104", *(daftarStudio + 1), 4, 4 * daftarStudio[1].hargaPerJam};
}

void tampilkanReservasiUser(Reservasi daftarReservasi[], int jumlah, string nim, int i = 0, int no = 1, bool ada = false) 
{
    if (i == 0) 
    {
        cout << "\nReservasi Anda:\n";
        cout << "==========================================\n";
        cout << "| No | Kelas   | Jam | Total Harga       |\n";
        cout << "==========================================\n";
    }
    if (i >= jumlah) 
    {
        if (!ada) cout << "|          Tidak ada reservasi           |\n";
        cout << "==========================================\n";
        return;
    }
    if (daftarReservasi[i].nim == nim) 
    {
        cout << "| " << no << "  | " << daftarReservasi[i].studio.namaKelas
             << " |  " << daftarReservasi[i].jam
             << "  | Rp " << daftarReservasi[i].totalHarga << "         |\n";
        tampilkanReservasiUser(daftarReservasi, jumlah, nim, i + 1, no + 1, true);
    } 
    else 
    {
        tampilkanReservasiUser(daftarReservasi, jumlah, nim, i + 1, no, ada);
    }
}

string registrasiUser(string *nama, string *nim) 
{
    cout << "\n--===REGISTRASI USER===--\nMasukkan Nama: ";
    cin.ignore();
    getline(cin, *nama);
    cout << "Masukkan NIM: ";
    getline(cin, *nim);
    return "Registrasi Berhasil!\n\n";
}

string tambahReservasiUser(string nama, string nim, Reservasi *daftar, int *jumlah, Studio *daftarStudio) 
{
    if (*jumlah >= MAX_RESERVASI) return "Reservasi penuh!\n";
    Reservasi r;
    r.nama = nama;
    r.nim = nim;
    cout << tampilkanDaftarStudio();
    int pilihan;
    cout << "Pilih Kelas Studio (1/2): ";
    cin >> pilihan;
    if (pilihan < 1 || pilihan > 2) return "Pilihan tidak valid!\n";
    r.studio = *(daftarStudio + pilihan - 1);
    cout << "Masukkan jumlah jam: ";
    cin >> r.jam;
    r.totalHarga = r.jam * r.studio.hargaPerJam;
    *(daftar + (*jumlah)++) = r;
    return "Reservasi berhasil ditambahkan!\n";
}

string editReservasiUser(string nim, Reservasi daftar[], int jumlah, Studio daftarStudio[]) 
{
    int urutan = 0;
    cout << "\nReservasi Anda:\n";
    cout << "==========================================\n";
    cout << "| No | Kelas   | Jam | Total Harga       |\n";
    cout << "==========================================\n";
    for (int i = 0; i < jumlah; i++) 
    {
        if (daftar[i].nim == nim) 
        {
            urutan++;
            cout << "| " << urutan << "  | " << daftar[i].studio.namaKelas
                 << " |  " << daftar[i].jam
                 << "  | Rp " << daftar[i].totalHarga << "         |\n";
        }
    }
    if (urutan == 0) 
    {
        cout << "|          Tidak ada reservasi           |\n";
        cout << "==========================================\n";
        return "Tidak ada reservasi yang bisa diedit.\n";
    }
    cout << "==========================================\n";
    int no, pilihan, jam;
    cout << "Masukkan nomor reservasi yang akan diedit: ";
    cin >> no;
    urutan = 0;
    for (int i = 0; i < jumlah; i++) 
    {
        if (daftar[i].nim == nim) 
        {
            urutan++;
            if (urutan == no) 
            {
                cout << "\nPilih Kelas Studio Baru:\n";
                cout << "1. Kelas A (Rp " << daftarStudio[0].hargaPerJam << "/jam)\n";
                cout << "2. Kelas B (Rp " << daftarStudio[1].hargaPerJam << "/jam)\n";
                cout << "Pilihan(1/2): ";
                cin >> pilihan;
                if (pilihan < 1 || pilihan > 2) return "Pilihan Tidak Valid!\n";
                daftar[i].studio = daftarStudio[pilihan - 1];
                cout << "Masukkan jumlah jam baru: ";
                cin >> jam;
                daftar[i].jam = jam;
                daftar[i].totalHarga = jam * daftar[i].studio.hargaPerJam;
                return "Reservasi Berhasil Diperbarui!\n";
            }
        }
    }
    return "Reservasi Tidak Ditemukan!\n";
}

void tampilkanReservasiAdmin(Reservasi daftar[], int jumlah) 
{
    cout << "\n=======================================================================\n";
    cout << "| No | Nama                 | NIM       | Kelas   | Jam | Total Harga |\n";
    cout << "=======================================================================\n";
    for (int i = 0; i < jumlah; i++) 
    {
        cout << "| " << i + 1 << "  | " << daftar[i].nama;
        cout << string(21 - daftar[i].nama.length(), ' ') << "|  " << daftar[i].nim
             << "   | " << daftar[i].studio.namaKelas << " |  " << daftar[i].jam
             << "  | Rp " << daftar[i].totalHarga << "   |\n";
    }
    if (jumlah == 0)
        cout << "|                    Tidak Ada Reservasi Saat Ini                     |\n";
    cout << "=======================================================================\n";
}

string hapusReservasiAdmin(Reservasi daftar[], int &jumlah) 
{
    if (jumlah == 0) return "Tidak Ada Reservasi Yang Bisa Dihapus.\n";
    tampilkanReservasiAdmin(daftar, jumlah);
    int index;
    cout << "Masukkan nomor reservasi yang akan dihapus: ";
    cin >> index;
    if (index < 1 || index > jumlah) return "Nomor Reservasi Tidak Valid!\n";
    for (int i = index - 1; i < jumlah - 1; i++)
        daftar[i] = daftar[i + 1];
    jumlah--;
    return "Reservasi Berhasil Dihapus!\n";
}

bool loginAdmin() 
{
    string username, password;
    int kesempatan = 3;
    while (kesempatan > 0) 
    {
        cout << "\n--===LOGIN ADMIN===--\nMasukkan Username: ";
        cin >> username;
        cout << "Masukkan Password: ";
        cin >> password;
        if (username == "tea" && password == "063") return true;
        kesempatan--;
        cout << "Username atau Password Salah!\nSisa kesempatan: " << kesempatan << endl;
    }
    return false;
}

void bubbleSortNama(Reservasi daftar[], int jumlah) 
{
    for (int i = 0; i < jumlah - 1; i++) 
    {
        for (int j = 0; j < jumlah - i - 1; j++) 
        {
            if (daftar[j].nama > daftar[j+1].nama) 
            {
                Reservasi temp = daftar[j];
                daftar[j] = daftar[j+1];
                daftar[j+1] = temp;
            }
        }
    }
}

void insertionSortTotalHargaDesc(Reservasi daftar[], int jumlah) 
{
    for (int i = 1; i < jumlah; i++) 
    {
        Reservasi key = daftar[i];
        int j = i - 1;
        while (j >= 0 && daftar[j].totalHarga < key.totalHarga) 
        {
            daftar[j+1] = daftar[j];
            j--;
        }
        daftar[j+1] = key;
    }
}

void selectionSortJam(Reservasi daftar[], int jumlah) 
{
    for (int i = 0; i < jumlah - 1; i++) 
    {
        int minIdx = i;
        for (int j = i + 1; j < jumlah; j++) 
        {
            if (daftar[j].jam < daftar[minIdx].jam) 
            {
                minIdx = j;
            }
        }
        Reservasi temp = daftar[i];
        daftar[i] = daftar[minIdx];
        daftar[minIdx] = temp;
    }
}

void menuSorting(Reservasi daftar[], int jumlah) 
{
    int pilihSort;
    cout << "\nPilih Metode Sorting:\n";
    cout << "1. Urutkan Berdasarkan Nama\n";
    cout << "2. Urutkan Berdasarkan Total Harga\n";
    cout << "3. Urutkan Berdasarkan Jumlah Jam Reservasi\n";
    cout << "Pilihan: ";
    cin >> pilihSort;
    switch(pilihSort) 
    {
        case 1:
            bubbleSortNama(daftar, jumlah);
            cout << "\nData berhasil diurutkan berdasarkan Nama secara Ascending!\n";
            tampilkanReservasiAdmin(daftar, jumlah);
            break;
        case 2:
            insertionSortTotalHargaDesc(daftar, jumlah);
            cout << "\nData berhasil diurutkan berdasarkan Total Harga secara Descending!\n";
            tampilkanReservasiAdmin(daftar, jumlah);
            break;
        case 3:
            selectionSortJam(daftar, jumlah);
            cout << "\nData berhasil diurutkan berdasarkan Jumlah Jam secara Ascending!\n";
            tampilkanReservasiAdmin(daftar, jumlah);
            break;
        default:
            cout << "\nPilihan tidak valid!\n";
    }
}

int main() 
{
    int pilihan;
    bool isAdmin = false;
    string namaUser, nimUser;
    tambahReservasiAwal(daftarReservasi, &jumlahReservasi, daftarStudio);
    while (true) 
    {
        cout << "\n\nHELLO";
        cout << "\nSelamat Datang di Sistem Reservasi Studio Musik\n";
        cout << "1. Login Admin\n2. Registrasi User\n3. Keluar Program\nPilih: ";
        cin >> pilihan;
        if (pilihan == 1) 
        {
            isAdmin = loginAdmin();
            if (!isAdmin) 
            {
                cout << "Anda Telah Melebihi Batas Percobaan Login!\nPROGRAM BERHENTI.\n";
                return 0;
            }
        } 
        else if (pilihan == 2) 
        {
            cout << registrasiUser(&namaUser, &nimUser);
            isAdmin = false;
        } 
        else if (pilihan == 3) 
        {
            cout << "\nTerima kasih telah menggunakan sistem ini.\n";
            return 0;
        } 
        else 
        {
            cout << "\nPilihan Tidak Valid! Silakan coba lagi.\n\n";
            continue;
        }

        while (true) 
        {
            cout << "\nMENU:\n";
            if (isAdmin) 
            {
                cout << "1. Lihat Semua Reservasi\n2. Hapus Reservasi\n3. Urutkan Reservasi\n4. Logout\n";
            } 
            else 
            {
                cout << "1. Lihat Daftar Studio Musik\n2. Tambah Reservasi\n3. Edit Reservasi\n4. Lihat Reservasi Saya\n5. Logout\n";
            }
            cout << "Pilih menu: ";
            cin >> pilihan;

            if (isAdmin) 
            {
                if (pilihan == 1) tampilkanReservasiAdmin(daftarReservasi, jumlahReservasi);
                else if (pilihan == 2) cout << hapusReservasiAdmin(daftarReservasi, jumlahReservasi);
                else if (pilihan == 3) menuSorting(daftarReservasi, jumlahReservasi);
                else if (pilihan == 4) 
                {
                    cout << "\nAnda Berhasil Logout\n\n";
                    break;
                } 
                else 
                {
                    cout << "\nPilihan Tidak Valid!\nSilakan coba lagi.\n\n";
                }
            } 
            else 
            {
                if (pilihan == 1) cout << tampilkanDaftarStudio();
                else if (pilihan == 2) cout << tambahReservasiUser(namaUser, nimUser, daftarReservasi, &jumlahReservasi, daftarStudio);
                else if (pilihan == 3) cout << editReservasiUser(nimUser, daftarReservasi, jumlahReservasi, daftarStudio);
                else if (pilihan == 4) tampilkanReservasiUser(daftarReservasi, jumlahReservasi, nimUser);
                else if (pilihan == 5) 
                {
                    cout << "\nAnda Berhasil Logout\n\n";
                    break;
                } 
                else 
                {
                    cout << "\nPilihan Tidak Valid!\nSilakan coba lagi.\n\n";
                }
            }
        }
    }
}
