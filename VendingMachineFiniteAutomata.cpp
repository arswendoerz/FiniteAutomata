#include <iostream>
#include <string>
#include <map>

using namespace std;

// Daftar minuman dan harga dalam koin
map<int, pair<string, int> > minuman;

void inisialisasiMinuman() {
    minuman[1] = make_pair("Air Mineral", 1);
    minuman[2] = make_pair("Soda", 2);
    minuman[3] = make_pair("Jus Jeruk", 3);
    minuman[4] = make_pair("Teh Botol", 2);
}

// Fungsi untuk menampilkan menu minuman
void tampilkanMenu() {
    cout << "Menu Minuman:\n";
    cout << "0. Untuk membatalkan\n";
    for (map<int, pair<string, int> >::iterator it = minuman.begin(); it != minuman.end(); ++it) {
        cout << it->first << ". " << it->second.first << " - " << it->second.second << " koin\n";
    }
}

int main() {
    int pilihan;
    int totalKoin = 0;
    int hargaMinuman;

    inisialisasiMinuman();
    tampilkanMenu();

    cout << "Pilih minuman dengan memasukkan nomor: ";
    cin >> pilihan;

    if (pilihan == 0) {
        cout << "Transaksi dibatalkan.\n";
        return 0;
    }

    if (minuman.find(pilihan) == minuman.end()) {
        cout << "Pilihan tidak valid.\n";
        return 1;
    }

    hargaMinuman = minuman[pilihan].second;
    cout << "Anda memilih " << minuman[pilihan].first << " dengan harga " << hargaMinuman << " koin.\n";

    while (totalKoin < hargaMinuman) {
        int koin;
        cout << "\nMasukkan koin: ";
        cin >> koin;
        totalKoin += koin;
        cout << "Total koin yang telah dimasukkan: " << totalKoin << "\n";

        if (totalKoin < hargaMinuman) {
            cout << "Koin masih kurang, silahkan kembali masukkan " << (hargaMinuman - totalKoin) << " koin lagi.\n";
        } else if (totalKoin > hargaMinuman) {
            int kembalian = totalKoin - hargaMinuman;
            cout << "Koin berlebih, mengembalikan sisa " << kembalian << " koin.\n";
            totalKoin -= kembalian;
        }
    }

    cout << "Jumlah koin pas. Mengeluarkan " << minuman[pilihan].first << ".\n";
    cout << "Terima kasih telah menggunakan vending machine.\n";

    return 0;
}
