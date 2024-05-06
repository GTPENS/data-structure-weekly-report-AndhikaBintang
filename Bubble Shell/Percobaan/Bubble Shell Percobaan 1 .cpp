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

// Function to perform bubble sort
void BubbleSort() {
    for(int i = 1; i < MAX; i++) {
        for(int j = MAX - 1; j >= i; j--) {
            if(Data[j-1] > Data[j]) {
                Swap(&Data[j-1], &Data[j]);
            }
        }
    }
}

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr))); // Seed random with current time for better randomness

    // Generating random numbers
    std::cout << "DATA SEBELUM TERURUT";
    for(int i = 0; i < MAX; i++) {
        Data[i] = std::rand() % 100 + 1; // Generates random numbers between 1 and 100
        std::cout << "\nData ke " << i << " : " << Data[i];
    }

    BubbleSort(); // Sorting the array

    // Displaying sorted data
    std::cout << "\nDATA SETELAH TERURUT";
    for(int i = 0; i < MAX; i++) {
        std::cout << "\nData ke " << i << " : " << Data[i];
    }

    return 0;
}
