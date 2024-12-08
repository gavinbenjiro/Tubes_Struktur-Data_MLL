#include <iostream>

using namespace std;
#include "../header/list_child.h"
#include "../header/list_parent.h"
#include "../header/list_relasi.h"
#include "../header/menu.h"

int main()
{
    List_parent LP;
    infotype_parent data;
    adr_parent p;
    string id, nama; // untuk mencari elemen data user
    int banyakData;  // Banyak data yang diinputkan user

    createListParent(LP);

    int opsi = menuUtama(); // untuk menampung pilihan menu dari user
    while (opsi != 0)
    {
        switch (opsi)
        {
        case 1:
            menuInsertParent();
            cout << "Banyak data yang akan ditambahkan: ";
            cin >> banyakData;
            for (int i = 1; i <= banyakData; i++)
            {
                cout << "ID: ";
                cin >> data.idPenulis;
                cout << "Nama: ";
                cin >> data.nama;
                cout << "Usia: ";
                cin >> data.usia;
                cout << "Jenis Kelamin: ";
                cin >> data.jenisKelamin;
                cout << "Email: ";
                cin >> data.email;
                p = newElmListParent(data);
                insertLastParent(LP, p);
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
            p = findElmParent(LP, id, nama);
            printf("\n");
            if (p == NULL)
            {
                cout << "Data Penulis Tidak Tersedia" << endl;
            }
            else
            {
                cout << "Data Penulis Tersedia" << endl;
                cout << "ID: ";
                cout << infoP(p).idPenulis << endl;
                cout << "Nama: ";
                cout << infoP(p).nama << endl;
                cout << "Usia: ";
                cout << infoP(p).usia << endl;
                cout << "Jenis Kelamin: ";
                cout << infoP(p).jenisKelamin << endl;
                cout << "Email: ";
                cout << infoP(p).email << endl;
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
            p = findElmParent(LP, id, nama);
            printf("\n");
            if (p == NULL)
            {
                cout << "Data Penulis Tidak Tersedia" << endl;
            }
            else
            {
                changeDataParent(LP, p);
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