#include <iostream>
#include <cstdlib>
#include <ctime>
#define MAX 10

// Nama : Andhika Bintang Ratnanto
// Kelas: Teknologi Game A
// NRP 	: 5223600014

int Data[MAX];

// Fungsi untuk pertukaran bilangan
void Tukar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Fungsi pengurutan Selection Sort
void SelectionSort() {
    int i, j, k;
    for (i = 0; i < MAX - 1; i++) {
        k = i;
        for (j = i + 1; j < MAX; j++) {
            if (Data[k] > Data[j]) {
                k = j;
            }
        }
        Tukar(&Data[i], &Data[k]);
    }
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr))); // Inisialisasi pengacakan dengan seed waktu saat ini

    std::cout << "DATA SEBELUM TERURUT";
    for (int i = 0; i < MAX; i++) {
        Data[i] = rand() % 1000 + 1;  // Menghasilkan bilangan acak antara 1 dan 1000
        std::cout << "\nData ke " << i << " : " << Data[i];
    }

    SelectionSort(); // Melakukan pengurutan

    std::cout << "\nDATA SETELAH TERURUT";
    for (int i = 0; i < MAX; i++) {
        std::cout << "\nData ke " << i << " : " << Data[i];
    }

    return 0;
}
