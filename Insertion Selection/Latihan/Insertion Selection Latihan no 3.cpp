#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// Nama : Andhika Bintang Ratnanto
// Kelas: Teknologi Game A
// NRP 	: 5223600014

struct Pegawai {
    std::string nip;
    std::string nama;
};

void printPegawai(const std::vector<Pegawai>& pegawai) {
    for (const auto& p : pegawai) {
        std::cout << "NIP: " << p.nip << ", Nama: " << p.nama << std::endl;
    }
}

void selectionSort(std::vector<Pegawai>& pegawai, bool sortByNip, bool ascending) {
    int n = pegawai.size();
    for (int i = 0; i < n - 1; i++) {
        int idx = i;
        for (int j = i + 1; j < n; j++) {
            if (sortByNip) {
                if ((ascending && pegawai[j].nip < pegawai[idx].nip) || (!ascending && pegawai[j].nip > pegawai[idx].nip)) {
                    idx = j;
                }
            } else {
                if ((ascending && pegawai[j].nama < pegawai[idx].nama) || (!ascending && pegawai[j].nama > pegawai[idx].nama)) {
                    idx = j;
                }
            }
        }
        if (idx != i) {
            std::swap(pegawai[idx], pegawai[i]);
        }
    }
}

int main() {
    std::vector<Pegawai> pegawai = {
        {"192837465", "Alice"},
        {"987654321", "Bob"},
        {"123456789", "Charlie"},
        {"564738291", "Diana"}
    };

    char repeat;
    do {
        int choice, order;
        std::cout << "Pilih metode pengurutan:\n1. Berdasarkan NIP\n2. Berdasarkan Nama\nPilihan Anda: ";
        std::cin >> choice;
        std::cout << "Pilih urutan:\n1. Naik\n2. Turun\nPilihan Anda: ";
        std::cin >> order;

        bool sortByNip = (choice == 1);
        bool ascending = (order == 1);

        selectionSort(pegawai, sortByNip, ascending);

        std::cout << "Data pegawai setelah diurutkan:" << std::endl;
        printPegawai(pegawai);

        std::cout << "Apakah Anda ingin mengurutkan lagi? (y/n): ";
        std::cin >> repeat;
    } while (repeat == 'y' || repeat == 'Y');

    return 0;
}
