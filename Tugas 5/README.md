# NAMA : ANDHIKA BINTANG RATNANTO
# NRP/Kelas : 5223600014 / Teknologi Game A - 11
## Praktikum 4 : Stack

### Contoh 8,3 : Implementasi Stack Menggunakan Linked List

```cpp
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
```

### Program di atas adalah 
implementasi dari struktur data tumpukan (stack) menggunakan linked list dalam bahasa C++. Berikut adalah rangkumannya:

- **Kelas ListStack**: Ini adalah kelas utama yang mengimplementasikan tumpukan. Di dalamnya, terdapat struktur data `Node` yang merepresentasikan elemen tumpukan dalam bentuk simpul (node) dari linked list.
- **Struktur Node**: Digunakan untuk merepresentasikan setiap elemen dalam tumpukan. Setiap node memiliki dua atribut: `value` untuk menyimpan nilai elemen dan `next` untuk menunjukkan node selanjutnya dalam linked list.
- **Variabel-variabel**: `head` adalah pointer yang menunjuk ke elemen paling atas tumpukan (top of stack), dan `count` digunakan untuk menyimpan jumlah elemen dalam tumpukan.
- **Metode `size()`**: Mengembalikan jumlah elemen dalam tumpukan.
- **Metode `Empty()`**: Mengembalikan `true` jika tumpukan kosong, dan `false` jika tidak.
- **Metode `peek()`**: Mengembalikan nilai dari elemen paling atas tumpukan tanpa menghapusnya. Jika tumpukan kosong, akan memunculkan pengecualian.
- **Metode `Push(int value)`**: Menambahkan elemen baru ke atas tumpukan dengan nilai yang diberikan.
- **Metode `Pop()`**: Menghapus elemen paling atas tumpukan dan mengembalikan nilainya. Jika tumpukan kosong, akan memunculkan pengecualian.
- **Metode `insertAtBottom(int value)`**: Memasukkan nilai ke dalam tumpukan pada posisi paling bawah dengan cara rekursif. Metode ini memanfaatkan rekursi dan metode `Push()` dan `Pop()`.
- **Metode `print()`**: Mencetak nilai semua elemen dalam tumpukan dari atas ke bawah.
- **Fungsi `main()`**: Membuat objek dari kelas `ListStack`, menambahkan 100 elemen ke dalamnya, menghapus 50 elemen, dan mencetak elemen-elemen yang tersisa.

### Contoh 8,4 : Keseimbangan Simbol

```cpp
#include <iostream>
#include <stack>
#include <string>

bool isBalancedParenthesis(const std::string& expn) {
    std::stack<char> stk;
    for (char ch : expn) {
        switch (ch) {
            case '{':
            case '[':
            case '(':
                stk.push(ch);
                break;
            case '}':
                if (stk.empty() || stk.top() != '{') {
                    return false;
                }
                stk.pop();
                break;
            case ']':
                if (stk.empty() || stk.top() != '[') {
                    return false;
                }
                stk.pop();
                break;
            case ')':
                if (stk.empty() || stk.top() != '(') {
                    return false;
                }
                stk.pop();
                break;
        }
    }
    return stk.empty();
}

int main() {
    std::string expn = "{()}[";
    bool value = isBalancedParenthesis(expn);
    std::cout << "Given Expn: " << expn << std::endl;
    std::cout << "Result after isParenthesisMatched: " << std::boolalpha << value << std::endl;

    return 0;
}
```
### Program di atas adalah 
implementasi fungsi `isBalancedParenthesis()` dalam bahasa C++. Fungsi ini bertujuan untuk memeriksa apakah urutan kurung buka dan kurung tutup dalam sebuah ekspresi matematika atau logika telah seimbang.

