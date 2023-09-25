#include <iostream>
using namespace std;

const int ROWS = 2;
const int COLS = 2;

// Fungsi untuk menampilkan matriks
void tampilMatriks(int matriks[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << matriks[i][j] << " ";
        }
        cout <<endl;
    }
}

// Fungsi untuk penjumlahan matriks
void penjumlahanMatriks(int matriksA[][COLS], int matriksB[][COLS], int hasil[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            hasil[i][j] = matriksA[i][j] + matriksB[i][j];
        }
    }
}

// Fungsi untuk pengurangan matriks
void penguranganMatriks(int matriksA[][COLS], int matriksB[][COLS], int hasil[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            hasil[i][j] = matriksA[i][j] - matriksB[i][j];
        }
    }
}

// Fungsi untuk perkalian dengan skalar
void perkalianSkalar(int matriks[][COLS], int skalar) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            matriks[i][j] *= skalar;
        }
    }
}

// Fungsi untuk perkalian matriks
void perkalianMatriks(int matriksA[][COLS], int matriksB[][COLS], int hasil[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            hasil[i][j] = 0;
            for (int k = 0; k < COLS; k++) {
                hasil[i][j] += matriksA[i][k] * matriksB[k][j];
            }
        }
    }
}

int main() {
    int matriksA[ROWS][COLS] = {{1, 3}, {2, 4}};
    int matriksB[ROWS][COLS] = {{1, 3}, {2, 4}};
    int hasil[ROWS][COLS];

    char pilihan;
    do {
        cout << "Daftar Menu Operasi Matriks:" << std::endl;
        cout << "1. Penjumlahan" << std::endl;
        cout << "2. Pengurangan" << std::endl;
        cout << "3. Perkalian Skalar (n)" << std::endl;
        cout << "4. Perkalian Matriks A dan Matriks B" << std::endl;
        cout << "Pilih operasi (1/2/3/4): ";
        cin >> pilihan;

        switch (pilihan) {
            case '1':
                penjumlahanMatriks(matriksA, matriksB, hasil);
                cout << "Hasil Penjumlahan Matriks:" <<endl;
                tampilMatriks(hasil);
                break;
            case '2':
                penguranganMatriks(matriksA, matriksB, hasil);
                cout << "Hasil Pengurangan Matriks:" << endl;
                tampilMatriks(hasil);
                break;
            case '3':
                int skalar;
                cout << "Masukkan nilai skalar (n): ";
                cin >> skalar;
                perkalianSkalar(matriksA, skalar);
                cout << "Hasil Perkalian Skalar:" << endl;
                tampilMatriks(matriksA);
                break;
            case '4':
                perkalianMatriks(matriksA, matriksB, hasil);
                cout << "Hasil Perkalian Matriks A dan Matriks B:" << endl;
                tampilMatriks(hasil);
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
        }

        cout << "Apakah Anda ingin memilih operasi lagi? (Y/N): ";
        cin >> pilihan;

    } while (pilihan == 'Y' || pilihan == 'y');

    return 0;
}

