#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

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

// Fungsi untuk Save Data ke File
void simpanData(Film arr[], int counter) {
    FILE *file = fopen("netfilm_db.txt", "w");
    if (file == NULL) {
        printf("[!] Gagal membuka file untuk menyimpan data.\n");
        return;
    }
    for (int i = 0; i < counter; i++) {
        // Menyimpan dengan delimiter ';'
        fprintf(file, "%s;%.0f;%d;%.1f\n", arr[i].judul, arr[i].harga, arr[i].tahun, arr[i].rating);
    }
    fclose(file);
    printf("[ SUCCESS ] Data berhasil disinkronkan ke netfilm_db.txt\n");
}

// --- FUNGSI UTILITIES & TAMPILAN ---

void displayFilms(Film arr[], int counter) {
    if (counter == 0) {
        printf("\n[!] Katalog masih kosong.\n");
        return;
    }
    printf("\nNETFLIX CONTENT KATALOG\n");
    printf("=========================================================================\n");
    printf("%-5s | %-35s | %-12s | %-5s | %-6s\n", "ID", "judul FILM", "LISENSI", "TAHUN", "RATING");
    printf("-------------------------------------------------------------------------\n");
    for (int i = 0; i < counter; i++) {
        printf("[%d]   | %-35s | Rp %-9.0lf | %-5d | %.1lf\n", i + 1, arr[i].judul, arr[i].harga, arr[i].tahun, arr[i].rating);
    }
    printf("=========================================================================\n");
}

// --- FUNGSI SORTING ---

// 1. Bubble Sort (Berdasarkan judul A-Z)
void bubbleSort(Film arr[], int counter) {
    for (int i = 0; i < counter - 1; i++) {
        for (int j = 0; j < counter - i - 1; j++) {
            // Membandingkan string judul
            if (strcmp(arr[j].judul, arr[j + 1].judul) > 0) {
                Film temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("\n[!] Katalog berhasil diurutkan berdasarkan Abjad (A-Z).\n");
}

// 2. Quick Sort (Berdasarkan Rating Tertinggi - Descending)
void swapFilm(Film* a, Film* b) {
    Film t = *a;
    *a = *b;
    *b = t;
}

int partition(Film arr[], int low, int high) {
    float pivot = arr[high].rating;
    int i = (low - 1);
    
    for (int j = low; j <= high - 1; j++) {
        if (arr[j].rating > pivot) { // Descending (> pivot)
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

// --- FUNGSI SEARCHING ---

// 1. Linear Search (Pencarian Parsial/Keyword berdasarkan judul)
void linearSearch(Film arr[], int counter) {
    char keyword[255];
    printf("\nKeyword judul: ");
    scanf(" %[^\n]s", keyword); // Membaca string dengan spasi
    
    bool found = false;
    for (int i = 0; i < counter; i++) {
        // strstr mencari substring di dalam string
        if (strstr(arr[i].judul, keyword) != NULL) {
            printf("[FOUND] %s (%d) - Rating: %.1lf\n", arr[i].judul, arr[i].tahun, arr[i].rating);
            found = true;
        }
    }
    if (!found) {
        printf("[!] Film tidak ditemukan.\n");
    }
}

// 2. Binary Search (Pencarian Exact berdasarkan judul, data wajib terurut A-Z)
void binarySearch(Film arr[], int counter) {
    char keyword[255];
    printf("\njudul Lengkap (Exact): ");
    scanf(" %[^\n]s", keyword);
    
    int left = 0, right = counter - 1;
    bool found = false;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int res = strcmp(arr[mid].judul, keyword);
        
        if (res == 0) { // Cocok
            printf("[FOUND] %s (%d) - Rating: %.1lf\n", arr[mid].judul, arr[mid].tahun, arr[mid].rating);
            found = true;
            break;
        }
        if (res < 0) { // keyword lebih besar (abjad setelahnya)
            left = mid + 1;
        } else { // keyword lebih kecil
            right = mid - 1;
        }
    }
    
    if (!found) {
        printf("[!] judul tidak ditemukan. Pastikan data sudah di-sort A-Z.\n");
    }
}


int main() {
    Film arr[MAX_FILM];
    int counter = 0;
    int choice;
    
    muatData(arr, counter);
    
    do {
        printf("\n=========================================\n");
        printf("       NETFILM SYSTEM - DASHBOARD\n");
        printf("=========================================\n");
        printf("[1] Lihat Katalog Film\n");
        printf("[2] Urutkan Rating (Quick Sort)\n");
        printf("[3] Urutkan Abjad  (Bubble Sort)\n");
        printf("[4] Cari Film (Linear Search)\n");
        printf("[5] Cari Film (Binary Search)\n");
        printf("[6] Tambah Film Baru\n");
        printf("[0] Keluar & Simpan\n");
        printf("=========================================\n");
        printf("Pilih Menu > ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Input tidak valid. Keluar dari program.\n");
            break;
        }

        switch (choice) {
            case 1:
                displayFilms(arr, counter);
                break;
            case 2:
                if (counter > 0) {
                    quickSort(arr, 0, counter - 1);
                    printf("\n[!] Katalog berhasil diurutkan berdasarkan Rating Tertinggi.\n");
                    displayFilms(arr, counter);
                } else {
                    printf("\n[!] Katalog kosong.\n");
                }
                break;
            case 3:
                if (counter > 0) {
                    bubbleSort(arr, counter);
                    displayFilms(arr, counter);
                } else {
                    printf("\n[!] Katalog kosong.\n");
                }
                break;
            case 4:
                if (counter > 0) linearSearch(arr, counter);
                else printf("\n[!] Katalog kosong.\n");
                break;
            case 5:
                if (counter > 0) binarySearch(arr, counter);
                else printf("\n[!] Katalog kosong.\n");
                break;
            case 6:
                if (counter < MAX_FILM) {
                    printf("\nInput judul: ");
                    scanf(" %[^\n]s", arr[counter].judul);
                    printf("Input Harga: ");
                    scanf("%lf", &arr[counter].harga);
                    printf("Input Tahun: ");
                    scanf("%d", &arr[counter].tahun);
                    printf("Input Rating: ");
                    scanf("%lf", &arr[counter].rating);
                    
                    counter++;
                    
                    simpanData(arr, counter);
                    printf("[ SUCCESS ] Film ditambahkan.\n");
                } else {
                    printf("\n[!] Kapasitas database penuh (Max %d film).\n", MAX_FILM);
                }
                break;
            case 0:
                printf("\nMenyimpan data...\n");
                simpanData(arr, counter);
                printf("Sistem Offline. Terimakasih!\n");
                break;
            default:
                printf("\n[!] Pilihan tidak valid!\n");
        }
        
        if (choice != 0) {
            printf("\nTekan Enter untuk melanjutkan...");
            while(getchar() != '\n');
            getchar();
        }

    } while (choice != 0);

    return 0;
}