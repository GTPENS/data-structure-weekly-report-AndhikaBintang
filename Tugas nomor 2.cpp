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
    int nilai, after, before;

    int pilihan;
    do {
        cout << "\nMenu Pilihan:\n";
        cout << "1. Menyisipkan sebagai node dari linked list.\n";
        cout << "2. Membaca atau menampilkan linked list.\n";
        cout << "3. Mencari sebuah simpul tertentu.\n";
        cout << "4. Menyisipkan sebagai simpul terakhir.\n";
        cout << "5. Menghapus node berdasarkan indeks.\n";
        cout << "6. Menghapus node berdasarkan nilai data.\n";
        cout << "7. Keluar.\n";
        cout << "Pilihan Anda: ";
        cin >> pilihan;

        switch (pilihan) {
        case 1:
            cout << "Masukkan nilai yang ingin disisipkan: ";
            cin >> nilai;
            buatAwal(head, nilai);
            break;
        case 2:
            tampil(head);
            break;
        case 3:
            cout << "Masukkan nilai yang ingin dicari: ";
            cin >> nilai;
            pencari(head, nilai);
            break;
        case 4:
            cout << "Masukkan nilai yang ingin disisipkan: ";
            cin >> nilai;
            buat(head, nilai);
            break;
        case 5:
            cout << "Masukkan indeks node yang ingin dihapus: ";
            cin >> nilai;
            hapusNode(head, nilai, true);
            break;
        case 6:
            cout << "Masukkan nilai data node yang ingin dihapus: ";
            cin >> nilai;
            hapusNode(head, nilai, false);
            break;
        case 7:
            cout << "Keluar dari program.\n";
            break;
        default:
            cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }
    } while (pilihan != 7);

    // Hapus semua node sebelum keluar dari program
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
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
    forTail(head, tail);
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
    cout << "pencarian " << cari->data << " " << cari->next << endl;
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
