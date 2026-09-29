//RAFI BAGUS SETIAWAN 26/578857/SV/28079
//SATRIA KANZEN JANNATUKA 26/579462/SV/28230
#include <iostream>
#include <string>
using namespace std;

const int MAX_BARANG = 50;
string namaBarang[MAX_BARANG];
double hargaBarang[MAX_BARANG];
int stokBarang[MAX_BARANG];
int jumlahBarang = 0;

void tambahBarang();
void jualBarang();
void lihatStok();
void laporanTotal();
int cariBarang(string nama);

double hitungTotalHarga(double harga, int jumlah);
double hitungTotalHarga(double harga[], int stok[], int n);

int main() {
    int pilihan;
    int jumlahAwal;

    cout << "===== SISTEM MANAJEMEN STOK KANTIN =====" << endl;
    cout << "Berapa jenis barang awal yang mau didaftarkan? ";
    cin >> jumlahAwal;

    for (int i = 0; i < jumlahAwal && jumlahBarang < MAX_BARANG; i++) {
        cout << "\n-- Input Barang ke-" << (i + 1) << " --" << endl;
        tambahBarang();
    }

    while (true) {
        cout << "\n================ MENU ================" << endl;
        cout << "1. Tambah Barang" << endl;
        cout << "2. Jual Barang" << endl;
        cout << "3. Lihat Stok" << endl;
        cout << "4. Laporan Total Nilai Stok" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tambahBarang();
                break;
            case 2:
                jualBarang();
                break;
            case 3:
                lihatStok();
                break;
            case 4:
                laporanTotal();
                break;
            case 5:
                cout << "\nTerima kasih, program selesai." << endl;
                break;
            default:
                cout << "Pilihan tidak valid, coba lagi." << endl;
                continue;
        }

        if (pilihan == 5) break; 
    }

    return 0;
}

void tambahBarang() {
    if (jumlahBarang >= MAX_BARANG) {
        cout << "Stok penuh, tidak bisa tambah barang baru." << endl;
        return;
    }

    string nama;
    double harga;
    int stok;

    cout << "Nama barang (Tanpa spasi): ";
    cin >> nama;

    int idx = cariBarang(nama);

    if (idx != -1) {
        cout << "Barang sudah ada, stok akan ditambahkan." << endl;
        cout << "Tambah stok sebanyak: ";
        cin >> stok;
        stokBarang[idx] += stok;
    } else {
        cout << "Harga barang: ";
        cin >> harga;
        cout << "Jumlah stok awal: ";
        cin >> stok;

        namaBarang[jumlahBarang] = nama;
        hargaBarang[jumlahBarang] = harga;
        stokBarang[jumlahBarang] = stok;
        jumlahBarang++;

        cout << "Barang \"" << nama << "\" berhasil ditambahkan." << endl;
    }
}

void jualBarang() {
    string nama;
    int jumlah;

    cout << "Nama barang yang mau dijual: ";
    cin >> nama;

    int idx = cariBarang(nama);

    if (idx == -1) {
        cout << "Barang tidak ditemukan." << endl;
        return;
    }

    cout << "Jumlah beli: ";
    cin >> jumlah;

    if (stokBarang[idx] >= jumlah) {
        stokBarang[idx] -= jumlah;
        double total = hitungTotalHarga(hargaBarang[idx], jumlah); 
        cout << "Transaksi berhasil. Total bayar: Rp" << total << endl;
        cout << "Sisa stok " << namaBarang[idx] << ": " << stokBarang[idx] << endl;
    } else {
        cout << "Stok tidak cukup! Sisa stok hanya " << stokBarang[idx] << endl;
    }
}

void lihatStok() {
    cout << "\n--- DAFTAR STOK BARANG ---" << endl;

    if (jumlahBarang == 0) {
        cout << "Belum ada barang terdaftar." << endl;
        return;
    }

    for (int i = 0; i < jumlahBarang; i++) {
        if (stokBarang[i] == 0) {
            cout << (i + 1) << ". " << namaBarang[i] << " - HABIS" << endl;
            continue;
        }
        cout << (i + 1) << ". " << namaBarang[i]
             << " | Harga: Rp" << hargaBarang[i]
             << " | Stok: " << stokBarang[i] << endl;
    }
}

void laporanTotal() {
    double totalNilai = hitungTotalHarga(hargaBarang, stokBarang, jumlahBarang);

    cout << "\n--- LAPORAN NILAI STOK ---" << endl;
    cout << "Jumlah jenis barang : " << jumlahBarang << endl;
    cout << "Total nilai stok    : Rp" << totalNilai << endl;
}

int cariBarang(string nama) {
    int index = -1;

    for (int i = 0; i < jumlahBarang; i++) {
        if (namaBarang[i] == nama) {
            index = i;
            break;
        }
    }

    return index;
}

double hitungTotalHarga(double harga, int jumlah) {
    return harga * jumlah;
}

double hitungTotalHarga(double harga[], int stok[], int n) {
    double total = 0;
    for (int i = 0; i < n; i++) {
        total += harga[i] * stok[i];
    }
    return total;
}