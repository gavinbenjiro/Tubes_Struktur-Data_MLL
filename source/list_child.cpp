#include "../header/list_child.h"

void createListChild(List_child &L)
{
    /*
    IS : -
    FS : Pointer First dari List L bernilai Nil
    */
    firstC(L) = NULL;
    lastC(L) = NULL;
}

adr_child newElmListChild(infotype_child x)
{
    /*
    IS : Nilai data infotype telah tersedia
    FS : Mengembalikan elemen list baru dengan info = x, next elemen = Nil
    */
    adr_child p;
    p = new elmList_child;
    infoC(p) = x;
    prevC(p) = NULL;
    nextC(p) = NULL;
    return p;
}

void insertLastChild(List_child &L, adr_child p)
{
    /*
    IS : Terdefinisi List L yang mungkin kosong dan sebuah elemen baru yang alamatnya disimpan oleh pointer P
    FS : Elemen baru telah masuk menjadi elemen paling akhir di list L
    */
    if (firstC(L) == NULL and lastC(L) == NULL)
    {
        firstC(L) = p;
        lastC(L) = p;
    }
    else
    {
        nextC(lastC(L)) = p;
        prevC(p) = lastC(L);
        lastC(L) = p;
    }
}

void showAllListChild(List_child L)
{
    /*
    IS : Terdefinisi List L yang mungkin kosong
    FS : Jika list kosong maka tampilkan ke layar “list kosong”, jika tidak maka seluruh data pada list ditampilkan ke layar
    */
    if (firstC(L) == NULL and lastC(L) == NULL)
    {
        cout << "List Buku Kosong" << endl;
    }
    else
    {
        adr_child q = firstC(L); // q berfungsi untuk menyimpan setiap elemen dari pertama hingga terakhir
        int i = 1;               // i berfungsi untuk iterasi urutan data
        while (q != NULL)
        {
            cout << "Data urutan ke-" << i << endl;
            cout << "ISBN: " << infoC(q).isbn << endl;
            cout << "Judul: " << infoC(q).judul << endl;
            cout << "Penerbit: " << infoC(q).penerbit << endl;
            cout << "Tahun Terbit: " << infoC(q).tahunTerbit << endl;
            cout << "Genre: " << infoC(q).genre << endl;
            cout << "Harga: " << infoC(q).harga << endl;
            cout << "Rating: " << infoC(q).rating << endl;
            cout << "Total Terjual: " << infoC(q).totalBukuTerjual << endl;
            cout << endl;
            q = nextC(q);
            i++;
        }
    }
}

adr_child findElmChild(List_child L, string isbn, string genre, string judul)
{
    /*
    IS : Terdefinisi List L dan genre, isbn, dan judul buku yang akan dicari. List mungkin kosong
    FS : Return alamat dimana penulis ditemukan, return nil jika tidak ditemukan
    */
    adr_child q = firstC(L); // q berfungsi untuk menemukan elemen yang dicari
    while (q != NULL)
    {
        if (infoC(q).genre == genre and infoC(q).isbn == isbn and infoC(q).judul == judul)
        {
            return q;
        }
        else
        {
            q = nextC(q);
        }
    }
    return NULL;
}

void changeDataChild(List_child &L, adr_child p)
{
    /*
    IS : Terdefinisi Elemen buku yang ingin diubah datanya
    FS : Data buku telah ter-update
    */
    cout << "Masukkan Genre Terbaru: ";
    cin >> infoC(p).genre;
    cout << "Masukkan Harga Terbaru: ";
    cin >> infoC(p).harga;
    cout << "Masukkan Rating Terbaru: ";
    cin >> infoC(p).rating;
    cout << "Masukkan Data Buku Terjual Terbaru: ";
    cin >> infoC(p).totalBukuTerjual;
}