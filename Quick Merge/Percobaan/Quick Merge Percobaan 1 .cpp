// Nama	 : Andhika Bintang Ratnanto
// Kelas : Teknologi Game A
// NRP 	 : 5223600014

#include <iostream>
#include <cstdlib>
#include <ctime>
#define MAX 10
#define MaxStack 10

int Data[MAX];

// Function to swap data
void Swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function for non-recursive quicksort
void QuickSortNonRecursive() {
    struct Stack {
        int left;
        int right;
    } Stack[MaxStack];

    int top = 0, i, j, L, R, pivot;
    Stack[top].left = 0;
    Stack[top].right = MAX - 1;

    while (top >= 0) {
        L = Stack[top].left;
        R = Stack[top].right;
        top--;

        while (R > L) {
            i = L;
            j = R;
            pivot = Data[(L + R) / 2];

            while (i <= j) {
                while (Data[i] < pivot) i++;
                while (Data[j] > pivot) j--;
                if (i <= j) {
                    Swap(&Data[i], &Data[j]);
                    i++;
                    j--;
                }
            }

            if (L < j) {
                top++;
                Stack[top].left = L;
                Stack[top].right = j;
            }

            L = i;
        }
    }
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    std::cout << "DATA BEFORE SORTING";
    for (int i = 0; i < MAX; i++) {
        Data[i] = rand() % 100 + 1;
        std::cout << "\nData[" << i << "]: " << Data[i];
    }

    QuickSortNonRecursive();

    std::cout << "\n\nDATA AFTER SORTING";
    for (int i = 0; i < MAX; i++) {
        std::cout << "\nData[" << i << "]: " << Data[i];
    }

    return 0;
}