- Fungsi `isBalancedParenthesis()` menerima string `expn` yang merupakan ekspresi yang akan diperiksa keseimbangannya.
- Di dalam fungsi tersebut, kita menggunakan objek `std::stack` dari pustaka standar C++ untuk menyimpan karakter kurung buka yang ditemukan.
- Selama iterasi melalui setiap karakter dalam `expn`, karakter kurung buka disimpan dalam tumpukan.
- Ketika ditemui karakter kurung tutup, kita memeriksa apakah tumpukan kosong atau apakah karakter kurung buka yang sesuai berada di atas tumpukan. Jika tidak, itu berarti ekspresi tidak seimbang, dan fungsi mengembalikan `false`.
- Jika karakter kurung tutup cocok dengan karakter kurung buka yang sesuai di tumpukan, kita menghapus karakter tersebut dari tumpukan.
- Setelah iterasi selesai, jika tumpukan kosong, itu berarti semua kurung buka telah ditutup dengan benar, dan fungsi mengembalikan `true`; jika tidak, itu berarti masih ada kurung buka yang tidak tertutup, dan fungsi mengembalikan `false`.
- Fungsi `main()` menggunakan fungsi `isBalancedParenthesis()` untuk memeriksa ekspresi `{()}[`, kemudian mencetak hasilnya ke konsol.

### Contoh 8,5 : Konversi Infix menjadi Postfix 

```cpp
#include <iostream>
#include <stack>
#include <string>

int precedence(char op) {
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/' || op == '%')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return -1;
}

std::string infixToPostfix(const std::string& expn) {
    std::stack<char> stk;
    std::string output = "";
    char temp;
    for (char ch : expn) {
        if (ch >= '0' && ch <= '9') {
            output += ch;
        } else {
            switch (ch) {
                case '+':
                case '-':
                case '*':
                case '/':
                case '%':
                case '^':
                    while (!stk.empty() && precedence(ch) <= precedence(stk.top())) {
                        temp = stk.top();
                        stk.pop();
                        output += " ";
                        output += temp;
                    }
                    stk.push(ch);
                    output += " ";
                    break;
                case '(':
                    stk.push(ch);
                    break;
                case ')':
                    while (!stk.empty() && (temp = stk.top()) != '(') {
                        stk.pop();
                        output += " ";
                        output += temp;
                        output += " ";
                    }
                    stk.pop();
                    break;
            }
        }
    }
    while (!stk.empty()) {
        temp = stk.top();
        stk.pop();
        output += " ";
        output += temp;
    }
    return output;
}

int main() {
    std::string expn = "10+((3))*5/(16-4)";
    std::string value = infixToPostfix(expn);
    std::cout << "Infix Expn: " << expn << std::endl;
    std::cout << "Postfix Expn: " << value << std::endl;

    return 0;
}
```
### Program di atas adalah
mengimplementasikan fungsi `infixToPostfix` dalam bahasa C++. Fungsi ini bertujuan untuk mengonversi ekspresi matematika dalam bentuk infix menjadi bentuk postfix.

- Fungsi `precedence` digunakan untuk menentukan prioritas operator. Operator dengan prioritas yang lebih tinggi memiliki nilai yang lebih tinggi.
- Fungsi `infixToPostfix` menerima string `expn` yang merupakan ekspresi matematika dalam bentuk infix.
- Selama iterasi melalui setiap karakter dalam `expn`, karakter angka ditambahkan langsung ke output, sedangkan operator dan tanda kurung diatur menggunakan tumpukan (`std::stack<char>`).
- Ketika ditemukan operator, program memeriksa prioritasnya dengan operator di tumpukan. Jika prioritas operator yang baru lebih rendah atau sama dengan operator di tumpukan, operator di tumpukan dipindahkan ke output sebelum operator baru ditambahkan ke tumpukan.
- Ketika ditemukan tanda kurung buka (`(`), program langsung menambahkannya ke tumpukan.
- Ketika ditemukan tanda kurung tutup (`)`), program mengeluarkan operator dari tumpukan dan menambahkannya ke output sampai menemukan tanda kurung buka yang sesuai.
- Setelah selesai iterasi, program mengeluarkan semua operator yang tersisa dari tumpukan ke output.
- Fungsi `main` digunakan untuk menguji fungsi `infixToPostfix`, mengonversi ekspresi infix `"10+((3))*5/(16-4)"` menjadi bentuk postfix, dan mencetak hasilnya ke konsol.

