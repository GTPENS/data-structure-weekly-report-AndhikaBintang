// Nama : Andhika Bintang Ratnanto
// Kelas: Teknologi Game A
// NRP 	: 5223600014

#include <iostream>
#include <cstdlib>
#include <ctime>

#define MAX 10
int Data[MAX];

// Function to swap data
void Swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform Shell sort
void ShellSort() {
    int gap, i, j;
    bool swapped;
    gap = MAX;

    while (gap > 1) {
        gap = gap / 2;
        swapped = false;

        while (!swapped) {
            swapped = true;
            for (j = 0; j < MAX - gap; j++) {
                i = j + gap;
                if (Data[j] > Data[i]) {
                    Swap(&Data[j], &Data[i]);
                    swapped = false;
                }
            }
        }
    }
}

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr))); // Seed random with current time for better randomness

    // Generating random numbers
    std::cout << "DATA SEBELUM TERURUT";
    for (int i = 0; i < MAX; i++) {
        Data[i] = std::rand() % 100 + 1; // Generates random numbers between 1 and 100
        std::cout << "\nData ke " << i << " : " << Data[i];
    }

    ShellSort(); // Sorting the array

    // Displaying sorted data
    std::cout << "\nDATA SETELAH TERURUT";
    for (int i = 0; i < MAX; i++) {
        std::cout << "\nData ke " << i << " : " << Data[i];
    }

    return 0;
}
