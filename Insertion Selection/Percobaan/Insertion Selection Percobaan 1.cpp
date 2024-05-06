#include <iostream>
#include <cstdlib>
#include <ctime>
#define MAX 10

// Nama : Andhika Bintang Ratnanto
// Kelas: Teknologi Game A
// NRP 	: 5223600014

int Data[MAX];

// Fungsi pengurutan penyisipan langsung (Straight Insertion Sort)
void StraightInsertSort() {
    int i, j, x;
    for (i = 1; i < MAX; i++) {
        x = Data[i];
        j = i - 1;
        while (j >= 0 && x < Data[j]) {
            Data[j + 1] = Data[j];
            j--;
        }
        Data[j + 1] = x;
    }
}

int main() {
    int i;
    srand((unsigned)time(0)); // Menggunakan seed berdasarkan waktu untuk membangkitkan bilangan acak

    // Membangkitkan bilangan acak
    std::cout << "DATA SEBELUM TERURUT";
    for (i = 0; i < MAX; i++) {
        Data[i] = rand() % 1000 + 1; // Memastikan bilangan acak antara 1 dan 1000
        std::cout << "\nData ke " << i << " : " << Data[i];
    }

    StraightInsertSort();

    // Menampilkan data setelah terurut
    std::cout << "\nDATA SETELAH TERURUT";
    for (i = 0; i < MAX; i++) {
        std::cout << "\nData ke " << i << " : " << Data[i];
    }

    return 0;
}
