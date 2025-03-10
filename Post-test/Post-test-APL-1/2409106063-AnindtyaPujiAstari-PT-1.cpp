#include <iostream>
using namespace std;

int PIN = 6063;
int saldo = 1000000000;

int menuATM();

int main() 
{
    int inputPIN;
    int kesempatan = 3;

    for (int i = 0; i < 3;  i++) 
    {
        cout << "Masukkan PIN Anda : ";
        cin >> inputPIN;

        if (inputPIN == PIN) 
        {
            cout << "\nLogin Berhasil \nSelamat Datang di ATM" << endl;
            int pilihan;
            do 
            {
                pilihan = menuATM();
            }
            while (pilihan != 4);
            cout << "Terima Kasih telah menggunakan layanan ATM" << endl;
            return 0;
        }
        else 
        {
            kesempatan--;
            cout << "\nPIN SALAH! \nKesempatan Tersisa : " << kesempatan << "\n";
        }
    }
    cout << "\nAkun Anda terblokir karena salah memasukkan PIN 3 kali" << endl;
    return 0;
}

int menuATM() 
{
    int pilihan;
    int nominal;

    cout << "\nMENU ATM" << endl;
    cout << "1. Setor Tunai" << endl;
    cout << "2. Cek Saldo" << endl;
    cout << "3. Tarik Tunai" << endl;
    cout << "4. Keluar"  << endl;
    cout << "Pilih Menu : ";
    cin >> pilihan;

    switch  (pilihan) 
    {
        case 1:
            cout << "Masukkan nominal setor tunai : ";
            cin >> nominal;
            if (nominal > 0)
            {
                saldo += nominal;
                cout << "\nSetor tunai berhasil \nSaldo Anda sekarang : " << saldo << endl;
            }
            else
            {
                cout << "Nominal harus lebih dari 0!" << endl;
            }
            break;
        case 2:
            cout << "\nSaldo Anda saat  ini : " << saldo << endl;
            break;
        case 3:
            cout << "Masukkan nominal tarik tunai : ";
            cin >> nominal;
            if (nominal > saldo)
            {
                cout << "Saldo tidak mencukupi" << endl;
            }
            else if (nominal > 0) 
            {
                saldo -= nominal;
                cout << "\nTarik tunai berhasil \nSaldo Anda sekarang : " << saldo << endl;
            }
            else
            {
                cout << "Nominal harus lebih dari 0!" << endl;
            }
            break;
        case 4:
            cout << "Keluar dari Menu ATM..." << endl;
            break;
        default:
            cout << "Pilihan tidak valid! \nSilahkan pilih menu yang tersedia" << endl;
    }
    return pilihan;
}