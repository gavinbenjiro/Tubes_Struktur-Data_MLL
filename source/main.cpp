#include <iostream>

using namespace std;
#include "../header/list_child.h"
#include "../header/list_parent.h"
#include "../header/list_relasi.h"
#include "../header/menu.h"

int main()
{
    List_parent LP;            // List Parent
    List_child LC;             // List Child
    List_relasi LR;            // List Relasi
    infotype_parent dataP;     // Infotype Parent
    infotype_child dataC;      // Infotype Child
    adr_parent pParent;        // Address Parent
    adr_child pChild;          // Address Child
    adr_relasi pRelasi;        // Address Relasi
    string id, nama;           // untuk mencari elemen data Penulis
    string isbn, genre, judul; // untuk mencari elemen data Buku
    int banyakData;            // Banyak data yang diinputkan user

    // Membuat List Parent & Child
    createListParent(LP);
    createListChild(LC);
    createListRelasi(LR);

    // Dummy Data
    elemenPenulis(LP);
    elemenBuku(LC);
    elemenRelasi(LR, LP, LC);

    int opsi = menuUtama(); // untuk menampung pilihan menu dari user
    while (opsi != 0)
    {
        switch (opsi)
        {
        case 1:
            menuInsertParent();
            cout << "Banyak data penulis yang akan ditambahkan: ";
            cin >> banyakData;
            for (int i = 1; i <= banyakData; i++)
            {
                cout << "Masukkan Data Penulis: " << endl;
                cout << "ID: ";
                cin >> dataP.idPenulis;
                cout << "Nama: ";
                cin >> dataP.nama;
                cout << "Usia: ";
                cin >> dataP.usia;
                cout << "Jenis Kelamin (L/P): ";
                cin >> dataP.jenisKelamin;
                cout << "Email: ";
                cin >> dataP.email;
                pParent = newElmListParent(dataP);
                insertLastParent(LP, pParent);
                printf("\n");
            }
            break;
        case 2:
            menuShowAllParent();
            showAllListParent(LP);
            break;
        case 3:
            menuFindElmParent();
            cout << "Masukkan ID & Nama Penulis!" << endl;
            cout << "ID: ";
            cin >> id;
            cout << "Nama: ";
            cin >> nama;
            pParent = findElmParent(LP, id, nama);
            printf("\n");
            if (pParent == NULL)
            {
                cout << "Data Penulis Tidak Tersedia" << endl;
            }
            else
            {
                cout << "Data Penulis Tersedia" << endl;
                cout << "ID: " << infoP(pParent).idPenulis << endl;
                cout << "Nama: " << infoP(pParent).nama << endl;
                cout << "Usia: " << infoP(pParent).usia << endl;
                cout << "Jenis Kelamin: " << infoP(pParent).jenisKelamin << endl;
                cout << "Email: " << infoP(pParent).email << endl;
            }
            printf("\n");
            break;
        case 4:
            menuChangeDataParent();
            cout << "Masukkan ID & Nama Penulis!" << endl;
            cout << "ID: ";
            cin >> id;
            cout << "Nama: ";
            cin >> nama;
            pParent = findElmParent(LP, id, nama);
            printf("\n");
            if (pParent == NULL)
            {
                cout << "Data Penulis Tidak Tersedia" << endl;
            }
            else
            {
                changeDataParent(LP, pParent);
            }
            printf("\n");
            break;
        case 5:
            menuInsertChild();
            cout << "Banyak data buku yang akan ditambahkan: ";
            cin >> banyakData;
            for (int i = 1; i <= banyakData; i++)
            {
                cout << "Masukkan Data Buku: " << endl;
                cout << "ISBN: ";
                cin >> dataC.isbn;
                cout << "Judul: ";
                cin >> dataC.judul;
                cout << "Penerbit: ";
                cin >> dataC.penerbit;
                cout << "Tahun Terbit: ";
                cin >> dataC.tahunTerbit;
                cout << "Genre: ";
                cin >> dataC.genre;
                cout << "Harga: ";
                cin >> dataC.harga;
                cout << "Rating: ";
                cin >> dataC.rating;
                cout << "Buku Terjual: ";
                cin >> dataC.totalBukuTerjual;
                pChild = newElmListChild(dataC);
                insertLastChild(LC, pChild);
                printf("\n");
            }
            break;
        case 6:
            menuShowAllChild();
            showAllListChild(LC);
            break;
        case 7:
            menuFindElmChild();
            cout << "Masukkan ISBN, Genre & Judul Buku!" << endl;
            cout << "ISBN: ";
            cin >> isbn;
            cout << "Genre: ";
            cin >> genre;
            cout << "Judul: ";
            cin >> judul;
            pChild = findElmChild(LC, isbn, genre, judul);
            printf("\n");
            if (pChild == NULL)
            {
                cout << "Data Buku Tidak Tersedia" << endl;
            }
            else
            {
                cout << "Data Buku Tersedia" << endl;
                cout << "ISBN: " << infoC(pChild).isbn << endl;
                cout << "Judul: " << infoC(pChild).judul << endl;
                cout << "Penerbit: " << infoC(pChild).penerbit << endl;
                cout << "Tahun Terbit: " << infoC(pChild).tahunTerbit << endl;
                cout << "Genre: " << infoC(pChild).genre << endl;
                cout << "Harga: " << infoC(pChild).harga << endl;
                cout << "Rating: " << infoC(pChild).rating << endl;
                cout << "Total Terjual: " << infoC(pChild).totalBukuTerjual << endl;
            }
            printf("\n");
            break;
        case 8:
            menuChangeDataChild();
            cout << "Masukkan ISBN, Genre & Judul Buku!" << endl;
            cout << "ISBN: ";
            cin >> isbn;
            cout << "Genre: ";
            cin >> genre;
            cout << "Judul: ";
            cin >> judul;
            pChild = findElmChild(LC, isbn, genre, judul);
            printf("\n");
            if (pChild == NULL)
            {
                cout << "Data Buku Tidak Tersedia" << endl;
            }
            else
            {
                changeDataChild(LC, pChild);
            }
            printf("\n");
            break;
        case 9:
            menuConnectRelasi();
            cout << "Banyak relasi yang akan ditambahkan: ";
            cin >> banyakData;
            for (int i = 1; i <= banyakData; i++)
            {
                cout << "Masukkan Data Penulis: " << endl;
                cout << "ID: ";
                cin >> id;
                cout << "Nama: ";
                cin >> nama;
                cout << "Masukkan Data Buku: " << endl;
                cout << "ISBN: ";
                cin >> isbn;
                cout << "Genre: ";
                cin >> genre;
                cout << "Judul: ";
                cin >> judul;
                connectRelasi(LR, LP, LC, id, nama, isbn, genre, judul);
                printf("\n");
            }
            break;
        case 10:
            menuShowAllParentAndChild();
            showParentAndChild(LR, LP);
            break;
        case 11:
            menuSearchChildFromParent();
            cout << "Masukkan ID & Nama Penulis!" << endl;
            cout << "ID: ";
            cin >> id;
            cout << "Nama: ";
            cin >> nama;
            pParent = findElmParent(LP, id, nama);
            printf("\n");
            if (pParent == NULL)
            {
                cout << "Data Penulis Tidak Tersedia" << endl
                     << endl;
            }
            else
            {
                searchChildFromParent(LR, pParent);
            }
            break;
        case 12:
            menuDeleteParentAndChild();
            cout << "Masukkan ID & Nama Penulis Yang Ingin Dihapus" << endl;
            cout << "ID: ";
            cin >> id;
            cout << "Nama: ";
            cin >> nama;
            pParent = findElmParent(LP, id, nama);
            printf("\n");
            if (pParent == NULL)
            {
                cout << "Data Penulis Tidak Tersedia" << endl;
            }
            else
            {
                deleteParentAndRelasiToChild(LR, LP, LC, pParent);
                cout << "Data Penulis Beserta Relasi Dengan Buku Telah Terhapus" << endl;
            }
            printf("\n");
            break;
        case 13:
            menuDeleteChildFromParent();
            cout << "Masukkan ID & Nama Penulis!" << endl;
            cout << "ID: ";
            cin >> id;
            cout << "Nama: ";
            cin >> nama;
            pParent = findElmParent(LP, id, nama);
            printf("\n");
            if (pParent == NULL)
            {
                cout << "Data Penulis Tidak Tersedia" << endl;
            }
            else
            {
                searchChildFromParent(LR, pParent);
                cout << "Masukkan ISBN, Genre & Judul Buku Yang Ingin Dihapus" << endl;
                cout << "ISBN: ";
                cin >> isbn;
                cout << "Genre: ";
                cin >> genre;
                cout << "Judul: ";
                cin >> judul;
                pChild = findElmChild(LC, isbn, genre, judul);
                if (pChild == NULL)
                {
                    cout << "\nData Buku Tidak Tersedia" << endl;
                }
                else
                {
                    deleteRelasiChildFromParent(LR, LP, LC, pParent, pChild);
                    cout << "\nData Buku " << infoC(pChild).judul << " Dari Penulis " << infoP(pParent).nama << " Telah Terhapus" << endl;
                }
            }
            printf("\n");
            break;
        case 14:
            menuCountSoldBooks();
            cout << "Masukkan ID & Nama Penulis!" << endl;
            cout << "ID: ";
            cin >> id;
            cout << "Nama: ";
            cin >> nama;
            pParent = findElmParent(LP, id, nama);
            printf("\n");
            if (pParent == NULL)
            {
                cout << "Data Penulis Tidak Tersedia" << endl;
            }
            else
            {
                searchChildFromParent(LR, pParent);
                cout << "Total Buku Yang Terjual Dari Penulis " << infoP(pParent).nama << " adalah " << countSoldBooksFromParent(LR, pParent) << endl;
            }
            printf("\n");
            break;
        }
        string lanjut; // untuk menampung pilihan user agar lanjut atau tidak
        cout << "Kembali ke menu utama? (Y/N): ";
        cin >> lanjut;
        if (lanjut == "Y")
        {
            opsi = menuUtama();
        }
        else
        {
            opsi = 0;
        }
    }

    return 0;
}