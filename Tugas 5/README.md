# NAMA : ANDHIKA BINTANG RATNANTO
# NRP/Kelas : 5223600014 / Teknologi Game A - 11
## Praktikum 5 : Queue

### Contoh 9,2 : Queue Menggunakan Linked List

```cpp
#include <iostream>
#include <stdexcept>

class Queue {
private:
    struct Node {
        int value;
        Node* next;
        Node(int v, Node* n) : value(v), next(n) {}
    };

    Node* head = nullptr;
    Node* tail = nullptr;
    int count = 0;

public:
    int size() {
        return count;
    }

    bool Empty() {
        return count == 0;
    }

    void print() {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->value << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    int peek() {
        if (Empty()) {
            throw std::runtime_error("QueueEmptyException");
        }
        return head->value;
    }

    void enqueue(int value) {
        Node* newNode = new Node(value, nullptr);
        if (Empty()) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        count++;
    }

    int dequeue() {
        if (Empty()) {
            throw std::runtime_error("QueueEmptyException");
        }
        int value = head->value;
        Node* temp = head;
        head = head->next;
        delete temp;
        count--;
        return value;
    }

    ~Queue() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    std::cout << "Queue size: " << q.size() << std::endl;
    std::cout << "Queue elements: ";
    q.print();

    std::cout << "Front element: " << q.peek() << std::endl;

    std::cout << "Dequeue: " << q.dequeue() << std::endl;
    std::cout << "Queue size after dequeue: " << q.size() << std::endl;
    std::cout << "Queue elements after dequeue: ";
    q.print();

    return 0;
}

```

### Program di atas adalah
implementasi dari kelas `Queue` dalam C++. 

- Kelas `Queue` memiliki tiga atribut data pribadi (`head`, `tail`, `count`) dan sebuah struktur internal `Node` yang merepresentasikan elemen-elemen dalam antrian.
- Metode `size()` digunakan untuk mengembalikan jumlah elemen dalam antrian.
- Metode `Empty()` mengembalikan `true` jika antrian kosong, dan `false` jika tidak.
- Metode `print()` mencetak semua elemen dalam antrian.
- Metode `peek()` mengembalikan nilai dari elemen pertama dalam antrian tanpa menghapusnya. Jika antrian kosong, metode ini akan melemparkan pengecualian `std::runtime_error`.
- Metode `enqueue(int value)` menambahkan elemen baru ke dalam antrian.
- Metode `dequeue()` menghapus dan mengembalikan nilai dari elemen pertama dalam antrian. Jika antrian kosong, metode ini juga akan melemparkan pengecualian `std::runtime_error`.
- Destruktor (`~Queue()`) digunakan untuk membersihkan memori yang dialokasikan untuk elemen-elemen antrian.

Fungsi `main()` adalah program utama yang menunjukkan penggunaan kelas `Queue`. Program tersebut membuat objek `q` dari kelas `Queue`, menambahkan beberapa elemen ke antrian, mencetak ukuran antrian dan elemen-elemennya, mengambil nilai dari elemen pertama tanpa menghapusnya, menghapus elemen pertama, dan mencetak ukuran antrian dan elemen-elemennya lagi untuk menunjukkan efek dari operasi enqueue dan dequeue.

### Contoh 9,3 :

```cpp
void add(int value) {
    Node* temp = new Node(value, nullptr);
    if (head == nullptr) {
        head = tail = temp;
    } else {
        tail->next = temp;
        tail = temp;
    }
    count++;
}

```
### Program di atas adalah 
implementasi metode `add` dalam kelas `Queue` yang bertujuan untuk menambahkan elemen baru ke dalam antrian. Berikut rangkuman penjelasannya:

1. Sebuah node baru (`temp`) dibuat dengan nilai yang diberikan dan `next` diatur menjadi `nullptr`.
2. Jika `head` adalah `nullptr`, yang menandakan antrian kosong, maka `head` dan `tail` diatur untuk menunjuk ke node baru tersebut.
3. Jika tidak, yaitu jika antrian tidak kosong, maka node baru (`temp`) ditambahkan sebagai elemen terakhir dalam antrian dengan mengatur `next` dari `tail` menjadi `temp`, kemudian `tail` diperbarui untuk menunjuk ke node baru tersebut.
4. Setelah menambahkan elemen baru, jumlah elemen dalam antrian (`count`) diperbarui dengan menambahkan 1.

### Contoh 9,4

