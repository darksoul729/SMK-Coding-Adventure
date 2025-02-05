#include <iostream>

extern "C" {
    int tambah(int a, int b) { return a + b; }
    int kurang(int a, int b) { return a - b; }
    int kali(int a, int b) { return a * b; }
    float bagi(float a, float b) { return b != 0 ? a / b : 0; }
}
