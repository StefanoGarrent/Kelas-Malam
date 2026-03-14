#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iomanip>

using namespace std;

#define MAX_FILM 100 

struct Film {
    char judul[255];
    float harga;
    int tahun;
    float rating;
};

void muatData(Film arr[], int &counter) {
    FILE *file = fopen("netfilm_db.txt", "r");
    if (file == NULL) {
        counter = 0;
        return;
    }
    
    counter = 0;
    while (fscanf(file, "%[^;];%f;%d;%f\n", arr[counter].judul, &arr[counter].harga, &arr[counter].tahun, &arr[counter].rating) != EOF) {
        counter++;
    }
    fclose(file);
}

void simpanData(Film arr[], int counter) {
    FILE *file = fopen("netfilm_db.txt", "w");
    if (file == NULL) {
        cout << "[!] Gagal membuka file untuk menyimpan data." << endl;
        return;
    }
    for (int i = 0; i < counter; i++) {
        fprintf(file, "%s;%.0f;%d;%.1f\n", arr[i].judul, arr[i].harga, arr[i].tahun, arr[i].rating);
    }
    fclose(file);
    cout << "[ SUCCESS ] Data berhasil disinkronkan ke netfilm_db.txt" << endl;
}

void displayFilms(Film arr[], int counter) {
    if (counter == 0) {
        cout << "\n[!] Katalog masih kosong." << endl;
        return;
    }
    cout << "\nNETFLIX CONTENT KATALOG" << endl;
    cout << "=========================================================================" << endl;
    cout << left << setw(5) << "ID" << " | "
         << setw(35) << "JUDUL FILM" << " | "
         << setw(12) << "LISENSI" << " | "
         << setw(5) << "TAHUN" << " | "
         << setw(6) << "RATING" << endl;
    cout << "-------------------------------------------------------------------------" << endl;
    for (int i = 0; i < counter; i++) {
        cout << "[" << (i + 1) << "]   | "
             << left << setw(35) << arr[i].judul << " | Rp "
             << setw(9) << fixed << setprecision(0) << arr[i].harga << " | "
             << setw(5) << arr[i].tahun << " | "
             << fixed << setprecision(1) << arr[i].rating << endl;
    }
    cout << "=========================================================================" << endl;
}

void bubbleSort(Film arr[], int counter) {
    for (int i = 0; i < counter - 1; i++) {
        for (int j = 0; j < counter - i - 1; j++) {
            if (strcmp(arr[j].judul, arr[j + 1].judul) > 0) {
                Film temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    cout << "\n[!] Katalog berhasil diurutkan berdasarkan Abjad (A-Z)." << endl;
}

void swapFilm(Film* a, Film* b) {
    Film t = *a;
    *a = *b;
    *b = t;
}

int partition(Film arr[], int low, int high) {
    float pivot = arr[high].rating;
    int i = (low - 1);
    
    for (int j = low; j <= high - 1; j++) {
        if (arr[j].rating > pivot) { 
            i++;
            swapFilm(&arr[i], &arr[j]);
        }
    }
    swapFilm(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(Film arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void linearSearch(Film arr[], int counter) {
    system("cls");
    char keyword[255];
    cout << "\nKeyword judul: ";
    scanf(" %[^\n]s", keyword); 
    
    bool found = false;
    for (int i = 0; i < counter; i++) {
        if (strstr(arr[i].judul, keyword) != NULL) {
            cout << "[FOUND] " << arr[i].judul << " (" << arr[i].tahun
                 << ") - Rating: " << fixed << setprecision(1) << arr[i].rating << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "[!] Film tidak ditemukan." << endl;
    }
}

void binarySearch(Film arr[], int counter) {
    system("cls");
    char keyword[255];
    cout << "\njudul Lengkap (Exact): ";
    scanf(" %[^\n]s", keyword);
    
    int left = 0, right = counter - 1;
    bool found = false;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int res = strcmp(arr[mid].judul, keyword);
        
        if (res == 0) { 
            cout << "[FOUND] " << arr[mid].judul << " (" << arr[mid].tahun
                 << ") - Rating: " << fixed << setprecision(1) << arr[mid].rating << endl;
            found = true;
            break;
        }
        if (res < 0) { 
            left = mid + 1;
        } else { 
            right = mid - 1;
        }
    }
    
    if (!found) {
        cout << "[!] judul tidak ditemukan. Pastikan data sudah di-sort A-Z." << endl;
    }
}

void tambahFilm(Film arr[], int &counter) {
    if (counter >= MAX_FILM) {
        cout << "\n[!] Kapasitas database penuh (Max " << MAX_FILM << " film)." << endl;
        return;
    }

    cout << "\nInput judul: ";
    scanf(" %254[^\n]", arr[counter].judul);

    cout << "Input Harga: ";
    scanf("%f", &arr[counter].harga);

    cout << "Input Tahun: ";
    scanf("%d", &arr[counter].tahun);

    cout << "Input Rating: ";
    scanf("%f", &arr[counter].rating);

    counter++;

    simpanData(arr, counter);
    cout << "[ SUCCESS ] Film ditambahkan." << endl;
}


int main() {
    Film arr[MAX_FILM];
    int counter = 0;
    int choice;
    
    muatData(arr, counter);
    
    do {
        system("cls");
        cout << "\n=========================================" << endl;
        cout << "       NETFILM SYSTEM - DASHBOARD" << endl;
        cout << "=========================================" << endl;
        cout << "[1] Lihat Katalog Film" << endl;
        cout << "[2] Urutkan Rating (Quick Sort)" << endl;
        cout << "[3] Urutkan Abjad  (Bubble Sort)" << endl;
        cout << "[4] Cari Film (Linear Search)" << endl;
        cout << "[5] Cari Film (Binary Search)" << endl;
        cout << "[6] Tambah Film Baru" << endl;
        cout << "[0] Keluar & Simpan" << endl;
        cout << "=========================================" << endl;
        cout << "Pilih Menu > ";
        
        if (scanf("%d", &choice) != 1) {
            cout << "Input tidak valid. Keluar dari program." << endl;
            break;
        }

        switch (choice) {
            case 1:
                system("cls");
                displayFilms(arr, counter);
                break;
            case 2:
                system("cls");
                if (counter > 0) {
                    quickSort(arr, 0, counter - 1);
                    cout << "\n[!] Katalog berhasil diurutkan berdasarkan Rating Tertinggi." << endl;
                    displayFilms(arr, counter);
                } else {
                    cout << "\n[!] Katalog kosong." << endl;
                }
                break;
            case 3:
                system("cls");
                if (counter > 0) {
                    bubbleSort(arr, counter);
                    displayFilms(arr, counter);
                } else {
                    cout << "\n[!] Katalog kosong." << endl;
                }
                break;
            case 4:
                system("cls");
                if (counter > 0) linearSearch(arr, counter);
                else cout << "\n[!] Katalog kosong." << endl;
                break;
            case 5:
                system("cls");
                if (counter > 0) binarySearch(arr, counter);
                else cout << "\n[!] Katalog kosong." << endl;
                break;
            case 6:
                system("cls");
                tambahFilm(arr, counter);
                break;
            case 0:
                cout << "\nMenyimpan data..." << endl;
                simpanData(arr, counter);
                cout << "Sistem Offline. Terimakasih!" << endl;
                break;
            default:
                cout << "\n[!] Pilihan tidak valid!" << endl;
        }
        
        if (choice != 0) {
            cout << "\nTekan Enter untuk melanjutkan...";
            while(getchar() != '\n');
            getchar();
        }

    } while (choice != 0);

    return 0;
}