#include <iostream>
#include <vector>
using namespace std;

// Struktur untuk menyimpan data siswa
struct Siswa {
    int id;
    string nama;
    int umur;
    string kelas;
};

vector<Siswa> daftarSiswa;
int idCounter = 1;

// Fungsi untuk menampilkan semua data siswa
void tampilkanSiswa() {
    cout << "====================================\n";
    cout << "         Data Siswa\n";
    cout << "====================================\n";
    if (daftarSiswa.empty()) {
        cout << "Tidak ada data siswa.\n";
    } else {
        for (const auto& siswa : daftarSiswa) {
            cout << "ID: " << siswa.id << "\n";
            cout << "Nama: " << siswa.nama << "\n";
            cout << "Umur: " << siswa.umur << "\n";
            cout << "Kelas: " << siswa.kelas << "\n";
            cout << "------------------------------------\n";
        }
    }
}

// Fungsi untuk menambahkan siswa baru
void tambahSiswa() {
    Siswa siswa;
    siswa.id = idCounter++;
    cout << "Masukkan nama siswa: ";
    cin.ignore();
    getline(cin, siswa.nama);
    cout << "Masukkan umur siswa: ";
    cin >> siswa.umur;
    cout << "Masukkan kelas siswa: ";
    cin >> siswa.kelas;
    daftarSiswa.push_back(siswa);
    cout << "Siswa berhasil ditambahkan!\n";
}

// Fungsi untuk mengedit data siswa
void editSiswa() {
    int id;
    cout << "Masukkan ID siswa yang ingin diedit: ";
    cin >> id;
    for (auto& siswa : daftarSiswa) {
        if (siswa.id == id) {
            cout << "Masukkan nama baru: ";
            cin.ignore();
            getline(cin, siswa.nama);
            cout << "Masukkan umur baru: ";
            cin >> siswa.umur;
            cout << "Masukkan kelas baru: ";
            cin >> siswa.kelas;
            cout << "Data siswa berhasil diperbarui!\n";
            return;
        }
    }
    cout << "Siswa dengan ID tersebut tidak ditemukan.\n";
}

// Fungsi untuk menghapus data siswa
void hapusSiswa() {
    int id;
    cout << "Masukkan ID siswa yang ingin dihapus: ";
    cin >> id;
    for (size_t i = 0; i < daftarSiswa.size(); ++i) {
        if (daftarSiswa[i].id == id) {
            daftarSiswa.erase(daftarSiswa.begin() + i);
            cout << "Siswa berhasil dihapus!\n";
            return;
        }
    }
    cout << "Siswa dengan ID tersebut tidak ditemukan.\n";
}

int main() {
    int pilihan;
    do {
        cout << "\nSistem Administrasi Data Siswa\n";
        cout << "1. Lihat Data Siswa\n";
        cout << "2. Tambah Siswa\n";
        cout << "3. Edit Siswa\n";
        cout << "4. Hapus Siswa\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;
        
        switch (pilihan) {
            case 1:
                tampilkanSiswa();
                break;
            case 2:
                tambahSiswa();
                break;
            case 3:
                editSiswa();
                break;
            case 4:
                hapusSiswa();
                break;
            case 5:
                cout << "Terima kasih telah menggunakan sistem!\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 5);
    
    return 0;
}