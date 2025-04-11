#include <iostream>
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

Reservasi daftarReservasi[MAX_RESERVASI];
int jumlahReservasi = 0;

Studio daftarStudio[2] = {{"Kelas A", 80000}, {"Kelas B", 100000}};
string alatMusik[2][7] = 
{
    {"Drum", "Keyboard", "Gitar Akustik", "Gitar Elektrik", "Bass", "Cajon", "Mic"},
    {"Piano", "Violin", "Celo", "Flute", "Terompet", "Saxofon", "Harpa"}
};
int hargaPerJam[2] = {80000, 100000};

string tambahReservasiAwal() 
{
    daftarReservasi[jumlahReservasi++] = {"ipeh", "202101", daftarStudio[0], 3, 3 * daftarStudio[0].hargaPerJam};
    daftarReservasi[jumlahReservasi++] = {"aryo", "202102", daftarStudio[1], 2, 2 * daftarStudio[1].hargaPerJam};
    daftarReservasi[jumlahReservasi++] = {"araa", "202103", daftarStudio[0], 5, 5 * daftarStudio[0].hargaPerJam};
    daftarReservasi[jumlahReservasi++] = {"inun", "202104", daftarStudio[1], 4, 4 * daftarStudio[1].hargaPerJam};
    return "HELLO\n";
}

string tampilkanReservasiUser(string nimUser) 
{
    string output = "\nReservasi Anda:\n";
    output += "==========================================\n";
    output += "| No | Kelas   | Jam | Total Harga       |\n";
    output += "==========================================\n";
    
    bool ada = false;
    for (int i = 0; i < jumlahReservasi; i++) 
    {
        if (daftarReservasi[i].nim == nimUser) 
        {
            output += "| " + to_string(i + 1) + "  | " + daftarReservasi[i].studio.namaKelas + " |  " +
                      to_string(daftarReservasi[i].jam) + "  | Rp " +
                      to_string(daftarReservasi[i].totalHarga) + "         |\n";
            ada = true;
        }
    }
    if (!ada) output += "|          Tidak ada reservasi           |\n";
    
    output += "==========================================\n";
    return output;
}

string tampilkanDaftarStudio() 
{
    string output = "\n==================================================================================================\n";
    output += "| No | Kelas   | Alat Musik                                                      | Harga Per Jam |\n";
    output += "==================================================================================================\n";
    for (int i = 0; i < 2; i++) 
    {
        output += "| " + to_string(i + 1) + "  | " + daftarStudio[i].namaKelas + " | ";
        for (int j = 0; j < 7; j++) 
        {
            output += alatMusik[i][j];
            if (j < 6) output += ", ";
        }
        output += " |   Rp " + to_string(daftarStudio[i].hargaPerJam) + "    |\n";
    }
    output += "==================================================================================================\n";
    return output;
}

string tambahReservasiUser(string nama, string nim) 
{
    if (jumlahReservasi >= MAX_RESERVASI) {
        return "Reservasi penuh! Tidak dapat menambah reservasi baru.\n";
    }
    
    Reservasi r;
    cout << "Masukkan Nama: ";
    cin.ignore();
    getline(cin, r.nama);
    cout << "Masukkan NIM: ";
    getline(cin, r.nim);
    
    cout << tampilkanDaftarStudio();
    int pilihan;
    cout << "Pilih Kelas Studio (1/2): ";
    cin >> pilihan;
    if (pilihan < 1 || pilihan > 2) {
        return "Pilihan tidak valid!\n";
    }
    
    r.studio = daftarStudio[pilihan - 1];
    cout << "Masukkan jumlah jam: ";
    cin >> r.jam;
    r.totalHarga = r.jam * r.studio.hargaPerJam;
    daftarReservasi[jumlahReservasi++] = r;
    
    return "Reservasi berhasil ditambahkan!\n";
}

