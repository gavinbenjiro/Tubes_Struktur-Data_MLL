#include "../header/list_parent.h"

void createListParent(List_parent &L)
{
    /*
    IS : -
    FS : Pointer First dari List L bernilai Nil
    */

    firstP(L) = NULL;
}

adr_parent newElmListParent(infotype_parent x)
{
    /*
    IS : Nilai data infotype telah tersedia
    FS : Mengembalikan elemen list baru dengan info = x, next elemen = Nil
    */

    adr_parent p;           // alamat untuk membentuk elemen baru
    p = new elmList_parent; // elemen baru terbentuk
    infoP(p) = x;
    nextP(p) = NULL;
    return p;
}

void insertLastParent(List_parent &L, adr_parent p)
{
    /*
    IS : Terdefinisi List L yang mungkin kosong dan sebuah elemen baru yang alamatnya disimpan oleh pointer P
    FS : Elemen baru telah masuk menjadi elemen paling akhir di list L
    */

    if (firstP(L) == NULL) // jika list kosong
    {
        firstP(L) = p;
    }
    else // jika list tidak kosong
    {
        adr_parent q = firstP(L); // q berfungsi untuk mencari elemen terakhir
        while (nextP(q) != NULL)
        {
            q = nextP(q);
        }
        nextP(q) = p;
    }
}

void deleteFirstParent(List_parent &L, adr_parent &p)
{
    /*
    IS : Terdefinisi List L yang mungkin kosong atau hanya memiliki 1 elemen
    FS : Jika list kosong, maka pointer P di assign dengan NIL, jika tidak kosong maka elemen paling awal dihapus dari List L,
         alamatnya disimpan oleh pointer p
    */

    if (firstP(L) == NULL) // jika list kosong
    {
        p = NULL;
    }
    else // jika list memiliki minimal 1 elemen
    {
        p = firstP(L);
        firstP(L) = nextP(p);
        nextP(p) = NULL;
    }
}

void deleteAfterParent(List_parent &L, adr_parent prec, adr_parent &p)
{
    /*
    IS : Terdefinisi List L yang mungkin kosong atau memiliki lebih dari 1 elemen
    FS : Jika list kosong, maka pointer P di assign dengan Nil, jika tidak kosong maka elemen setelah prec akan dihapus dari list L,
         alamatnya disimpan oleh pointer p
    */
    if (nextP(prec) == NULL or firstP(L) == NULL) // jika prec berada di elemen terakhir atau jika list kosong
    {
        p = NULL;
    }
    else // jika elemen yang ingin dihapus berada di tengah atau di akhir
    {
        p = nextP(prec);
        nextP(prec) = nextP(p);
        nextP(p) = NULL;
    }
}

void deleteLastParent(List_parent &L, adr_parent &p)
{
    /*
    IS : Terdefinisi List L yang mungkin kosong atau hanya memiliki 1 elemen
    FS : Jika list kosong, maka pointer P di assign dengan NIL, jika tidak kosong maka elemen paling akhir dihapus dari List L,
         alamatnya disimpan oleh pointer p
    */

    if (firstP(L) == NULL) // jika list kosong
    {
        p = NULL;
    }
    else if (nextP(firstP(L)) == NULL) // jika list hanya memiliki 1 elemen
    {
        p = firstP(L);
        firstP(L) = NULL;
    }
    else // jika list memiliki lebih dari 1 elemen
    {
        adr_parent q, p = firstP(L);
        while (nextP(p) != NULL)
        {
            q = p; // q berfungsi sebagai prec (menyimpan elemen sebelum last)
            p = nextP(p);
        }
        nextP(q) = NULL;
    }
}

void deletePenulis(List_parent &L, adr_parent p)
{
    /*
    IS : Terdefinisi List L dan alamat dari elemen yang ingin di hapus
    FS : Elemen p akan terhapus dari list
    */
    adr_parent q, prec; // q dan prec untuk delete after
    if (firstP(L) != NULL)
    {
        if (firstP(L) == p)
        {
            deleteFirstParent(L, p);
        }
        else if (nextP(p) == NULL)
        {
            deleteLastParent(L, p);
        }
        else
        {
            q = firstP(L);
            while (nextP(q) != p)
            {
                q = nextP(q);
            }
            prec = q;
            deleteAfterParent(L, prec, p);
        }
    }
}

void showAllListParent(List_parent L)
{
    /*
    IS : Terdefinisi List L yang mungkin kosong
    FS : Jika list kosong maka tampilkan ke layar “list kosong”, jika tidak maka seluruh data pada list ditampilkan ke layar
    */
    if (firstP(L) == NULL) // jika list kosong
    {
        cout << "List Penulis Kosong\n"
             << endl;
    }
    else // jika list tidak kosong
    {
        adr_parent q = firstP(L); // q berfungsi untuk menyimpan setiap elemen dari pertama hingga terakhir
        int i = 1;                // i berfungsi untuk iterasi urutan data
        while (q != NULL)
        {
            cout << "Penulis urutan ke-" << i << endl;
            cout << "ID: " << infoP(q).idPenulis << endl;
            cout << "Nama: " << infoP(q).nama << endl;
            cout << "Usia: " << infoP(q).usia << endl;
            cout << "Jenis Kelamin: " << infoP(q).jenisKelamin << endl;
            cout << "Email: " << infoP(q).email << endl;
            cout << endl;
            q = nextP(q);
            i++;
        }
    }
}

adr_parent findElmParent(List_parent L, string id, string nama)
{
    /*
    IS : Terdefinisi List L dan nama serta ID penulis yang akan dicari. List mungkin kosong
    FS : Return alamat dimana penulis ditemukan, return nil jika tidak ditemukan
    */

    adr_parent q = firstP(L); // q berfungsi untuk menemukan elemen yang dicari
    while (q != NULL)         // memastikan pencarian akan dilakukan jika list memiliki minimal 1 elemen
    {
        if (infoP(q).idPenulis == id and infoP(q).nama == nama)
        {
            return q; // jika data ditemukan
        }
        else
        {
            q = nextP(q);
        }
    }
    return NULL; // jika tidak ditemukan
}

void changeDataParent(List_parent &L, adr_parent p)
{
    /*
    IS : Terdefinisi Elemen penulis yang ingin diubah datanya
    FS : Data penulis telah ter-update
    */
    cout << "Masukkan Nama Terbaru: ";
    cin >> infoP(p).nama;
    cout << "Masukkan Usia Terbaru: ";
    cin >> infoP(p).usia;
    cout << "Masukkan Email Terbaru: ";
    cin >> infoP(p).email;
}