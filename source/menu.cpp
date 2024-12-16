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
    cout << "9. Buat Relasi Penulis Dan Buku" << endl;
    cout << "10. Tampilkan Data Penulis Dan Buku" << endl;
    cout << "11. Cari Data Buku Berdasarkan Penulis" << endl;
    cout << "12. Hapus Data Penulis" << endl;
    cout << "13. Hapus Data Buku Berdasarkan Penulis" << endl;
    cout << "14. Hitung Total Buku Terjual Berdasarkan Penulis" << endl;
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

void menuShowAllParentAndChild()
{
    cout << "\n--------------------------------------" << endl;
    cout << "    Menampilkan Data Penulis & Buku   " << endl;
    cout << "--------------------------------------" << endl;
}

void menuConnectRelasi()
{
    cout << "\n--------------------------------------" << endl;
    cout << "       Relasikan Penulis & Buku       " << endl;
    cout << "--------------------------------------" << endl;
}

void menuSearchChildFromParent()
{
    cout << "\n--------------------------------------" << endl;
    cout << "  Cari Data Buku Berdasarkan Penulis  " << endl;
    cout << "--------------------------------------" << endl;
}

void menuDeleteParentAndChild()
{
    cout << "\n--------------------------------------" << endl;
    cout << "          Hapus Data Penulis          " << endl;
    cout << "--------------------------------------" << endl;
}

void menuDeleteChildFromParent()
{
    cout << "\n--------------------------------------" << endl;
    cout << "  Hapus Data Buku Berdasarkan Penulis " << endl;
    cout << "--------------------------------------" << endl;
}

void menuCountSoldBooks()
{
    cout << "\n--------------------------------------" << endl;
    cout << "Total Buku Terjual Berdasarkan Penulis" << endl;
    cout << "--------------------------------------" << endl;
}

// Dummy Data
void elemenPenulis(List_parent &L)
{
    infotype_parent data;
    adr_parent p;

    data.idPenulis = "1";
    data.nama = "Sena";
    data.usia = 19;
    data.jenisKelamin = 'L';
    data.email = "senarizky@gmail.com";
    p = newElmListParent(data);
    insertLastParent(L, p);

    data.idPenulis = "2";
    data.nama = "Ihsan";
    data.usia = 26;
    data.jenisKelamin = 'L';
    data.email = "ihsannopal@gmail.com";
    p = newElmListParent(data);
    insertLastParent(L, p);

    data.idPenulis = "3";
    data.nama = "Adhisti";
    data.usia = 19;
    data.jenisKelamin = 'P';
    data.email = "adhistisophia@gmail.com";
    p = newElmListParent(data);
    insertLastParent(L, p);

    data.idPenulis = "4";
    data.nama = "Salma";
    data.usia = 20;
    data.jenisKelamin = 'P';
    data.email = "nurfitri@gmail.com";
    p = newElmListParent(data);
    insertLastParent(L, p);

    data.idPenulis = "5";
    data.nama = "Arya";
    data.usia = 36;
    data.jenisKelamin = 'L';
    data.email = "aryakesuma@gmail.com";
    p = newElmListParent(data);
    insertLastParent(L, p);

    // data.idPenulis = "6";
    // data.nama = "Gavin";
    // data.usia = 27;
    // data.jenisKelamin = 'L';
    // data.email = "gavinbnjro@gmail.com";
}

