#include "../header/menu.h"

int menuUtama()
{
    cout << "\n======================================" << endl;
    cout << "              MENU UTAMA              " << endl;
    cout << "======================================" << endl;
    cout << "1. Tambah Data Penulis" << endl;
    cout << "2. Tampilkan Seluruh Data Penulis" << endl;
    cout << "3. Cari Data Penulis" << endl;
    cout << "4. Update Data Penulis" << endl;
    cout << "5. Tambah Data Buku" << endl;
    cout << "6. Tampilkan Seluruh Data Buku" << endl;
    cout << "7. Cari Data Buku" << endl;
    cout << "8. Update Data Buku" << endl;
    cout << "0. Exit" << endl;

    cout << "Masukkan menu: ";
    int inp = 0;
    cin >> inp;

    return inp;
}

void menuInsertParent()
{
    cout << "\n--------------------------------------" << endl;
    cout << "         Masukkan Data Penulis        " << endl;
    cout << "--------------------------------------" << endl;
}

void menuShowAllParent()
{
    cout << "\n--------------------------------------" << endl;
    cout << "       Menampilkan Data Penulis       " << endl;
    cout << "--------------------------------------" << endl;
}

void menuFindElmParent()
{
    cout << "\n--------------------------------------" << endl;
    cout << "          Cari Data Penulis           " << endl;
    cout << "--------------------------------------" << endl;
}

void menuChangeDataParent()
{
    cout << "\n--------------------------------------" << endl;
    cout << "             Edit Penulis             " << endl;
    cout << "--------------------------------------" << endl;
}

void menuInsertChild()
{
    cout << "\n--------------------------------------" << endl;
    cout << "          Masukkan Data Buku          " << endl;
    cout << "--------------------------------------" << endl;
}

void menuShowAllChild()
{
    cout << "\n--------------------------------------" << endl;
    cout << "         Menampilkan Data Buku        " << endl;
    cout << "--------------------------------------" << endl;
}

void menuFindElmChild()
{
    cout << "\n--------------------------------------" << endl;
    cout << "            Cari Data Buku            " << endl;
    cout << "--------------------------------------" << endl;
}

void menuChangeDataChild()
{
    cout << "\n--------------------------------------" << endl;
    cout << "               Edit Buku              " << endl;
    cout << "--------------------------------------" << endl;
}