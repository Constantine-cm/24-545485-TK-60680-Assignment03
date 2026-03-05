# Assignment 03 - Algoritma Stuktur Data

**Name: Christian Bo Constantine**

**Student ID: 24/545485/TK/60680** 

## Description
* **Problem 1:** Perhitungan *Cost*, *T(n)*, dan kompleksitas masing-masing kode *snippet* yang berisikan penjelasan lebih lanjut.
* **Problem 2:** Implementasi *Dynamic Array* dari awal menggunakan pendekatan prosedural (struct dan fungsi lepas) di C++, termasuk manajemen memori dinamis (*resize*, *insert*, *remove*) tanpa kebocoran memori.
* **Problem 3:** Implementasi dan perbandingan antara *Linear Search* dan *Binary Search* secara iteratif pada array yang dialokasikan di *heap*.
* **Problem 4:** Perhitungan *Growth Factor Comparison* dan analisis lebih lanjutnya.

## Compilation Commands
Mengingat saya menggunakan environment macOS dengan `clang++`, berikut adalah perintah kompilasi yang digunakan untuk memastikan tidak ada *memory leak*):
* `g++ -std=c++17 -Wall -Wextra problem2.cpp -o problem2`
* `g++ -std=c++17 -Wall -Wextra problem3.cpp -o problem3`

## Known Issues or Limitations
* Tidak ada *memory leak* yang terdeteksi pada kedua program.
* Binary search pada Problem 3 mengasumsikan input array sudah terurut (sesuai fungsi generator).

## Time Spent
* Sekitar 4 jam untuk menyelesaikan keseluruhan analisis, implementasi, dan *debugging*.
