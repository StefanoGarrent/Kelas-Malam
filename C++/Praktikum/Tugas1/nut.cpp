#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <iomanip>

using namespace std;

struct Film {
    int id;
    char judul[100];
    char genre[50];
    double rating;
};

const int MAX_FILM = 100;

int loadFilm(Film arr[]) {
    FILE *file = fopen("netfilm_db.txt", "r");
    if (file == NULL) {
        return 0;
    }

    int i = 0;
    while (i < MAX_FILM && fscanf(file, " %d;%99[^;];%49[^;];%lf", &arr[i].id, arr[i].judul, arr[i].genre, &arr[i].rating) == 4) {
        i++;
    }

    fclose(file);
    return i;
}

void saveFilm(const Film arr[], int jumlahFilm) {
    FILE *file = fopen("netfilm_db.txt", "w");
    if (file == NULL) {
        cout << "Gagal membuka file netfilm_db.txt" << endl;
        return;
    }

    for (int i = 0; i < jumlahFilm; i++) {
        // Delimiter ';' menjaga judul/genre yang mengandung spasi tetap terbaca benar.
        fprintf(file, "%d;%s;%s;%.1lf\n", arr[i].id, arr[i].judul, arr[i].genre, arr[i].rating);
    }

    fclose(file);
}

void katalogFilm(const Film arr[], int jumlahFilm) {
    system("cls");
    cout << "       N E T F I L M   C O N T E N T   K A T A L O G       " << endl;
    cout << "-----------------------------------------------------------" << endl;
    cout << " [ID]  [Judul Film]                [Genre]        [Rating] " << endl;
    cout << "-----------------------------------------------------------" << endl;

    if (jumlahFilm == 0) {
        cout << " Data film kosong." << endl;
        cout << "-----------------------------------------------------------" << endl;
        cout << "Tekan Enter untuk Melanjutkan..." << endl;
        cin.ignore();
        cin.get();
        return;
    }

    for (int i = 0; i < jumlahFilm; i++) {
        cout << " " << left << setw(4) << arr[i].id
             << "  " << setw(25) << arr[i].judul
             << " " << setw(12) << arr[i].genre
             << " " << fixed << setprecision(1) << arr[i].rating << endl;
    }

    cout << "-----------------------------------------------------------" << endl;
    cout << "Tekan Enter untuk Melanjutkan..." << endl;
    cin.ignore();
    cin.get();
}

void tambahFilm(Film arr[], int &jumlahFilm) {
    if (jumlahFilm >= MAX_FILM) {
        cout << "Kapasitas film penuh." << endl;
        cout << "Tekan Enter untuk Melanjutkan..." << endl;
        cin.ignore();
        cin.get();
        return;
    }

    system("cls");
    cout << "=========== TAMBAH FILM BARU ===========" << endl;
    cout << "ID Film    : ";
    cin >> arr[jumlahFilm].id;

    cin.ignore();
    cout << "Judul Film : ";
    cin.getline(arr[jumlahFilm].judul, sizeof(arr[jumlahFilm].judul));

    cout << "Genre      : ";
    cin.getline(arr[jumlahFilm].genre, sizeof(arr[jumlahFilm].genre));

    cout << "Rating     : ";
    cin >> arr[jumlahFilm].rating;

    jumlahFilm++;

    cout << "Film berhasil ditambahkan." << endl;
    cout << "Tekan Enter untuk Melanjutkan..." << endl;
    cin.ignore();
    cin.get();
}

int main() {
    int pilihan;
    bool menu = true;
    Film daftarFilm[MAX_FILM];
    int jumlahFilm = loadFilm(daftarFilm);

    do {
        system("cls");
        cout << "======================================" << endl;
        cout << "      NETFILM SYSTEM - DASHBOARD      " << endl;
        cout << "======================================" << endl;
        cout << "  [1] Lihat Katalog Film              " << endl;
        cout << "  [2] Urutkan Rating (Quick Sort)     " << endl;
        cout << "  [3] Urutkan Abjad (Bubble Sort)     " << endl;
        cout << "  [4] Cari Film (Linear Search)       " << endl;
        cout << "  [5] Cari Film (Binary Search)       " << endl;
        cout << "  [6] Tambah Film Baru (Quick Sort)   " << endl;
        cout << "  [0] Keluar & Simpan                 " << endl;
        cout << "======================================" << endl;
        cout << "Pilih Menu : ";
        cin >> pilihan;

        if (pilihan < 0 || pilihan > 6) {
            system("cls");
            cout << "=================================================" << endl;
            cout << " Pilihan Menu Tidak Valid! Silakan Pilih Kembali " << endl;
            cout << "=================================================" << endl;
            cout << "Tekan Enter untuk Melanjutkan..." << endl;
            cin.ignore();
            cin.get();
            continue;
        }

        switch (pilihan) {
            case 1:
                katalogFilm(daftarFilm, jumlahFilm);
                break;
            case 2:
                /* code */
                break;
            case 3:
                /* code */
                break;
            case 4:
                /* code */
                break;
            case 5:
                /* code */
                break;
            case 6:
                tambahFilm(daftarFilm, jumlahFilm);
                break;
            case 0:
                saveFilm(daftarFilm, jumlahFilm);
                system("cls");
                cout << "================================================" << endl;
                cout << " Terima kasih telah menggunakan Netfilm System! " << endl;
                cout << "================================================" << endl;
                cin.ignore();
                cin.get();
                menu = false;
                break;
        }
    } while (menu == true);

    return 0;
}
