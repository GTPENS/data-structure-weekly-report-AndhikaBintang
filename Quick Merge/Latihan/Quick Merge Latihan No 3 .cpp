// Nama	 : Andhika Bintang Ratnanto
// Kelas : Teknologi Game A
// NRP 	 : 5223600014


#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // Untuk std::swap

struct Pegawai {
    std::string nip;
    std::string nama;
};

std::vector<Pegawai> pegawai;

void cetakPegawai() {
    for (auto& p : pegawai) {
        std::cout << "NIP: " << p.nip << ", Nama: " << p.nama << "\n";
    }
}

int partition(std::vector<Pegawai>& arr, int low, int high, bool ascending, bool sortByNip) {
    Pegawai pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (ascending == (sortByNip ? (arr[j].nip < pivot.nip) : (arr[j].nama < pivot.nama))) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(std::vector<Pegawai>& arr, int low, int high, bool ascending, bool sortByNip) {
    if (low < high) {
        int pi = partition(arr, low, high, ascending, sortByNip);

        quickSort(arr, low, pi - 1, ascending, sortByNip);
        quickSort(arr, pi + 1, high, ascending, sortByNip);
    }
}

void merge(std::vector<Pegawai>& arr, int l, int m, int r, bool ascending, bool sortByNip) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    std::vector<Pegawai> L(n1), R(n2);

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0; j = 0; k = l;
    while (i < n1 && j < n2) {
        if (ascending == (sortByNip ? (L[i].nip <= R[j].nip) : (L[i].nama <= R[j].nama))) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(std::vector<Pegawai>& arr, int l, int r, bool ascending, bool sortByNip) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m, ascending, sortByNip);
        mergeSort(arr, m + 1, r, ascending, sortByNip);
        merge(arr, l, m, r, ascending, sortByNip);
    }
}

int main() {
    char lanjut;
    int pilihan, metodeSort, orderSort;
    do {
        std::cout << "Masukkan data Pegawai (NIP dan Nama, ketik 'done' untuk selesai):\n";
        std::string nip, nama;
        while (true) {
            std::cout << "NIP: ";
            std::getline(std::cin, nip);
            if (nip == "done") break;
            std::cout << "Nama: ";
            std::getline(std::cin, nama);
            pegawai.push_back({nip, nama});
        }

        std::cout << "Pilih metode pengurutan:\n";
        std::cout << "1. Quick Sort\n";
        std::cout << "2. Merge Sort\n";
        std::cin >> metodeSort;
        std::cin.ignore();

        std::cout << "Pilih tipe pengurutan:\n";
        std::cout << "1. Berdasarkan NIP\n";
        std::cout << "2. Berdasarkan Nama\n";
        std::cin >> orderSort;
        std::cin.ignore();

        std::cout << "Pilih arah pengurutan:\n";
        std::cout << "1. Ascending (Naik)\n";
        std::cout << "2. Descending (Turun)\n";
        int direction;
        std::cin >> direction;
        std::cin.ignore();

        bool ascending = (direction == 1);
        bool sortByNip = (orderSort == 1);

        std::cout << "\nData Pegawai sebelum diurutkan:\n";
        cetakPegawai();

        if (metodeSort == 1) {
            quickSort(pegawai, 0, pegawai.size() - 1, ascending, sortByNip);
        } else {
            mergeSort(pegawai, 0, pegawai.size() - 1, ascending, sortByNip);
        }

        std::cout << "\nData Pegawai setelah diurutkan:\n";
        cetakPegawai();

        std::cout << "\nUlangi program? (y/n): ";
        std::cin >> lanjut;
        std::cin.ignore();

        pegawai.clear();  // Clear the vector for new input if repeated
    } while (lanjut == 'y' || lanjut == 'Y');

    return 0;
}
