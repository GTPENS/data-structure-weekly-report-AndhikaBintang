#include <iostream>
#include <cstdlib>
#include <ctime>
#define MAX 10

// Nama : Andhika Bintang Ratnanto
// Kelas: Teknologi Game A
// NRP 	: 5223600014

int Data[MAX];

void Tukar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void PrintArray() {
    for (int i = 0; i < MAX; i++) {
        std::cout << Data[i] << " ";
    }
    std::cout << std::endl;
}

void InsertionSort() {
    int i, j, key;
    for (i = 1; i < MAX; i++) {
        key = Data[i];
        j = i - 1;
        while (j >= 0 && Data[j] > key) {
            Data[j + 1] = Data[j];
            j--;
        }
        Data[j + 1] = key;
        std::cout << "Setelah iterasi " << i << ": ";
        PrintArray();
    }
}

void BinaryInsertionSort() {
    int i, j, l, r, m, x;
    for (i = 1; i < MAX; i++) {
        x = Data[i];
        l = 0;
        r = i - 1;
        while (l <= r) {
            m = (l + r) / 2;
            if (x < Data[m])
                r = m - 1;
            else
                l = m + 1;
        }
        for (j = i - 1; j >= l; j--)
            Data[j + 1] = Data[j];
        Data[l] = x;
        std::cout << "Setelah iterasi " << i << ": ";
        PrintArray();
    }
}

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
        std::cout << "Setelah iterasi " << i << ": ";
        PrintArray();
    }
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));
    int choice;
    char repeat;

    do {
        std::cout << "Data awal: ";
        for (int i = 0; i < MAX; i++) {
            Data[i] = rand() % 1000 + 1;
            std::cout << Data[i] << " ";
        }
        std::cout << "\n\n";

        std::cout << "Pilih metode pengurutan:\n1. Insertion Sort\n2. Binary Insertion Sort\n3. Selection Sort\nPilihan Anda: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                InsertionSort();
                break;
            case 2:
                BinaryInsertionSort();
                break;
            case 3:
                SelectionSort();
                break;
            default:
                std::cout << "Pilihan tidak valid!\n";
                break;
        }

        std::cout << "Ulangi program? (y/n): ";
        std::cin >> repeat;
        std::cout << "\n";
    } while (repeat == 'y' || repeat == 'Y');

    return 0;
}
