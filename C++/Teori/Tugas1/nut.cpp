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
    cout << "\n[ Data berhasil disimpan ke " << namaFile << " ]\n";
    cout << "Tekan enter untuk kembali ke menu...";
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
    cout << "Tekan enter untuk kembali ke menu...";
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
                // SEARCHING functionality would go here
                break;
            case 4:
                system("cls");
                // SORTING functionality would go here
                break;
            case 5:
                system("cls");
                cout << "==============================\n";
                cout << "Terima kasih! Program selesai.\n";
                cout << "==============================\n";
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