string editReservasiUser(string nim) 
{
    int index, jam, pilihan;
    cout << "Masukkan nomor reservasi yang akan diedit: ";
    cin >> index;
    if (index < 1 || index > jumlahReservasi || daftarReservasi[index - 1].nim != nim)
        return "Reservasi Tidak Ditemukan!\n";

    cout << "\nPilih Kelas Studio Baru:\n";
    cout << "1. Kelas A (Rp " << hargaPerJam[0] << "/jam)\n";
    cout << "2. Kelas B (Rp " << hargaPerJam[1] << "/jam)\n";
<<<<<<< HEAD
    cout << "Pilih Kelas Studio (1/2): ";
=======
    cout << "Pilihan: ";
>>>>>>> 8faaff2bb9b677cae1a79b36508dd898b8e3c547
    cin >> pilihan;
    if (pilihan < 1 || pilihan > 2) 
        return "Pilihan Tidak Valid!\n";

    daftarReservasi[index - 1].studio = daftarStudio[pilihan - 1];
    cout << "Masukkan jumlah jam baru: ";
    cin >> jam;
    daftarReservasi[index - 1].jam = jam;
    daftarReservasi[index - 1].totalHarga = jam * daftarStudio[pilihan - 1].hargaPerJam; 

    return "Reservasi Berhasil Diperbarui!\n";
}

string tampilkanReservasiAdmin() 
{
    if (jumlahReservasi == 0) return "\nTidak Ada Reservasi Saat Ini.\n";
    
    string output = "\n=======================================================================\n";
    output += "| No | Nama                 | NIM       | Kelas   | Jam | Total Harga |\n";
    output += "=======================================================================\n";
    for (int i = 0; i < jumlahReservasi; i++) 
    {
        output += "| " + to_string(i + 1) + "  | " + daftarReservasi[i].nama + "                 | " +
                  daftarReservasi[i].nim + "    | " + daftarReservasi[i].studio.namaKelas + " |  " +
                  to_string(daftarReservasi[i].jam) + "  | Rp " +
                  to_string(daftarReservasi[i].totalHarga) + "   |\n";
    }
    output += "=======================================================================\n";
    return output;
}

string hapusReservasiAdmin() 
{
    if (jumlahReservasi == 0) return "Tidak Ada Reservasi Yang Bisa Dihapus.\n";
    
    cout << tampilkanReservasiAdmin();
    int index;
    cout << "Masukkan nomor reservasi yang akan dihapus: ";
    cin >> index;
    
    if (index < 1 || index > jumlahReservasi) return "Nomor Reservasi Tidak Valid!\n";

    for (int i = index - 1; i < jumlahReservasi - 1; i++) 
    {
        daftarReservasi[i] = daftarReservasi[i + 1];
    }
    jumlahReservasi--;
    
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


string registrasiUser(string &nama, string &nim) 
{
    cout << "\n--===REGISTRASI USER===--\nMasukkan Nama: ";
    cin >> nama;
    cout << "Masukkan NIM: ";
    cin >> nim;
    return "Registrasi Berhasil!\n\n";
}

int main() 
{
    int pilihan;
    bool isAdmin = false;
    string namaUser, nimUser;

    cout << tambahReservasiAwal(); 

    while (true) 
    {
        cout << "Selamat Datang di Sistem Reservasi Studio Musik\n";
        cout << "1. Login Admin\n2. Registrasi User\n3. Keluar\nPilih: ";
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
            cout << registrasiUser(namaUser, nimUser);
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
                cout << "1. Lihat Semua Reservasi\n2. Hapus Reservasi\n3. Logout\n";
            } 
            else 
            {
                cout << "1. Lihat Daftar Studio Musik\n2. Tambah Reservasi\n3. Edit Reservasi\n4. Lihat Reservasi Saya\n5. Logout\n";
            }
            cout << "Pilih menu: ";
            cin >> pilihan;

            if (isAdmin) 
            {
                if (pilihan == 1) cout << tampilkanReservasiAdmin();
                else if (pilihan == 2) cout << hapusReservasiAdmin();
                else if (pilihan == 3) 
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
                else if (pilihan == 2) cout << tambahReservasiUser(namaUser, nimUser);
                else if (pilihan == 3) cout << editReservasiUser(nimUser);
                else if (pilihan == 4) cout << tampilkanReservasiUser(nimUser);
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
