#include "../header/list_child.h"

void createListChild(List_child &L)
{
    /*
    IS : -
    FS : Pointer First dan Last dari List L bernilai Nil
    */
    firstC(L) = NULL;
    lastC(L) = NULL;
}

adr_child newElmListChild(infotype_child x)
{
    /*
    IS : Nilai data infotype telah tersedia
    FS : Mengembalikan elemen list baru dengan info = x, next elemen = Nil & prev elemen = Nil
    */
    adr_child p;           // alamat untuk membentuk elemen baru
    p = new elmList_child; // elemen baru terbentuk
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
    if (firstC(L) == NULL and lastC(L) == NULL) // jika list kosong
    {
        firstC(L) = p;
        lastC(L) = p;
    }
    else // jika list tidak kosong
    {
        nextC(lastC(L)) = p;
        prevC(p) = lastC(L);
        lastC(L) = p;
    }
}

void deleteFirstChild(List_child &L, adr_child &p)
{
    /*
    IS : Terdefinisi List L yang mungkin kosong atau hanya memiliki 1 elemen
    FS : Jika list kosong, maka pointer P di assign dengan NIL, jika tidak kosong maka elemen paling awal dihapus dari List L,
         alamatnya disimpan oleh pointer p
    */
    p = firstC(L);
    if (firstC(L) == lastC(L)) // jika list kosong atau hanya memiliki 1 elemen
    {
        firstC(L) = NULL;
        lastC(L) = NULL;
    }
    else // jika list memiliki lebih dari 1 elemen
    {
        firstC(L) = nextC(p);
        nextC(p) = NULL;
        prevC(firstC(L)) = NULL;
    }
}

void deleteAfterChild(List_child &L, adr_child prec, adr_child &p)
{
    /*
    IS : Terdefinisi List L yang mungkin kosong atau memiliki lebih dari 1 elemen
    FS : Jika list kosong, maka pointer P di assign dengan Nil, jika tidak kosong maka elemen setelah prec akan dihapus dari list L,
         alamatnya disimpan oleh pointer p
    */
    if (nextC(prec) == lastC(L)) // elemen yang ingin dihapus adalah elemen terakhir
    {
        p = nextC(prec);
        lastC(L) = prec;
        nextC(prec) = NULL;
        prevC(p) = NULL;
    }
    else if (nextC(prec) != lastC(L)) // jika elemen yang ingin dihapus bukan elemen terakhir
    {
        p = nextC(prec);
        nextC(prec) = nextC(p);
        prevC(nextC(p)) = prec;
        nextC(p) = NULL;
        prevC(p) = NULL;
    }
    else // jika list kosong
    {
        p = NULL;
    }
}

void deleteLastChild(List_child &L, adr_child &p)
{
    /*
    IS : Terdefinisi List L yang mungkin kosong atau hanya memiliki 1 elemen
    FS : Jika list kosong, maka pointer P di assign dengan NIL, jika tidak kosong maka elemen paling akhir dihapus dari List L,
         alamatnya disimpan oleh pointer p
    */
    p = lastC(L);
    if (firstC(L) == lastC(L)) // jika list kosong atau hanya memiliki 1 elemen
    {
        firstC(L) = NULL;
        lastC(L) = NULL;
    }
    else // jika list memiliki lebih dari 1 elemen
    {
        lastC(L) = prevC(p);
        nextC(lastC(L)) = NULL;
        prevC(p) = NULL;
    }
}

void deleteBuku(List_child &L, adr_child p)
{
    /*
    IS : Terdefinisi List L dan alamat dari elemen yang ingin di hapus
    FS : Elemen p akan terhapus dari list
    */
    adr_child prec;        // prec berfungsi untuk delete after
    if (firstC(L) != NULL) // memastikan penghapusan akan dilakukan jika list memiliki minimal 1 elemen
    {
        if (firstC(L) == p) // jika elemen yang ingin dihapus adalah elemen pertama
        {
            deleteFirstChild(L, p);
        }
        else if (lastC(L) == p) // jika elemen yang ingin dihapus adalah elemen terakhir
        {
            deleteLastChild(L, p);
        }
        else // jika elemen yang ingin dihapus tidak berada di awal ataupun di akhir
        {
            prec = prevC(p);
            deleteAfterChild(L, prec, p);
        }
    }
}

void showAllListChild(List_child L)
{
    /*
    IS : Terdefinisi List L yang mungkin kosong
    FS : Jika list kosong maka tampilkan ke layar “list kosong”, jika tidak maka seluruh data pada list ditampilkan ke layar
    */
    if (firstC(L) == NULL and lastC(L) == NULL) // jika list kosong
    {
        cout << "List Buku Kosong\n"
             << endl;
    }
    else // jika list tidak kosong
    {
        adr_child q = firstC(L); // q berfungsi untuk menyimpan setiap elemen dari pertama hingga terakhir
        int i = 1;               // i berfungsi untuk iterasi urutan data
        while (q != NULL)
        {
            cout << "Buku urutan ke-" << i << endl;
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
    while (q != NULL)        // memastikan pencarian akan dilakukan jika list memiliki minimal 1 elemen
    {
        if (infoC(q).genre == genre and infoC(q).isbn == isbn and infoC(q).judul == judul)
        {
            return q; // jika data ditemukan
        }
        else
        {
            q = nextC(q);
        }
    }
    return NULL; // jika tidak ditemukan
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