#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    float a, b, hasilFloat;
    double c, d, hasilDouble;

    a = 22;
    b = 7;

    c = 22;
    d = 7;

    hasilFloat = a / b;
    hasilDouble = c / d;

    cout << fixed << setprecision(20); // Menampilkan hasil dengan 20 angka di belakang koma
    cout << "Hasil pembagian dengan tipe data float: " << hasilFloat << endl;
    cout << "Hasil pembagian dengan tipe data double: " << hasilDouble << endl;
    

    return 0;
}