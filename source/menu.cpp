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