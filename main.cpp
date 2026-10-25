#include "Doublylist.h"
#include <limits>

int main() {
    List L;
    CreateList(L);

    infotype x;
    address P;
    const int JUMLAH_DATA = 4;

    // ===== Soal 1: input data kendaraan =====
    for (int i = 0; i < JUMLAH_DATA; i++) {
        cout << "masukkan nomor polisi: ";
        getline(cin, x.nopol);
        cout << "masukkan warna kendaraan: ";
        getline(cin, x.warna);
        cout << "masukkan tahun kendaraan: ";
        cin >> x.thnBuat;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (findElm(L, x) != Nil) {
            cout << "nomor polisi sudah terdaftar" << endl << endl;
        } else {
            P = alokasi(x);
            insertLast(L, P);
            cout << endl;
        }
    }

    cout << "DATA LIST 1" << endl << endl;
    printInfo(L);
    cout << endl;

    // ===== Soal 2: cari elemen =====
    cout << "Masukkan Nomor Polisi yang dicari  : ";
    getline(cin, x.nopol);
    P = findElm(L, x);
    if (P != Nil) {
        cout << endl;
        cout << "Nomor Polisi : " << P->info.nopol << endl;
        cout << "Warna        : " << P->info.warna << endl;
        cout << "Tahun        : " << P->info.thnBuat << endl;
    } else {
        cout << "Data tidak ditemukan" << endl;
    }
    cout << endl;

    // ===== Soal 3: hapus elemen =====
    cout << "Masukkan Nomor Polisi yang akan dihapus  : ";
    getline(cin, x.nopol);
    P = findElm(L, x);
    if (P == Nil) {
        cout << "Data dengan nomor polisi " << x.nopol << " tidak ditemukan." << endl;
    } else {
        address Hapus;
        if (P == L.First) {
            deleteFirst(L, Hapus);
        } else if (P == L.Last) {
            deleteLast(L, Hapus);
        } else {
            deleteAfter(P->prev, Hapus);
        }
        cout << "Data dengan nomor polisi " << Hapus->info.nopol
             << " berhasil dihapus." << endl;
        dealokasi(Hapus);
    }
    cout << endl;

    cout << "DATA LIST 1" << endl << endl;
    printInfo(L);

    return 0;
}