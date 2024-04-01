# NAMA : ANDHIKA BINTANG RATNANTO
# NRP/Kelas : 5223600014 / Teknologi Game A - 11
## Praktikum 4 : Stack

Contoh 8,3 : Implementasi Stack Menggunakan Linked List

#include <iostream>

class ListStack {
private:
    struct Node {
        int value;
        Node* next;
        Node(int v, Node* n) : value(v), next(n) {}
    };

    Node* head = nullptr;
    int count = 0;

public:
    int size() {
        return count;
    }

    bool Empty() {
        return count == 0;
    }

    int peek() {
        if (Empty()) {
            throw std::runtime_error("ListStackEmptyException");
        }
        return head->value;
    }

    void Push(int value) {
        head = new Node(value, head);
        count++;
    }

    int Pop() {
        if (Empty()) {
            throw std::runtime_error("ListStackEmptyException");
        }
        int value = head->value;
        Node* temp = head;
        head = head->next;
        delete temp;
        count--;
        return value;
    }

    void insertAtBottom(int value) {
        if (Empty()) {
            Push(value);
        } else {
            int temp = Pop();
            insertAtBottom(value);
            Push(temp);
        }
    }

    void print() {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->value << " ";
            temp = temp->next;
        }
    }
};

int main() {
    ListStack s;
    for (int i = 1; i <= 100; i++)
        s.Push(i);
    for (int i = 1; i <= 50; i++)
        s.Pop();
    s.print();

    return 0;
}

##Program di atas adalah 
implementasi dari struktur data tumpukan (stack) menggunakan linked list dalam bahasa C++. Berikut adalah rangkumannya:

-. Kelas ListStack: Ini adalah kelas utama yang mengimplementasikan tumpukan. Di dalamnya, terdapat struktur data Node yang merepresentasikan elemen tumpukan dalam bentuk simpul (node) dari linked list.
-. Struktur Node: Digunakan untuk merepresentasikan setiap elemen dalam tumpukan. Setiap node memiliki dua atribut: value untuk menyimpan nilai elemen dan next untuk menunjukkan node selanjutnya dalam linked list.
-. Variabel-variabel: head adalah pointer yang menunjuk ke elemen paling atas tumpukan (top of stack), dan count digunakan untuk menyimpan jumlah elemen dalam tumpukan.
-. Metode size(): Mengembalikan jumlah elemen dalam tumpukan.
-. Metode Empty(): Mengembalikan true jika tumpukan kosong, dan false jika tidak.
-. Metode peek(): Mengembalikan nilai dari elemen paling atas tumpukan tanpa menghapusnya. Jika tumpukan kosong, akan memunculkan pengecualian.
-. Metode Push(int value): Menambahkan elemen baru ke atas tumpukan dengan nilai yang diberikan.
-. Metode Pop(): Menghapus elemen paling atas tumpukan dan mengembalikan nilainya. Jika tumpukan kosong, akan memunculkan pengecualian.
-. Metode insertAtBottom(int value): Memasukkan nilai ke dalam tumpukan pada posisi paling bawah dengan cara rekursif. Metode ini memanfaatkan rekursi dan metode Push() dan Pop().
-. Metode print(): Mencetak nilai semua elemen dalam tumpukan dari atas ke bawah.
-. Fungsi main(): Membuat objek dari kelas ListStack, menambahkan 100 elemen ke dalamnya, menghapus 50 elemen, dan mencetak elemen-elemen yang tersisa.
