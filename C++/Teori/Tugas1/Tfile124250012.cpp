#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>

using namespace std;

void inputData() {
    int jumlah;
    string namaFile;
    cout << "\nINPUT DATA\n";
    cout << "========================\n";
    
    do {
        cout << "Jumlah data (max 10): ";
        cin >> jumlah;
        if (jumlah < 1 || jumlah > 10) {
            cout << "Jumlah maksimal adalah 10 dan minimal 1. Silakan ulangi.\n";
            cout << "Tekan enter untuk melanjutkan...";
            cin.ignore();
            cin.get();
            system("cls");
            return;
        }
    } while (jumlah < 1 || jumlah > 10);

    cout << "Disimpan di file : "; cin >> namaFile;
    cout << "\n";

    FILE *file = fopen(namaFile.c_str(), "a");

    if (file == NULL) {
        cout << "Gagal membuka file untuk menyimpan data!\n";
        return;
    }

    for (int i = 1; i <= jumlah; i++) {
        string nim, kelas, ipk;


        cout << "Data ke-" << i << endl;
        cout << "  NIM   : "; cin >> nim;
        cout << "  Kelas : "; cin >> kelas;
        cout << "  IPK   : "; cin >> ipk;

        fprintf(file, " %s     %s        %s\n", nim.c_str(), kelas.c_str(), ipk.c_str());
    }

    fclose(file);
    cout << "\n======================================\n";
    cout << "Data berhasil disimpan ke " << namaFile << "";
    cout << "\n======================================\n";
    cout << "\nTekan enter untuk kembali ke menu...";
    cin.ignore();
    cin.get();
    system("cls");

}

void tampilData() {
    string namaFile;
    cout << "\nTAMPIL DATA\n";
    cout << "========================\n";
    
    cout << "Masukkan nama file yang ingin ditampilkan: "; cin >> namaFile;
    cout << "\n";
    FILE *file = fopen(namaFile.c_str(), "r");
    
    if (file == NULL) {
        cout << "File " << namaFile << " belum ada atau kosong! Silakan input data terlebih dahulu.\n";
        cout << "Tekan enter untuk kembali ke menu...";
        cin.ignore();
        cin.get();
        system("cls");
        return;
    }
    cout << "================================\n";
    cout << "    NIM    | Kelas |     IPK    \n";
    cout << "================================\n";
    
    char buffer[256];
    while (fgets(buffer, sizeof(buffer), file)) {
        cout << buffer;
    }

    fclose(file);
    cout << "================================\n";
    cout << "\nTekan enter untuk kembali ke menu...";
    cin.ignore();
    cin.get();
    system("cls");
}

void sequentialSearchFile() {
    string namaFile, nimCari;
    bool ulangi = true;
    char pilKembali;
    do
    {
        system("cls");
        cout << "=================\n";
        cout << "SEQUENTIAL SEARCH\n";
        cout << "=================\n";
    
        cout << "\nMasukkan nama file yang ingin dicari: "; cin >> namaFile;
        cout << "\nMasukkan NIM yang ingin dicari: "; cin >> nimCari;
    
        FILE *file = fopen(namaFile.c_str(), "r");
        if (file == NULL) {
            cout << "\n====================================================================================\n";
            cout << "File " << namaFile << " belum ada atau kosong! Silakan input data terlebih dahulu.";
            cout << "\n====================================================================================\n";
            cout << "Tekan enter untuk kembali ke menu...";
            cin.ignore();
            cin.get();
            system("cls");
            return;
        }
    
        char buffer[256];
        bool found = false;
    
        while (fgets(buffer, sizeof(buffer), file)) {
            string line(buffer);
            size_t pos = line.find(nimCari);
            if (pos != string::npos) {
                cout << "\nData ditemukan:\n";
                cout << "================================\n";
                cout << "    NIM    | Kelas |     IPK    \n";
                cout << "================================\n";
                cout << line;
                cout << "================================\n";
                found = true;
                break;
            }
        }
    
        if (!found) {
            cout << "\n===================================================================\n";    
            cout << "NIM " << nimCari << " tidak ditemukan dalam file " << namaFile << ".";
            cout << "\n===================================================================\n";    
        }

        fclose(file);

        cout << "\nApakah Anda ingin mencari NIM lain? (y/n): "; cin >> pilKembali;
        if (pilKembali == 'y' || pilKembali == 'Y') {
            ulangi = true;
        } else {
            ulangi = false;
        }

    } while (ulangi == true);
    

    cout << "\nTekan enter untuk kembali ke menu...";
    cin.ignore();
    cin.get();
    system("cls");
}

