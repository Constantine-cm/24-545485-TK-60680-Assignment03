# Assignment 03 - Algoritma Stuktur Data

**Name:Christian Bo Constantine** 
**Student ID: 24/545485/TK/60680** 

## Description
* **Problem 2:** Implementasi *Dynamic Array* dari awal menggunakan pendekatan prosedural (struct dan fungsi lepas) di C++, termasuk manajemen memori dinamis (*resize*, *insert*, *remove*) tanpa kebocoran memori.
* **Problem 3:** Implementasi dan perbandingan antara *Linear Search* dan *Binary Search* secara iteratif pada array yang dialokasikan di *heap*.

## Compilation Commands
Mengingat saya menggunakan environment macOS dengan `clang++`, berikut adalah perintah kompilasi yang digunakan (termasuk AddressSanitizer untuk memastikan tidak ada *memory leak*):
* `clang++ -fsanitize=address -g problem2.cpp -o problem2`
* `clang++ -fsanitize=address -g problem3.cpp -o problem3`

## Known Issues or Limitations
* Tidak ada *memory leak* yang terdeteksi oleh AddressSanitizer pada kedua program.
* Binary search pada Problem 3 mengasumsikan input array sudah terurut (sesuai fungsi generator).

## Time Spent
* Sekitar 4 jam untuk menyelesaikan keseluruhan analisis, implementasi, dan *debugging*.
