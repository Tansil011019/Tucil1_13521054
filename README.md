# Tucil1_13521054
Tugas Kecil 1 IF2211 Strategi Algoritma
<br />
Penyelesaian Permainan Kartu 24 dengan Algoritma Brute Force

## Table of Contents
* [General Info](#general-information)
* [How To Run](#how-to-run)
* [Tech Stack](#tech-stack)
* [Project Structure](#project-structure)
* [Credits](#credits)

## General Information
Permainan kartu 24 adalah permainan kartu aritmatika dengan tujuan mencari cara untuk mengubah 4 buah angka random sehingga mendapatkan hasil akhir sejumlah 24. Permainan ini menarik cukup banyak peminat dikarenakan dapat meningkatkan kemampuan berhitung serta mengasah otak agar dapat berpikir dengan cepat dan akurat. Permainan Kartu 24 biasa dimainkan dengan menggunakan kartu remi. Kartu remi terdiri dari 52 kartu yang terbagi menjadi empat suit (sekop, hati, keriting, dan wajik) yang masing-masing terdiri dari 13 kartu (As, 2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, dan King). Yang perlu diperhatikan hanyalah nilai kartu yang didapat (As, 2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, dan King). As bernilai 1, Jack bernilai 11, Queen bernilai 12, King bernilai 13, sedangkan kartu bilangan memiliki nilai dari bilangan itu sendiri. Pada awal permainan moderator atau salah satu pemain mengambil 4 kartu dari dek yang sudah dikocok secara random. Permainan berakhir ketika pemain berhasil menemukan solusi untuk membuat kumpulan nilainya menjadi 24. Pengubahan nilai tersebut dapat dilakukan menggunakan operasi dasar matematika penjumlahan (+), pengurangan (-), perkalian (×), divisi (/) dan tanda kurung ( () ). Tiap kartu harus digunakan tepat sekali dan urutan penggunaannya bebas.

## How To Run
### Run Using Windows Batch File
1. Di terminal (cmd), jalankan:
```shell
run.bat
```
2. Atau double klik pada file `run.bat`

### Run Manually 
1. Pastikan anda berada pada dir `bin` dengan :
```shell
cd bin
```
3. Jalankan perintah berikut:
```shell
./out
```

## Tech Stack
### Programming Languange
* C language 6.3.0

### Libraries
* string.h
* time.h
* stdio.h
* stdlib.h

## Project Structure
```bash
.
├── README.md
├── run.bat
│
├── bin
│    │
│    └── out.exe
│
├── doc
│    │
│    └── Tucil1_K2_13521054_Wilson Tansil.pdf
│
├── src
│    │
│    └── 24games.c
│
└── test
     ├── test1.txt
     ├── test2.txt
     ├── test3.txt
     ├── test4.txt
     ├── test5.txt
     └── test6.txt
     
```

## Credits
This project is implemented by: Wilson Tansil (13521054)