### Contoh 8,6 : Konversi Infix menjadi Prefix

```cpp
#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

int precedence(char op) {
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/' || op == '%')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return -1;
}

void replaceParanthesis(char* a, int length) {
    for (int i = 0; i < length; ++i) {
        if (a[i] == '(') {
            a[i] = ')';
        } else if (a[i] == ')') {
            a[i] = '(';
        }
    }
}

void reverseString(char* expn, int length) {
    int lower = 0;
    int upper = length - 1;
    char tempChar;
    while (lower < upper) {
        tempChar = expn[lower];
        expn[lower] = expn[upper];
        expn[upper] = tempChar;
        lower++;
        upper--;
    }
}

std::string infixToPostfix(std::string expn) {
    std::stack<char> stk;
    std::string output = "";
    char temp;
    for (char ch : expn) {
        if (ch >= '0' && ch <= '9') {
            output += ch;
        } else {
            switch (ch) {
                case '+':
                case '-':
                case '*':
                case '/':
                case '%':
                case '^':
                    while (!stk.empty() && precedence(ch) <= precedence(stk.top())) {
                        temp = stk.top();
                        stk.pop();
                        output += " ";
                        output += temp;
                    }
                    stk.push(ch);
                    output += " ";
                    break;
                case '(':
                    stk.push(ch);
                    break;
                case ')':
                    while (!stk.empty() && (temp = stk.top()) != '(') {
                        stk.pop();
                        output += " ";
                        output += temp;
                        output += " ";
                    }
                    stk.pop();
                    break;
            }
        }
    }
    while (!stk.empty()) {
        temp = stk.top();
        stk.pop();
        output += " ";
        output += temp;
    }
    return output;
}

std::string infixToPrefix(std::string expn) {
    std::reverse(expn.begin(), expn.end());
    replaceParanthesis(&expn[0], expn.length());
    expn = infixToPostfix(expn);
    std::reverse(expn.begin(), expn.end());
    return expn;
}

int main() {
    std::string expn = "10+((3))*5/(16-4)";
    std::string value = infixToPrefix(expn);
    std::cout << "Infix Expn: " << expn << std::endl;
    std::cout << "Prefix Expn: " << value << std::endl;

    return 0;
}
```
### Program di atas adalah 
sebuah program dalam bahasa C++ yang mengonversi ekspresi matematika dari bentuk infix menjadi bentuk prefix. 

- Fungsi `precedence` digunakan untuk menentukan prioritas operator.
- Fungsi `replaceParanthesis` digunakan untuk mengubah tanda kurung buka menjadi tanda kurung tutup, dan sebaliknya.
- Fungsi `reverseString` digunakan untuk membalikkan string.
- Fungsi `infixToPostfix` mengonversi ekspresi infix menjadi bentuk postfix.
- Fungsi `infixToPrefix` mengonversi ekspresi infix menjadi bentuk prefix dengan cara membalikkan string, mengganti tanda kurung, mengonversi ke postfix, dan membalikkan kembali hasilnya.
- Di dalam `main`, ekspresi infix `"10+((3))*5/(16-4)"` dikonversi menjadi bentuk prefix menggunakan fungsi `infixToPrefix`, dan hasilnya dicetak ke konsol.

### Contoh 8,7 : Evaluasi Postfix