void elemenBuku(List_child &L)
{
    infotype_child data;
    adr_child p;

    data.isbn = "001";
    data.judul = "LaskarPelangi";
    data.penerbit = "BentangPustaka";
    data.tahunTerbit = 2005;
    data.genre = "Fiksi";
    data.harga = 85000;
    data.rating = 8.4;
    data.totalBukuTerjual = 1500;
    p = newElmListChild(data);
    insertLastChild(L, p);

    data.isbn = "002";
    data.judul = "Bumi";
    data.penerbit = "GramediaPustakaUtama";
    data.tahunTerbit = 2014;
    data.genre = "FiksiSains";
    data.harga = 99000;
    data.rating = 7.4;
    data.totalBukuTerjual = 3000;
    p = newElmListChild(data);
    insertLastChild(L, p);

    data.isbn = "003";
    data.judul = "SepatuDahlan";
    data.penerbit = "NouraBooks";
    data.tahunTerbit = 2012;
    data.genre = "Biografi";
    data.harga = 75000;
    data.rating = 5.4;
    data.totalBukuTerjual = 1200;
    p = newElmListChild(data);
    insertLastChild(L, p);

    data.isbn = "004";
    data.judul = "AyatAyatCinta";
    data.penerbit = "Republika";
    data.tahunTerbit = 2004;
    data.genre = "Religi";
    data.harga = 65000;
    data.rating = 6.8;
    data.totalBukuTerjual = 2100;
    p = newElmListChild(data);
    insertLastChild(L, p);

    data.isbn = "005";
    data.judul = "Negeri5Menara";
    data.penerbit = "GramediaPustakaUtama";
    data.tahunTerbit = 2009;
    data.genre = "Inspirasi";
    data.harga = 80000;
    data.rating = 9.2;
    data.totalBukuTerjual = 7500;
    p = newElmListChild(data);
    insertLastChild(L, p);

    // data.isbn = "006";
    // data.judul = "SuperNova";
    // data.penerbit = "BentangPustaka";
    // data.tahunTerbit = 2012;
    // data.genre = "Drama";
    // data.harga = 86000;
    // data.rating = 7.5;
    // data.totalBukuTerjual = 3650;
}

void elemenRelasi(List_relasi &L, List_parent LP, List_child LC)
{
    adr_parent elmP;
    adr_child elmC;
    adr_relasi p;

    elmP = findElmParent(LP, "5", "Arya");
    elmC = findElmChild(LC, "001", "Fiksi", "LaskarPelangi");
    p = newElmListRelasi(elmP, elmC);
    insertLastRelasi(L, p);

    elmP = findElmParent(LP, "1", "Sena");
    elmC = findElmChild(LC, "005", "Inspirasi", "Negeri5Menara");
    p = newElmListRelasi(elmP, elmC);
    insertLastRelasi(L, p);

    elmP = findElmParent(LP, "3", "Adhisti");
    elmC = findElmChild(LC, "004", "Religi", "AyatAyatCinta");
    p = newElmListRelasi(elmP, elmC);
    insertLastRelasi(L, p);

    elmP = findElmParent(LP, "2", "Ihsan");
    elmC = findElmChild(LC, "004", "Religi", "AyatAyatCinta");
    p = newElmListRelasi(elmP, elmC);
    insertLastRelasi(L, p);

    elmP = findElmParent(LP, "4", "Salma");
    elmC = findElmChild(LC, "002", "FiksiSains", "Bumi");
    p = newElmListRelasi(elmP, elmC);
    insertLastRelasi(L, p);

    elmP = findElmParent(LP, "1", "Sena");
    elmC = findElmChild(LC, "001", "Fiksi", "LaskarPelangi");
    p = newElmListRelasi(elmP, elmC);
    insertLastRelasi(L, p);

    elmP = findElmParent(LP, "2", "Ihsan");
    elmC = findElmChild(LC, "003", "Biografi", "SepatuDahlan");
    p = newElmListRelasi(elmP, elmC);
    insertLastRelasi(L, p);

    elmP = findElmParent(LP, "5", "Arya");
    elmC = findElmChild(LC, "005", "Inspirasi", "Negeri5Menara");
    p = newElmListRelasi(elmP, elmC);
    insertLastRelasi(L, p);

    elmP = findElmParent(LP, "1", "Sena");
    elmC = findElmChild(LC, "003", "Biografi", "SepatuDahlan");
    p = newElmListRelasi(elmP, elmC);
    insertLastRelasi(L, p);

    // elmP = findElmParent(LP, "6", "Gavin");
    // elmC = findElmChild(LC, "006", "Drama", "SuperNova");

    // elmP = findElmParent(LP, "6", "Gavin");
    // elmC = findElmChild(LC, "002", "FiksiSains", "Bumi");
}