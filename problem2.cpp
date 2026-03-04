#include <iostream>

using namespace std;

// Struktur data utama sesuai instruksi (jangan diubah)
struct DynArray {
    int* data;     // pointer to heap-allocated buffer
    int size;      // number of elements in use
    int capacity;  // total allocated slots
};

// O(1)
// Penjelasan: Hanya melakukan assignment dasar dan satu kali alokasi memori awal.
void initArray(DynArray& a) {
    a.capacity = 2;
    a.size = 0;
    a.data = new int[a.capacity]; // Mengalokasikan array di heap
}

// O(1)
// Penjelasan: Dealokasi memori yang ditunjuk oleh pointer dieksekusi dalam waktu konstan.
void freeArray(DynArray& a) {
    delete[] a.data;   // Membebaskan memori heap untuk mencegah memory leak
    a.data = nullptr;  // Praktik baik: set pointer ke null setelah di-delete
    a.size = 0;
    a.capacity = 0;
}

// O(1) amortized, O(n) worst-case
// Penjelasan: Normalnya O(1) karena kita hanya memasukkan nilai di akhir. 
// Namun jika array penuh, kita butuh O(n) untuk menyalin data ke buffer baru.
void pushBack(DynArray& a, int value) {
    // Jika kapasitas sudah penuh, gandakan kapasitasnya
    if (a.size == a.capacity) {
        a.capacity *= 2;
        int* newData = new int[a.capacity]; // 1. Allocate new buffer
        
        for (int i = 0; i < a.size; i++) {
            newData[i] = a.data[i];         // 2. Copy old data
        }
        
        delete[] a.data;                    // 3. Free old buffer
        a.data = newData;                   // 4. Update pointer
    }
    
    a.data[a.size] = value;
    a.size++;
}

// O(n)
// Penjelasan: Dalam kasus terburuk (insert di index 0), kita harus menggeser 
// semua elemen yang ada (n elemen) ke kanan.
void insertAt(DynArray& a, int index, int value) {
    // Sama seperti pushBack, periksa apakah butuh resize
    if (a.size == a.capacity) {
        a.capacity *= 2;
        int* newData = new int[a.capacity];
        for (int i = 0; i < a.size; i++) {
            newData[i] = a.data[i];
        }
        delete[] a.data;
        a.data = newData;
    }
    
    // Geser elemen dari kanan ke kiri untuk memberi ruang di 'index'
    for (int i = a.size; i > index; i--) {
        a.data[i] = a.data[i - 1];
    }
    
    a.data[index] = value;
    a.size++;
}

// O(n)
// Penjelasan: Menghapus elemen berarti kita harus menarik semua elemen 
// di sebelah kanannya ke kiri untuk menutup celah kosong.
void removeAt(DynArray& a, int index) {
    // Geser elemen dari kiri ke kanan untuk menimpa elemen yang dihapus
    for (int i = index; i < a.size - 1; i++) {
        a.data[i] = a.data[i + 1];
    }
    a.size--;
}

// O(1)
// Penjelasan: Mengakses elemen array berdasarkan indeks adalah operasi langsung.
int getAt(const DynArray& a, int index) {
    return a.data[index];
}

// O(1)
// Penjelasan: Menimpa nilai pada indeks array adalah operasi langsung.
void setAt(DynArray& a, int index, int value) {
    a.data[index] = value;
}

// O(n)
// Penjelasan: Harus mencetak satu per satu seluruh elemen array.
void printDynArr(const DynArray& a) {
    cout << "[";
    for (int i = 0; i < a.size; i++) {
        cout << a.data[i];
        if (i < a.size - 1) {
            cout << ", ";
        }
    }
    cout << "] (size=" << a.size << ", cap=" << a.capacity << ")" << endl;
}

int main() {
    DynArray arr;
    initArray(arr);

    // 1. pushBack until a resize is triggered
    for (int i = 1; i <= 5; i++) {
        pushBack(arr, i * 10);
    }
    printDynArr(arr);  // Expected: [10, 20, 30, 40, 50] (size=5, cap=8)

    // 2. insertAt
    insertAt(arr, 2, 25);
    printDynArr(arr);  // Expected: [10, 20, 25, 30, 40, 50] (size=6, cap=8)

    // 3. removeAt
    removeAt(arr, 0);
    printDynArr(arr);  // Expected: [20, 25, 30, 40, 50] (size=5, cap=8)

    // 4. getAt / setAt
    cout << "Element at index 2: " << getAt(arr, 2) << "\n";  // Expected: 30
    setAt(arr, 2, 99);
    printDynArr(arr);  // Expected: [20, 25, 99, 40, 50] (size=5, cap=8)

    // Membebaskan memori di akhir program (Sangat Penting untuk nilai 4 pts "No memory leaks")
    freeArray(arr);

    return 0;
}