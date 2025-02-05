#include <emscripten.h>
#include <iostream>
#include <string>

extern "C" {
    int saldo = 1000;  // saldo awal

    // Fungsi untuk cek saldo
    EMSCRIPTEN_KEEPALIVE
    int cekSaldo() {
        return saldo;
    }

    // Fungsi untuk setor uang
    EMSCRIPTEN_KEEPALIVE
    void setorUang(int jumlah) {
        saldo += jumlah;
    }

    // Fungsi untuk tarik uang
    EMSCRIPTEN_KEEPALIVE
    bool tarikUang(int jumlah) {
        if (jumlah <= saldo) {
            saldo -= jumlah;
            return true;
        }
        return false;
    }

    // Fungsi untuk transfer uang
    EMSCRIPTEN_KEEPALIVE
    bool transferUang(int jumlah) {
        if (jumlah <= saldo) {
            saldo -= jumlah;
            return true;
        }
        return false;
    }
}