void bubbleSortFile() {
    string namaFile;
    cout << "===================\n";
    cout << "BUBBLE SORTING\n";
    cout << "===================\n";
    
    cout << "\nMasukkan nama file yang ingin diurutkan: "; cin >> namaFile;
    cout << "\n";

    FILE *file = fopen(namaFile.c_str(), "r");
    if (file == NULL) {
        cout << "File " << namaFile << " belum ada atau kosong! Silakan input data terlebih dahulu.\n";
        cout << "Tekan enter untuk kembali ke menu...";
        cin.ignore();
        cin.get();
        system("cls");
        return;
    }

    struct Data {
        string nim;
        string kelas;
        string ipk;
    };

    Data dataArray[10];
    int count = 0;
    char buffer[256];

    // Baca semua data ke array terlebih dahulu
    while (fgets(buffer, sizeof(buffer), file) && count < 10) {
        char nim[50], kelas[50], ipk[50];
        if (sscanf(buffer, "%s %s %s", nim, kelas, ipk) == 3) {
            dataArray[count].nim = nim;
            dataArray[count].kelas = kelas;
            dataArray[count].ipk = ipk;
            count++;
        }
    }

    fclose(file);

    // Tampilkan data sebelum diurutkan dari array
    cout << "Data dalam '" << namaFile << "' sebelum diurutkan:\n";
    cout << "================================\n";
    cout << "    NIM    | Kelas |     IPK    \n";
    cout << "================================\n";
    for (int i = 0; i < count; i++) {
        cout << " " << dataArray[i].nim << "     " << dataArray[i].kelas << "        " << dataArray[i].ipk << "\n";
    }
    cout << "================================\n";

    cout << "\nTekan enter untuk melanjutkan ke proses sorting...";
    cin.ignore();
    cin.get();

    // Bubble sort berdasarkan NIM
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (dataArray[j].nim > dataArray[j + 1].nim) {
                swap(dataArray[j], dataArray[j + 1]);
            }
        }
    }

    cout << "\nData setelah diurutkan berdasarkan NIM:\n";
    cout << "================================\n";
    cout << "    NIM    | Kelas |     IPK    \n";
    cout << "================================\n";
    
    for (int i = 0; i < count; i++) {
        cout << " " << dataArray[i].nim << "     " << dataArray[i].kelas << "        " << dataArray[i].ipk << "\n";
    }
    
    cout << "================================\n";
    
    cout << "\nTekan enter untuk kembali ke menu...";
    cin.ignore();
    cin.get();
    system("cls");
}

int main() {
    int pilihan;
    do {
        system("cls");
        cout << "MENU :\n";
        cout << "========================\n";
        cout << "1. INPUT DATA\n";
        cout << "2. TAMPIL DATA\n";
        cout << "3. SEARCHING\n";
        cout << "4. SORTING\n";
        cout << "5. KELUAR\n";
        cout << "========================\n";
        cout << "Pilih: ";
        cin >> pilihan;

        if (pilihan < 1 || pilihan > 5) {
            system("cls");
            cout << "Pilihan tidak valid! Silakan pilih antara 1, 2, 3, 4, atau 5.\n";
            cout << "Tekan enter untuk melanjutkan...";
            cin.ignore();
            cin.get();
            continue;
        }

        switch (pilihan) {
            case 1:
                system("cls");
                inputData();
                break;
            case 2:
                system("cls");
                tampilData();
                break;
            case 3:
                system("cls");
                sequentialSearchFile();
                break;
            case 4:
                system("cls");
                bubbleSortFile();
                break;
            case 5:
                system("cls");
                cout << "==============================\n";
                cout << "Terima kasih! Program selesai.\n";
                cout << "==============================\n";
                cin.ignore();
                cin.get();
                break;
            default:
                system("cls");
                cout << "=============================================================\n";
                cout << "Pilihan tidak valid! Silakan pilih antara 1, 2, 3, 4, atau 5.\n";
                cout << "=============================================================\n";  
        }
    } while (pilihan != 5);
    return 0;
}