```cpp
#include <iostream>
#include <stdexcept>

class Queue {
private:
    struct Node {
        int value;
        Node* next;
        Node(int v, Node* n) : value(v), next(n) {}
    };

    Node* head = nullptr;
    Node* tail = nullptr;
    int count = 0;

public:
    int size() {
        return count;
    }

    bool Empty() {
        return count == 0;
    }

    void print() {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->value << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    int remove() {
        if (Empty()) {
            throw std::runtime_error("QueueEmptyException");
        }
        int value = head->value;
        Node* temp = head;
        head = head->next;
        delete temp;
        count--;
        return value;
    }

    void add(int value) {
        Node* temp = new Node(value, nullptr);
        if (head == nullptr) {
            head = tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
        count++;
    }

    ~Queue() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    Queue q;
    for (int i = 1; i <= 100; i++) {
        q.add(i);
    }
    for (int i = 1; i <= 50; i++) {
        q.remove();
    }
    q.print();

    return 0;
}
```
### Program di atas adalah
mengimplementasikan kelas `Queue` dalam C++ yang memiliki kemampuan untuk menambahkan elemen baru, menghapus elemen, dan mencetak elemen-elemen yang tersisa dalam antrian. Berikut adalah rangkuman penjelasannya:

- Kelas `Queue` memiliki struktur data internal `Node`, yang memiliki dua anggota: `value` (nilai dari elemen) dan `next` (pointer ke node selanjutnya dalam antrian).
- Kelas `Queue` memiliki tiga atribut data pribadi: `head` (pointer ke elemen pertama dalam antrian), `tail` (pointer ke elemen terakhir dalam antrian), dan `count` (jumlah elemen dalam antrian).
- Metode `size()` digunakan untuk mengembalikan jumlah elemen dalam antrian.
- Metode `Empty()` mengembalikan `true` jika antrian kosong, dan `false` jika tidak.
- Metode `print()` mencetak semua elemen dalam antrian.
- Metode `remove()` menghapus dan mengembalikan nilai dari elemen pertama dalam antrian. Jika antrian kosong, metode ini akan melemparkan pengecualian `std::runtime_error`.
- Metode `add(int value)` menambahkan elemen baru ke dalam antrian. 
- Destruktor (`~Queue()`) digunakan untuk membersihkan memori yang dialokasikan untuk elemen-elemen antrian.
- Dalam fungsi `main()`, sebuah objek `q` dari kelas `Queue` dibuat. Kemudian, sebuah loop `for` digunakan untuk menambahkan 100 elemen ke dalam antrian. Setelah itu, loop `for` lainnya digunakan untuk menghapus 50 elemen pertama dari antrian. Akhirnya, elemen-elemen yang tersisa dalam antrian dicetak.

### Contoh 9,5 : 

```cpp
#include <iostream>
#include <stack>
#include <stdexcept>

class QueueUsingStack {
private:
    std::stack<int> stk1;
    std::stack<int> stk2;

public:
    QueueUsingStack() {}

    void add(int value) {
        stk1.push(value);
    }

    int remove() {
        int value;
        if (!stk2.empty()) {
            value = stk2.top();
            stk2.pop();
            return value;
        }
        while (!stk1.empty()) {
            value = stk1.top();
            stk1.pop();
            stk2.push(value);
        }
        if (stk2.empty()) {
            throw std::runtime_error("QueueEmptyException");
        }
        value = stk2.top();
        stk2.pop();
        return value;
    }
};

int main() {
    QueueUsingStack que;
    que.add(1);
    que.add(11);
    que.add(111);
    std::cout << que.remove() << std::endl;
    que.add(2);
    que.add(21);
    que.add(211);
    std::cout << que.remove() << std::endl;
    std::cout << que.remove() << std::endl;

    return 0;
}
```
### Program di atas adalah 
implementasi dari antrian (queue) yang menggunakan dua tumpukan (stack) dalam bahasa C++.

- Kelas `QueueUsingStack` memiliki dua tumpukan (`stk1` dan `stk2`) sebagai atribut data pribadi.
- Metode `add(int value)` digunakan untuk menambahkan nilai ke dalam tumpukan pertama (`stk1`).
- Metode `remove()` menghapus dan mengembalikan nilai dari antrian. Jika `stk2` tidak kosong, maka nilai langsung diambil dari `stk2`. Jika `stk2` kosong, maka nilai-nilai dari `stk1` dipindahkan ke `stk2` satu per satu, dan nilai paling atas dari `stk2` kemudian diambil dan dihapus.
- Dalam fungsi `main()`, objek `que` dari kelas `QueueUsingStack` dibuat, nilai-nilai ditambahkan ke dalam antrian menggunakan `add()`, dan nilai-nilai kemudian dihapus dari antrian menggunakan `remove()` dan dicetak.

