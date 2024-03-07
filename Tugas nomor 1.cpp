#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};
Node* tail = NULL;

void buat(Node*& head, int a);
void buatAwal(Node*& head, int a);
void tampil(Node* head);
void forTail(Node* head, Node*& tail);
void sisipkanSetelah(Node*& head, int after, int value);
void sisipkanSebelum(Node*& head, int before, int value);
void pencari(Node*& head, int i);
void hapusNode(Node*& head, int key, bool byIndex);

int main() {
    Node* head = NULL;

    // 1. Menambahkan beberapa node pada awal linked list.
    buat(head, 10);
    buat(head, 30);
    buat(head, 47);
    buat(head, 76);

    // 2. Menampilkan linked list.
    tampil(head);

    // 3. Mencari sebuah simpul tertentu.
    pencari(head, 47);

    // 4. Menyisipkan setelah simpul tertentu.
    sisipkanSetelah(head, 30, 45);
    tampil(head);

    // 5. Menyisipkan sebelum simpul tertentu.
    sisipkanSebelum(head, 10, 37);
    tampil(head);

    // 6. Menghapus simpul berdasarkan index.
    hapusNode(head, 2, true);
    tampil(head);

    // 7. Menghapus simpul berdasarkan data.
    hapusNode(head, 47, false);
    tampil(head);

    // 8. Menghapus semua node di linked list.
    hapusNode(head, 0, true);

    return 0;
}

void buat(Node*& head, int a) {
    cout << "Menambahkan data >> " << a;
    Node* newNode = new Node();
    newNode->data = a;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        tail = head;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
}

void buatAwal(Node*& head, int a) {
    Node* newNode = new Node();
    newNode->data = a;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        tail = head;
    }
    else {
        newNode->next = head;
        head = newNode;
    }
}

void tampil(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void forTail(Node* head, Node*& tail) {
    tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }
    cout << "\ttail pada : " << tail->data << endl;
}

void pencari(Node*& head, int i) {
    Node* cari = head;
    while (cari->data != i) {
        cari = cari->next;
    }
    cout << "Pencarian " << cari->data << " " << cari->next << endl;
}

void sisipkanSetelah(Node*& head, int after, int value) {
    Node* newNode = new Node();
    newNode->data = value;

    Node* temp = head;
    while (temp != nullptr && temp->data != after) {
        temp = temp->next;
    }

    if (temp != nullptr) {
        newNode->next = temp->next;
        temp->next = newNode;
    }
    else {
        cout << "Data " << after << " tidak ada" << endl;
    }
    cout << "Menambahkan data >> " << value << " setelah " << after << endl;
}

void sisipkanSebelum(Node*& head, int before, int value) {
    Node* newNode = new Node();
    newNode->data = value;

    Node* temp = head;

    if (head != nullptr && head->data == before) {
        newNode->next = head;
        head = newNode;
        return;
    }

    while (temp != nullptr && temp->next->data != before) {
        temp = temp->next;
    }

    if (temp != nullptr) {
        newNode->next = temp->next;
        temp->next = newNode;
    }
    else {
        cout << "Data " << before << " tidak ada" << endl;
    }
    cout << "Menambahkan data >> " << value << " sebelum " << before << endl;
}

void hapusNode(Node*& head, int key, bool byIndex) {
    if (head == NULL) {
        cout << "Linked list kosong." << endl;
        return;
    }

    Node* prev = NULL;
    Node* current = head;

    if (byIndex) {
        if (key == 0) {
            head = head->next;
            delete current;
            cout << "Menghapus node ke-" << key << endl;
            return;
        }

        int currentIndex = 0;
        while (current != NULL && currentIndex < key) {
            prev = current;
            current = current->next;
            currentIndex++;
        }
    }
    else {
        while (current != NULL && current->data != key) {
            prev = current;
            current = current->next;
        }
    }

    if (current != NULL) {
        if (prev != NULL) {
            prev->next = current->next;
        }
        else {
            head = current->next; // Jika node yang dihapus adalah node pertama
        }
        delete current;
        if (byIndex)
            cout << "Menghapus node ke-" << key << endl;
        else
            cout << "Menghapus node dengan nilai " << key << endl;
    }
    else {
        if (byIndex)
            cout << "Indeks melebihi ukuran linked list." << endl;
        else
            cout << "Node dengan nilai " << key << " tidak ditemukan." << endl;
    }
}