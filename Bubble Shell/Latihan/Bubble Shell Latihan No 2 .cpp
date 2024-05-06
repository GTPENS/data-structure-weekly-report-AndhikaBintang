// Nama : Andhika Bintang Ratnanto
// Kelas: Teknologi Game A
// NRP 	: 5223600014

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

#define MAX 10

std::vector<int> data(MAX);

// Function to swap data
void Swap(int *a, int *b, int& swaps) {
    int temp = *a;
    *a = *b;
    *b = temp;
    swaps++;
}

// Function to perform Bubble Sort with display at each iteration
void BubbleSort() {
    bool swapped;
    int comparisons = 0, swaps = 0;
    for (int i = 0; i < MAX - 1; i++) {
        swapped = false;
        for (int j = 0; j < MAX - i - 1; j++) {
            comparisons++;
            if (data[j] > data[j + 1]) {
                Swap(&data[j], &data[j + 1], swaps);
                swapped = true;
            }
        }
        // Display the array's state after each pass
        std::cout << "After pass " << i + 1 << ": ";
        for (int k = 0; k < MAX; k++) {
            std::cout << data[k] << " ";
        }
        std::cout << "\n";
        if (!swapped)
            break; // No swaps means the array is sorted
    }
    std::cout << "Total comparisons: " << comparisons << ", Total swaps: " << swaps << "\n";
}

// Function to perform Shell Sort with display at each iteration
void ShellSort() {
    int gap, i, j, comparisons = 0, swaps = 0;
    for (gap = MAX / 2; gap > 0; gap /= 2) {
        bool swapped;
        do {
            swapped = false;
            for (j = 0; j < MAX - gap; j++) {
                comparisons++;
                i = j + gap;
                if (data[j] > data[i]) {
                    Swap(&data[j], &data[i], swaps);
                    swapped = true;
                }
            }
            // Display the array's state after each gap comparison
            std::cout << "After gap " << gap << ": ";
            for (int k = 0; k < MAX; k++) {
                std::cout << data[k] << " ";
            }
            std::cout << "\n";
        } while (swapped);
    }
    std::cout << "Total comparisons: " << comparisons << ", Total swaps: " << swaps << "\n";
}

// Function to generate random data
void GenerateRandomData() {
    for (int i = 0; i < MAX; i++) {
        data[i] = std::rand() % 100 + 1;
    }
}

// Function to display the initial data
void DisplayData() {
    std::cout << "Data sebelum terurut: ";
    for (int i = 0; i < MAX; i++) {
        std::cout << data[i] << " ";
    }
    std::cout << "\n";
}

int main() {
    int choice;
    bool running = true;

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    while (running) {
        std::cout << "\nMenu:\n1. Bubble Sort\n2. Shell Sort\n3. Exit\nChoose (1-3): ";
        std::cin >> choice;

        if (choice == 1 || choice == 2) {
            GenerateRandomData();
            DisplayData();

            if (choice == 1) {
                std::cout << "Performing Bubble Sort...\n";
                BubbleSort();
            } else if (choice == 2) {
                std::cout << "Performing Shell Sort...\n";
                ShellSort();
            }

            std::cout << "Data setelah terurut: ";
            for (int i = 0; i < MAX; i++) {
                std::cout << data[i] << " ";
            }
            std::cout << "\n";
        } else if (choice == 3) {
            running = false; // Exit the loop
        } else {
            std::cout << "Invalid choice, please try again.\n";
        }
    }

    return 0;
}
