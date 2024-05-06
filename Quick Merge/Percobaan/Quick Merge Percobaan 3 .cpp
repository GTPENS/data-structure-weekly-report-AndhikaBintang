// Nama	 : Andhika Bintang Ratnanto
// Kelas : Teknologi Game A
// NRP 	 : 5223600014


#include <iostream>
#include <cstdlib>
#include <ctime>
#define MAX 10

int Data[MAX];
int temp[MAX];

// Function to merge arrays
void merge(int Data[], int temp[], int left, int mid, int right) {
    int i, left_end, num_elements, tmp_pos;
    left_end = mid - 1;
    tmp_pos = left;
    num_elements = right - left + 1;

    while ((left <= left_end) && (mid <= right)) {
        if (Data[left] <= Data[mid]) {
            temp[tmp_pos] = Data[left];
            tmp_pos++;
            left++;
        } else {
            temp[tmp_pos] = Data[mid];
            tmp_pos++;
            mid++;
        }
    }

    while (left <= left_end) {
        temp[tmp_pos] = Data[left];
        left++;
        tmp_pos++;
    }

    while (mid <= right) {
        temp[tmp_pos] = Data[mid];
        mid++;
        tmp_pos++;
    }

    for (i = 0; i < num_elements; i++) {
        Data[right] = temp[right];
        right--;
    }
}

// Recursive function to sort data
void m_sort(int Data[], int temp[], int left, int right) {
    int mid;
    if (right > left) {
        mid = (left + right) / 2;
        m_sort(Data, temp, left, mid);
        m_sort(Data, temp, mid + 1, right);
        merge(Data, temp, left, mid + 1, right);
    }
}

// Public interface to merge sort
void mergeSort(int Data[], int temp[], int array_size) {
    m_sort(Data, temp, 0, array_size - 1);
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr))); // Better seeding

    std::cout << "\nDATA BEFORE SORTING: ";
    for (int i = 0; i < MAX; i++) {
        Data[i] = rand() % 100 + 1; // More sensible and visible data range
        std::cout << Data[i] << " ";
    }

    mergeSort(Data, temp, MAX);

    std::cout << "\nDATA AFTER SORTING: ";
    for (int i = 0; i < MAX; i++) {
        std::cout << Data[i] << " ";
    }
    std::cout << "\n";

    return 0;
}