### Permasalahan Reverse a Stack

```cpp
#include <iostream>
#include <stack>
#include <queue>


void reverseStack(std::stack<int>& stk) {
    std::queue<int> q;
    
  
    while (!stk.empty()) {
        q.push(stk.top());
        stk.pop();
    }
    

    while (!q.empty()) {
        stk.push(q.front());
        q.pop();
    }
}


void printStack(std::stack<int> stk) {
    while (!stk.empty()) {
        std::cout << stk.top() << " ";
        stk.pop();
    }
    std::cout << std::endl;
}

int main() {
    std::stack<int> stk;
    
    
    stk.push(1);
    stk.push(2);
    stk.push(3);
    stk.push(4);
    stk.push(5);
    
    std::cout << "Original Stack: ";
    printStack(stk);
    
    
    reverseStack(stk);
    
    std::cout << "Reversed Stack: ";
    printStack(stk);
    
    return 0;
}
```
### Program di atas adalah 
implementasi dari fungsi untuk membalikkan tumpukan menggunakan sebuah antrean dalam bahasa C++.

- Fungsi `reverseStack` menerima referensi ke tumpukan (`std::stack<int>&`) sebagai argumen dan melakukan langkah-langkah untuk membalikkan elemen-elemen dalam tumpukan menggunakan sebuah antrean.
  - Pada langkah a, semua elemen dari tumpukan dipop satu per satu dan dimasukkan ke dalam sebuah antrean.
  - Pada langkah b, semua elemen dari antrean dipop satu per satu dan dimasukkan kembali ke dalam tumpukan, sehingga menghasilkan tumpukan yang terbalik.
- Fungsi `printStack` digunakan untuk mencetak elemen-elemen dalam tumpukan.
- Dalam fungsi `main`, beberapa elemen dimasukkan ke dalam tumpukan, kemudian tumpukan tersebut dicetak, kemudian dibalikkan menggunakan fungsi `reverseStack`, dan hasilnya dicetak kembali.

Program ini menunjukkan bagaimana kita dapat menggunakan sebuah antrean untuk membalikkan tumpukan. Dengan memanfaatkan sifat FIFO (First-In-First-Out) dari antrean, kita dapat membalikkan urutan elemen-elemen dalam tumpukan.

### Permasalahan Reverse a Queue

```cpp
#include <iostream>
#include <queue>
#include <stack>


void reverseQueue(std::queue<int>& q) {
    std::stack<int> stk;

    
    while (!q.empty()) {
        stk.push(q.front());
        q.pop();
    }

    
    while (!stk.empty()) {
        q.push(stk.top());
        stk.pop();
    }
}


void printQueue(std::queue<int> q) {
    while (!q.empty()) {
        std::cout << q.front() << " ";
        q.pop();
    }
    std::cout << std::endl;
}

int main() {
    std::queue<int> q;

    
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    std::cout << "Original Queue: ";
    printQueue(q);

    // Reverse the queue
    reverseQueue(q);

    std::cout << "Reversed Queue: ";
    printQueue(q);

    return 0;
}
```

### Program di atas adalah 
implementasi untuk membalikkan sebuah antrian (queue) menggunakan sebuah tumpukan (stack) dalam bahasa C++.

- Fungsi `reverseQueue` menerima referensi ke sebuah antrian (`std::queue<int>&`) sebagai argumen dan melakukan langkah-langkah untuk membalikkan elemen-elemen dalam antrian menggunakan sebuah tumpukan.
  - Pada langkah a, semua elemen dari antrian dipindahkan ke dalam sebuah tumpukan.
  - Pada langkah b, semua elemen dari tumpukan dipindahkan kembali ke dalam antrian, sehingga menghasilkan antrian yang terbalik.
- Fungsi `printQueue` digunakan untuk mencetak elemen-elemen dalam antrian.
- Di dalam fungsi `main`, beberapa elemen dimasukkan ke dalam antrian, kemudian antrian tersebut dicetak, kemudian dibalikkan menggunakan fungsi `reverseQueue`, dan hasilnya dicetak kembali.

Program ini menunjukkan cara menggunakan tumpukan untuk membalikkan urutan elemen-elemen dalam sebuah antrian. Dengan memanfaatkan sifat LIFO (Last-In-First-Out) dari tumpukan, kita dapat mencapai tujuan ini dengan mengeluarkan semua elemen dari antrian ke dalam tumpukan, lalu mengeluarkan kembali elemen-elemen tersebut dari tumpukan ke dalam antrian, sehingga menghasilkan antrian yang terbalik.
