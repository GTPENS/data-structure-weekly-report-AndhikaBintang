// Nama : Andhika Bintang Ratnanto
// Kelas: Teknologi Game A
// NRP 	: 5223600014

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Karyawan {
    std::string nama;
    int nip;
};

// Prototipe fungsi
void urutkanBubble(std::vector<Karyawan>& karyawan, bool berdasarkanNIP, bool naik);
void urutkanShell(std::vector<Karyawan>& karyawan, bool berdasarkanNIP, bool naik);
void tukar(Karyawan* a, Karyawan* b);
void tampilkanKaryawan(const std::vector<Karyawan>& karyawan);

int main() {
    // Data contoh
    std::vector<Karyawan> karyawan = {
        {"John Doe", 112233},
        {"Jane Smith", 223344},
        {"Alice Johnson", 334455},
        {"Bob Brown", 445566}
    };

    int pilihan, pilihanUrut, pilihanOrder;
    bool berjalan = true;

    while (berjalan) {
        std::cout << "\nMenu:\n1. Urutkan dengan Bubble Sort\n2. Urutkan dengan Shell Sort\n3. Keluar\nPilih metode pengurutan (1-3): ";
        std::cin >> pilihan;

        if (pilihan == 3) {
            berjalan = false;
            continue;
        }

        std::cout << "Pilih atribut pengurutan:\n1. Berdasarkan NIP\n2. Berdasarkan Nama\nPilih opsi (1-2): ";
        std::cin >> pilihanUrut;

        std::cout << "Pilih urutan:\n1. Naik\n2. Turun\nPilih urutan (1-2): ";
        std::cin >> pilihanOrder;

        bool berdasarkanNIP = pilihanUrut == 1;
        bool naik = pilihanOrder == 1;

        switch (pilihan) {
            case 1:
                urutkanBubble(karyawan, berdasarkanNIP, naik);
                break;
            case 2:
                urutkanShell(karyawan, berdasarkanNIP, naik);
                break;
            default:
                std::cout << "Pilihan tidak valid, silakan coba lagi.\n";
                continue;
        }

        std::cout << "Data setelah diurutkan:\n";
        tampilkanKaryawan(karyawan);
    }

    return 0;
}

void urutkanBubble(std::vector<Karyawan>& karyawan, bool berdasarkanNIP, bool naik) {
    int n = karyawan.size();
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            bool kondisi = berdasarkanNIP ? (karyawan[j].nip > karyawan[j + 1].nip) : (karyawan[j].nama > karyawan[j + 1].nama);
            if (naik ? kondisi : !kondisi) {
                tukar(&karyawan[j], &karyawan[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

void urutkanShell(std::vector<Karyawan>& karyawan, bool berdasarkanNIP, bool naik) {
    int n = karyawan.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            Karyawan temp = karyawan[i];
            int j;
            for (j = i; j >= gap; j -= gap) {
                bool kondisi = berdasarkanNIP ? (karyawan[j - gap].nip > temp.nip) : (karyawan[j - gap].nama > temp.nama);
                if (naik ? kondisi : !kondisi) {
                    karyawan[j] = karyawan[j - gap];
                } else {
                    break;
                }
            }
            karyawan[j] = temp;
        }
    }
}

void tukar(Karyawan* a, Karyawan* b) {
    Karyawan temp = *a;
    *a = *b;
    *b = temp;
}

void tampilkanKaryawan(const std::vector<Karyawan>& karyawan) {
    for (const auto& k : karyawan) {
        std::cout << "NIP: " << k.nip << ", Nama: " << k.nama << "\n";
    }
}