```cpp
#include <iostream>
#include <stack>
#include <string>

int postfixEvaluate(std::string expn) {
    std::stack<int> stk;
    size_t pos = 0;
    while (pos < expn.length()) {
        if (expn[pos] == ' ') {
            pos++;
            continue;
        }
        if (expn[pos] == '+' || expn[pos] == '-' || expn[pos] == '*' || expn[pos] == '/') {
            int num2 = stk.top();
            stk.pop();
            int num1 = stk.top();
            stk.pop();
            switch (expn[pos]) {
                case '+':
                    stk.push(num1 + num2);
                    break;
                case '-':
                    stk.push(num1 - num2);
                    break;
                case '*':
                    stk.push(num1 * num2);
                    break;
                case '/':
                    stk.push(num1 / num2);
                    break;
            }
        } else {
            int num = std::stoi(expn.substr(pos));
            stk.push(num);
            while (pos < expn.length() && expn[pos] != ' ')
                pos++;
        }
        pos++;
    }
    return stk.top();
}

int main() {
    std::string expn = "6 5 2 3 + 8 * + 3 + *";
    int value = postfixEvaluate(expn);
    std::cout << "Given Postfix Expn: " << expn << std::endl;
    std::cout << "Result after Evaluation: " << value << std::endl;
    return 0;
}
```

### Program di atas adalah 
implementasi dari evaluasi ekspresi postfix menggunakan stack dalam bahasa C++. 

- Fungsi `postfixEvaluate` mengambil string ekspresi postfix sebagai input dan mengembalikan hasil evaluasi ekspresi tersebut.
- Dalam fungsi `postfixEvaluate`, kita menggunakan stack untuk menyimpan operan dan melakukan operasi ketika menemui operator.
- Iterasi dilakukan pada string ekspresi postfix. Jika karakter yang ditemui adalah spasi, kita lanjutkan ke karakter berikutnya. Jika karakter adalah operator (`+`, `-`, `*`, `/`), kita ambil dua operand dari stack, lakukan operasi yang sesuai, dan hasilnya dimasukkan kembali ke stack.
- Jika karakter adalah operand, kita konversi string menjadi integer menggunakan `std::stoi` dan masukkan nilai tersebut ke dalam stack. Kami memeriksa apakah karakter berikutnya adalah spasi untuk menemukan batas operand yang tepat.
- Setelah iterasi selesai, nilai teratas dalam stack adalah hasil evaluasi ekspresi postfix, yang kemudian dikembalikan.
- Di dalam fungsi `main`, kita menggunakan string ekspresi postfix `"6 5 2 3 + 8 * + 3 + *"` sebagai contoh, dan mencetak hasil evaluasinya.

### Palindrome String Menggunakan Stack: 

```cpp
#include <iostream>
#include <stack>
#include <string>

bool isPalindrome(const std::string& str) {
    std::stack<char> charStack;
    int length = str.length();

    // Push characters from the first half of the string into the stack
    for (int i = 0; i < length / 2; ++i) {
        charStack.push(str[i]);
    }

    int i = length / 2 + (length % 2); // Starting index for comparison
    while (!charStack.empty() && i < length) {
        if (str[i] != charStack.top()) {
            return false; // Not a palindrome
        }
        charStack.pop();
        ++i;
    }

    return true; // Palindrome
}

int main() {
    std::string str;
    std::cout << "Enter a string: ";
    std::cin >> str;

    if (isPalindrome(str)) {
        std::cout << "The string \"" << str << "\" is a palindrome." << std::endl;
    } else {
        std::cout << "The string \"" << str << "\" is not a palindrome." << std::endl;
    }

    return 0;
}
```
### Program di atas adalah 
sebuah program C++ yang bertujuan untuk menentukan apakah sebuah string merupakan palindrome atau bukan menggunakan konsep stack. Berikut rangkuman penjelasan singkatnya:

- Fungsi `isPalindrome` menerima sebuah string sebagai parameter dan mengembalikan nilai boolean yang menunjukkan apakah string tersebut adalah palindrome atau tidak.
- Dalam fungsi `isPalindrome`, karakter-karakter dari setengah pertama string dimasukkan ke dalam stack.
- Kemudian, dilakukan iterasi pada setengah kedua string untuk membandingkan karakternya dengan karakter yang dikeluarkan dari stack. Jika ada perbedaan, maka string tersebut bukan palindrome.
- Program kemudian mencetak pesan yang sesuai berdasarkan hasil pengecekan.
- Fungsi `main` mengambil input string dari pengguna dan memanggil fungsi `isPalindrome` untuk menentukan apakah string tersebut palindrome atau tidak.
