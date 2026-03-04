#include <iostream>

using namespace std;

// 1. Linear Search
// Menggunakan perulangan biasa untuk mencari target.
int linearSearch(int* arr, int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i; // Ditemukan, kembalikan indeks
        }
    }
    return -1; // Tidak ditemukan
}

// 2. Binary Search
// Mencari dengan membelah rentang pencarian (iteratif).
int binarySearch(int* arr, int n, int target) {
    int lo = 0;
    int hi = n - 1;
    
    while (lo <= hi) {
        // Menggunakan formula tepat seperti yang diminta di soal
        int mid = lo + (hi - lo) / 2; 
        
        if (arr[mid] == target) {
            return mid; // Ditemukan di tengah
        } else if (arr[mid] < target) {
            lo = mid + 1; // Cari di sisi kanan
        } else {
            hi = mid - 1; // Cari di sisi kiri
        }
    }
    return -1; // Tidak ditemukan
}

// 3. Generate Sorted Array
// Membuat array di heap dan mengisinya dengan bilangan genap berurutan.
int* generateSortedArray(int n) {
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        arr[i] = i * 2; // Menghasilkan {0, 2, 4, ..., 2(n-1)}
    }
    return arr;
}

// Fungsi utama untuk mendemonstrasikan algoritma
int main() {
    // Demonstrasi untuk ukuran n = 10, 100, 1000
    int sizes[] = {10, 100, 1000};
    
    for (int i = 0; i < 3; i++) {
        int n = sizes[i];
        cout << "====================================\n";
        cout << "Menguji array dengan ukuran n = " << n << "\n";
        
        // Alokasi memori
        int* arr = generateSortedArray(n);
        
        // Menentukan target:
        // Target yang ada: elemen di indeks tengah (midpoint)
        int targetExists = arr[n / 2]; 
        // Target yang tidak ada: karena array isinya genap semua, angka ganjil pasti tidak ada
        int targetMissing = -1; 

        // Skenario 1: Target ADA
        cout << "Skenario 1: Mencari target yang ADA (" << targetExists << ")\n";
        int lsResult1 = linearSearch(arr, n, targetExists);
        int bsResult1 = binarySearch(arr, n, targetExists);
        cout << "  -> Linear Search mengembalikan index : " << lsResult1 << "\n";
        cout << "  -> Binary Search mengembalikan index : " << bsResult1 << "\n";
        if (lsResult1 == bsResult1) cout << "  => KEDUA ALGORITMA SETUJU!\n";

        // Skenario 2: Target TIDAK ADA
        cout << "Skenario 2: Mencari target yang TIDAK ADA (" << targetMissing << ")\n";
        int lsResult2 = linearSearch(arr, n, targetMissing);
        int bsResult2 = binarySearch(arr, n, targetMissing);
        cout << "  -> Linear Search mengembalikan index : " << lsResult2 << "\n";
        cout << "  -> Binary Search mengembalikan index : " << bsResult2 << "\n";
        if (lsResult2 == bsResult2) cout << "  => KEDUA ALGORITMA SETUJU!\n";
        
        // PENTING: Caller bertanggung jawab membebaskan pointer (sesuai soal)
        delete[] arr;
        cout << "\n";
    }

    return 0;
}