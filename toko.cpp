#include <iostream>
#include <vector>
using namespace std;

// Struktur untuk menyimpan data produk
struct Produk {
    string nama;
    double harga;
    int stok;
};

// Fungsi untuk menampilkan daftar produk
void tampilkanProduk(const vector<Produk>& daftarProduk) {
    cout << "==============================\n";
    cout << "       Daftar Produk\n";
    cout << "==============================\n";
    for (size_t i = 0; i < daftarProduk.size(); i++) {
        cout << i + 1 << ". " << daftarProduk[i].nama 
             << " - Rp" << daftarProduk[i].harga 
             << " (Stok: " << daftarProduk[i].stok << ")\n";
    }
    cout << "==============================\n";
}

// Fungsi untuk membeli produk
void beliProduk(vector<Produk>& daftarProduk) {
    int pilihan, jumlah;
    cout << "Masukkan nomor produk yang ingin dibeli: ";
    cin >> pilihan;
    if (pilihan < 1 || pilihan > daftarProduk.size()) {
        cout << "Produk tidak ditemukan!\n";
        return;
    }
    cout << "Masukkan jumlah yang ingin dibeli: ";
    cin >> jumlah;
    if (jumlah > daftarProduk[pilihan - 1].stok) {
        cout << "Stok tidak mencukupi!\n";
        return;
    }
    daftarProduk[pilihan - 1].stok -= jumlah;
    cout << "Pembelian berhasil! Total: Rp" << jumlah * daftarProduk[pilihan - 1].harga << "\n";
}

int main() {
    vector<Produk> daftarProduk = {
        {"Buku", 15000, 10},
        {"Pensil", 5000, 20},
        {"Penghapus", 3000, 15}
    };
    
    int pilihan;
    do {
        cout << "\nSistem Toko:\n";
        cout << "1. Lihat Produk\n";
        cout << "2. Beli Produk\n";
        cout << "3. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;
        
        switch (pilihan) {
            case 1:
                tampilkanProduk(daftarProduk);
                break;
            case 2:
                beliProduk(daftarProduk);
                break;
            case 3:
                cout << "Terima kasih telah berbelanja!\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 3);
    
    return 0;
}
