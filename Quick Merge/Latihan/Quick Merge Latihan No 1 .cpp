// Nama	 : Andhika Bintang Ratnanto
// Kelas : Teknologi Game A
// NRP 	 : 5223600014


#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#define MAX 10

std::vector<int> Data(MAX);
std::vector<int> temp(MAX);

void tukar(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void cetakArray(const std::vector<int>& array, const std::string& prefix) {
    std::cout << prefix;
    for (int num : array) {
        std::cout << num << " ";
    }
    std::cout << "\n";
}

void quickSort(int left, int right) {
    if (left >= right) return;
    int pivot = Data[(left + right) / 2];
    int i = left, j = right;

    while (i <= j) {
        while (Data[i] < pivot) i++;
        while (Data[j] > pivot) j--;
        if (i <= j) {
            tukar(&Data[i], &Data[j]);
            i++;
            j--;
        }
    }

    cetakArray(Data, "Quick Sort Iterasi: ");
    
    quickSort(left, j);
    quickSort(i, right);
}

void merge(int left, int mid, int right) {
    int i = left, j = mid, k = left;

    while (i <= mid - 1 && j <= right) {
        if (Data[i] <= Data[j])
            temp[k++] = Data[i++];
        else
            temp[k++] = Data[j++];
    }

    while (i <= mid - 1)
        temp[k++] = Data[i++];

    while (j <= right)
        temp[k++] = Data[j++];

    for (i = left; i <= right; i++)
        Data[i] = temp[i];

    cetakArray(Data, "Merge Sort Iterasi: ");
}

void mergeSort(int left, int right) {
    if (right > left) {
        int mid = (left + right) / 2;
        mergeSort(left, mid);
        mergeSort(mid + 1, right);
        merge(left, mid + 1, right);
    }
}

void inisialisasiData() {
    srand(static_cast<unsigned int>(time(nullptr)));
    for (int i = 0; i < MAX; i++) {
        Data[i] = rand() % 100 + 1;
    }
}

int main() {
    char lanjut;
    int pilihan;
    
    do {
        inisialisasiData();
        std::cout << "\nDATA SEBELUM TERURUT: ";
        cetakArray(Data, "");

        std::cout << "Pilih metode pengurutan:\n";
        std::cout << "1. Quick Sort\n";
        std::cout << "2. Merge Sort\n";
        std::cout << "Pilihan Anda: ";
        std::cin >> pilihan;

        switch (pilihan) {
            case 1:
                quickSort(0, MAX - 1);
                break;
            case 2:
                mergeSort(0, MAX - 1);
                break;
            default:
                std::cout << "Pilihan tidak valid!\n";
                continue;
        }

        std::cout << "\nDATA SETELAH TERURUT: ";
        cetakArray(Data, "");

        std::cout << "Ulangi program? (y/n): ";
        std::cin >> lanjut;
    } while (lanjut == 'y' || lanjut == 'Y');

    return 0;
}
