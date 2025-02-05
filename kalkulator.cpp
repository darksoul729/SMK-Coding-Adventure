#include <iostream>
using namespace std;

// Fungsi untuk menampilkan ASCII Art "Capibara"
void displayAsciiArt() {
    cout << "===========================" << endl;
    cout << "        /\_/\  " << endl;
    cout << "       ( o.o ) " << endl;
    cout << "        > ^ <  " << endl;
    cout << "===========================" << endl;
}


int main() {
    char operasi;
    double angka1, angka2, hasil;
    
    // Menampilkan ASCII Art
    displayAsciiArt();
    
    // Meminta input pengguna
    cout << "\nMasukkan operasi (+, -, *, /): ";
    cin >> operasi;
    cout << "Masukkan angka pertama: ";
    cin >> angka1;
    cout << "Masukkan angka kedua: ";
    cin >> angka2;
    
    // Melakukan operasi berdasarkan input pengguna
    switch (operasi) {
        case '+':
            hasil = angka1 + angka2;
            break;
        case '-':
            hasil = angka1 - angka2;
            break;
        case '*':
            hasil = angka1 * angka2;
            break;
        case '/':
            if (angka2 != 0) {
                hasil = angka1 / angka2;
            } else {
                cout << "Error: Pembagian oleh nol tidak diperbolehkan!" << endl;
                return 1;
            }
            break;
        default:
            cout << "Operasi tidak valid!" << endl;
            return 1;
    }
    
    // Menampilkan hasil
    cout << "Hasil: " << hasil << endl;
    
    return 0;
}
