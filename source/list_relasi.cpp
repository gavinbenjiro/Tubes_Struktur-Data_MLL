#include "../header/list_relasi.h"

void createListRelasi(List_relasi &L)
{
    /*
    IS : -
    FS : Pointer First dari List L bernilai Nil
    */
    firstR(L) = NULL;
}

adr_relasi newElmListRelasi(adr_parent elmP, adr_child elmC)
{
    /*
    IS : Terdefinisi elemen penulis dan elemen buku yang akan dihubungkan
    FS : Mengembalikan elemen list baru dengan relasi parent = elmP, relasi child = elmC, dan next elemen = Nil
    */
    adr_relasi p;           // alamat untuk membentuk elemen baru
    p = new elmList_relasi; // elemen baru terbentuk
    parentR(p) = elmP;
    childR(p) = elmC;
    nextR(p) = NULL;
    return p;
}

void insertLastRelasi(List_relasi &L, adr_relasi p)
{
    /*
    IS : Terdefinisi List L yang mungkin kosong dan sebuah elemen baru yang alamatnya disimpan oleh pointer P
    FS : Elemen baru telah masuk menjadi elemen paling akhir di list L
    */
    if (firstR(L) == NULL) // jika list kosong
    {
        firstR(L) = p;
    }
    else // jika list tidak kosong
    {
        adr_relasi q = firstR(L); // q berfungsi untuk mencari elemen terakhir
        while (nextR(q) != NULL)
        {
            q = nextR(q);
        }
        nextR(q) = p;
    }
}

void deleteFirstRelasi(List_relasi &L, adr_relasi &p)
{
    /*
    IS : Terdefinisi List L yang mungkin kosong atau hanya memiliki 1 elemen
    FS : Jika list kosong, maka pointer P di assign dengan NIL, jika tidak kosong maka elemen paling awal dihapus dari List L,
         alamatnya disimpan oleh pointer p
    */
    if (firstR(L) == NULL) // jika list kosong
    {
        p = NULL;
    }
    else // jika list memiliki minimal 1 elemen
    {
        p = firstR(L);
        firstR(L) = nextR(p);
        nextR(p) = NULL;
    }
}

void deleteAfterRelasi(List_relasi &L, adr_relasi prec, adr_relasi &p)
{
    /*
    IS : Terdefinisi List L yang mungkin kosong atau memiliki lebih dari 1 elemen
    FS : Jika list kosong, maka pointer P di assign dengan Nil, jika tidak kosong maka elemen setelah prec akan dihapus dari list L,
         alamatnya disimpan oleh pointer p
    */
    if (nextR(prec) == NULL or firstR(L) == NULL) // jika prec berada di elemen terakhir atau jika list kosong
    {
        p = NULL;
    }
    else // jika elemen yang ingin dihapus berada di tengah atau di akhir
    {
        p = nextR(prec);
        nextR(prec) = nextR(p);
        nextR(p) = NULL;
    }
}

void deleteLastRelasi(List_relasi &L, adr_relasi &p)
{
    /*
    IS : Terdefinisi List L yang mungkin kosong atau hanya memiliki 1 elemen
    FS : Jika list kosong, maka pointer P di assign dengan NIL, jika tidak kosong maka elemen paling akhir dihapus dari List L,
         alamatnya disimpan oleh pointer p
    */
    if (firstR(L) == NULL) // jika list kosong
    {
        p = NULL;
    }
    else if (nextR(firstR(L)) == NULL) // jika list hanya memiliki 1 elemen
    {
        p = firstR(L);
        firstR(L) = NULL;
    }
    else // jika list memiliki lebih dari 1 elemen
    {
        adr_relasi q, p = firstR(L);
        while (nextR(p) != NULL)
        {
            q = p; // q berfungsi sebagai prec (menyimpan elemen sebelum last)
            p = nextR(p);
        }
        nextR(q) = NULL;
    }
}

void deleteRelasi(List_relasi &L, adr_relasi p)
{
    /*
    IS : Terdefinisi List L dan alamat dari elemen yang ingin di hapus
    FS : Elemen p akan terhapus dari list
    */
    adr_relasi q, prec; // q dan prec untuk delete after
    if (firstR(L) != NULL)
    {
        if (firstR(L) == p)
        {
            deleteFirstRelasi(L, p);
        }
        else if (nextR(p) == NULL)
        {
            deleteLastRelasi(L, p);
        }
        else
        {
            q = firstR(L);
            while (nextR(q) != p)
            {
                q = nextR(q);
            }
            prec = q;
            deleteAfterRelasi(L, prec, p);
        }
    }
}

void connectRelasi(List_relasi &L, List_parent LP, List_child LC, string id, string nama, string isbn, string genre, string judul)
{
    /*
    IS : Terdefinisi List relasi, parent, dan child beserta nilai infotype dari penulis dan buku
    FS : Terbentuk sebuah relasi antara elemen parent dengan child yang dihubungkan dengan elemen relasi
    */
    adr_parent elmP; // untuk menyimpan alamat penulis
    adr_child elmC;  // untuk menyimpan alamat buku
    adr_relasi p;    // untuk menyimpan alamat relasi

    elmP = findElmParent(LP, id, nama);          // mencari elemen penulis
    elmC = findElmChild(LC, isbn, genre, judul); // mencari elemen buku
    if (elmP != NULL and elmC != NULL)           // memastikan jika elemen penulis dan buku terdapat dalam list
    {
        p = newElmListRelasi(elmP, elmC);
        insertLastRelasi(L, p);
        cout << "Penulis " << nama << " dengan Buku " << judul << " Berhasil Terhubung" << endl;
    }
    else // jika elemen penulis atau elemen buku ada yang tidak valid
    {
        cout << "Data Penulis atau Data Buku Tidak Tersedia" << endl;
    }
}

void showParentAndChild(List_relasi L, List_parent LP)
{
    /*
    IS : Terdefinisi List relasi & parent yang mungkin kosong
    FS : Jika list kosong maka tampilkan ke layar "tidak ada relasi penulis dan buku”, jika tidak maka seluruh data parent beserta child pada list ditampilkan ke layar
    */
    if (firstR(L) == NULL and firstP(LP) == NULL) // jika tidak ada relasi antara penulis dengan buku
    {
        cout << "Tidak Ada Relasi Antara Penulis dengan Buku\n"
             << endl;
    }
    else // jika terdapat relasi antara penulis dengan buku
    {
        adr_parent nodeP = firstP(LP); // untuk menyimpan alamat elemen penulis
        int i = 1;                     // i berfungsi untuk iterasi urutan data penulis

        while (nodeP != NULL) // perulangan sampai P tidak lagi memegang elemen penulis
        {
            cout << "Penulis urutan ke-" << i << endl;
            cout << "ID: " << infoP(nodeP).idPenulis << endl;
            cout << "Nama: " << infoP(nodeP).nama << endl;
            cout << "Usia: " << infoP(nodeP).usia << endl;
            cout << "Jenis Kelamin: " << infoP(nodeP).jenisKelamin << endl;
            cout << "Email: " << infoP(nodeP).email << endl;
            cout << endl;
            adr_relasi nodeR = firstR(L); // untuk menyimpan alamat elemen relasi
            int x = 1;                    // x berfungsi untuk iterasi urutan data buku
            while (nodeR != NULL)         // perulangan sampai R tidak lagi memegang elemen relasi
            {
                if (parentR(nodeR) == nodeP) // jika elemen pada parent dari R menunjuk penulis yang sama dengan P
                {
                    cout << "Buku ke-" << x << endl;
                    cout << "ISBN: " << infoC(childR(nodeR)).isbn << endl;
                    cout << "Judul: " << infoC(childR(nodeR)).judul << endl;
                    cout << "Penerbit: " << infoC(childR(nodeR)).penerbit << endl;
                    cout << "Tahun Terbit: " << infoC(childR(nodeR)).tahunTerbit << endl;
                    cout << "Genre: " << infoC(childR(nodeR)).genre << endl;
                    cout << "Harga: " << infoC(childR(nodeR)).harga << endl;
                    cout << "Rating: " << infoC(childR(nodeR)).rating << endl;
                    cout << "Total Terjual: " << infoC(childR(nodeR)).totalBukuTerjual << endl;
                    cout << endl;
                    x++;
                }
                nodeR = nextR(nodeR);
            }
            cout << "--------------------------------------\n"
                 << endl;
            nodeP = nextP(nodeP);
            i++;
        }
    }
}

adr_relasi findElmRelasiByChild(List_relasi L, adr_child buku)
{
    /*
    IS : Terdefinisi List L dan alamat buku yang akan dicari. List mungkin kosong
    FS : Return alamat dimana relasi ditemukan, return nil jika tidak ditemukan
    */
    adr_relasi q = firstR(L); // q berfungsi untuk menemukan elemen yang diari
    while (q != NULL)         // memastikan pencarian akan dilakukan jika list memiliki minimal 1 elemen
    {
        if (childR(q) == buku)
        {
            return q; // jika data ditemukan
        }
        else
        {
            q = nextR(q);
        }
    }
    return NULL; // jika tidak ditemukan
}

adr_relasi findElmRelasiByParent(List_relasi L, adr_parent penulis)
{
    /*
    IS : Terdefinisi List L dan alamat penulis yang akan dicari. List mungkin kosong
    FS : Return alamat dimana relasi ditemukan, return nil jika tidak ditemukan
    */
    adr_relasi q = firstR(L); // q berfungsi untuk menemukan elemen yang diari
    while (q != NULL)         // memastikan pencarian akan dilakukan jika list memiliki minimal 1 elemen
    {
        if (parentR(q) == penulis)
        {
            return q; // jika data ditemukan
        }
        else
        {
            q = nextR(q);
        }
    }
    return NULL; // jika tidak ditemukan
}

void searchChildFromParent(List_relasi L, adr_parent p)
{
    /*
    IS : Terdefinisi elemen penulis p
    FS : Menampilkan seluruh buku yang ditulis oleh penulis p
    */
    adr_relasi elmR = firstR(L); // untuk menyimpan alamat elemen relasi
    int i = 1;                   // i berfungsi untuk iterasi urutan data penulis
    cout << "Menampilkan Seluruh Buku yang Ditulis Oleh " << infoP(p).nama << endl
         << endl;
    while (elmR != NULL) // perulangan sampai R tidak lagi memegang elemen relasi
    {
        if (parentR(elmR) == p) // jika elemen pada parent dari R menunjuk penulis yang sama dengan P
        {
            cout << "Buku ke-" << i << endl;
            cout << "ISBN: " << infoC(childR(elmR)).isbn << endl;
            cout << "Judul: " << infoC(childR(elmR)).judul << endl;
            cout << "Penerbit: " << infoC(childR(elmR)).penerbit << endl;
            cout << "Tahun Terbit: " << infoC(childR(elmR)).tahunTerbit << endl;
            cout << "Genre: " << infoC(childR(elmR)).genre << endl;
            cout << "Harga: " << infoC(childR(elmR)).harga << endl;
            cout << "Rating: " << infoC(childR(elmR)).rating << endl;
            cout << "Total Terjual: " << infoC(childR(elmR)).totalBukuTerjual << endl;
            cout << endl;
            i++;
        }
        elmR = nextR(elmR);
    }
}

void deleteParentAndRelasiToChild(List_relasi &L, List_parent &LP, List_child &LC, adr_parent p)
{
    /*
    IS : Terdefinisi elemen penulis p yang akan dihapus
    FS : Elemen penulis P terhapus beserta relasi kepada buknya, jika elemen buku tidak berelasi ke penulis lainnya maka buku akan terhapus
    */
    adr_relasi elmR = firstR(L); // untuk menyimpan alamat elemen relasi untuk looping
    adr_relasi q;                // untuk menyimpan alamat elemen relasi guna mencari elemen relasi & menghapus elemen relasi
    adr_child elmC;              // untuk menyimpan elemen buku dan akan menghapus buku jika tidak ada relasi lagi terhadap elemen buku tersebut
    // menghapus relasi antara buku dengan penulis yang ingin dihapus
    while (elmR != NULL) // perulangan sampai R tidak lagi memegang elemen relasi
    {
        if (parentR(elmR) == p) // jika elemen pada parent dari R menunjuk penulis yang sama dengan P
        {
            parentR(elmR) = NULL;              // parent dari elemen relasi akan NULL
            elmC = childR(elmR);               // child dari elemen relasi disimpan ke dalam elmC
            childR(elmR) = NULL;               // child dari elemen relasi akan NULL
            q = findElmRelasiByChild(L, elmC); // mencari elemen relasi berdasarkan buku
            if (q == NULL)                     // jika q bernilai NULL artinya tidak ada lagi relasi terhadap buku yang disimpan oleh elmC
            {
                deleteBuku(LC, elmC); // buku tidak berelasi lagi dengan penulis manapun, maka buku akan terhapus
            }
        }
        elmR = nextR(elmR);
    }
    // menghapus elemen relasi yang sudah tidak berelasi dengan penulis dan buku
    elmR = firstR(L);
    while (elmR != NULL) // perulangan sampai R tidak lagi memegang elemen relasi
    {
        q = elmR;
        elmR = nextR(elmR);                           // elmR menyimpan nilai dari next(q)
        if (parentR(q) == NULL and childR(q) == NULL) // jika elemen relasi tidak lagi menghubungkan antara penulis dengan buku
        {
            deleteRelasi(L, q); // relasi tidak lagi menghubungkan penulis dengan buku manapun, maka relasi akan terhapus
        }
    }
    // menghapus elemen penulis
    deletePenulis(LP, p);
}

void deleteRelasiChildFromParent(List_relasi &L, List_parent &LP, List_child &LC, adr_parent pParent, adr_child pChild)
{
    /*
    IS : Terdefinisi elemen penulis dan elemen buku yang akan dihapus
    FS : Relasi antara penulis pParent dan buku pChild terhapus, jika elemen buku tidak berelasi ke penulis lainnya maka buku akan terhapus
         dan jika elemen penulis tidak berelasi ke buku lainnya maka penulis akan terhapus
    */
    adr_relasi elmR = firstR(L); // untuk menyimpan alamat elemen relasi untuk looping
    adr_relasi q;                // untuk menyimpan alamat elemen relasi guna mencari elemen relasi & menghapus elemen relasi
    adr_child elmC;              // untuk menyimpan elemen buku dan akan menghapus buku jika tidak ada relasi lagi terhadap elemen buku tersebut
    // menghapus relasi antara buku dengan penulis yang ingin dihapus
    while (elmR != NULL) // perulangan sampai R tidak lagi memegang elemen relasi
    {
        if (parentR(elmR) == pParent and childR(elmR) == pChild) // jika elemen relasi menghubungkan penulis dengan buku yang dicari
        {
            parentR(elmR) = NULL;              // parent dari elemen relasi akan NULL
            elmC = childR(elmR);               // child dari elemen relasi disimpan ke dalam elmC
            childR(elmR) = NULL;               // child dari elemen relasi akan NULL
            q = findElmRelasiByChild(L, elmC); // mencari elemen relasi berdasarkan buku
            if (q == NULL)                     // jika q bernilai NULL artinya tidak ada lagi relasi terhadap buku yang disimpan oleh elmC
            {
                deleteBuku(LC, elmC); // buku tidak berelasi lagi dengan penulis manapun, maka buku akan terhapus
            }
        }
        elmR = nextR(elmR);
    }
    // menghapus elemen relasi yang sudah tidak berelasi dengan penulis dan buku
    elmR = firstR(L);
    while (elmR != NULL) // perulangan sampai R tidak lagi memegang elemen relasi
    {
        q = elmR;
        elmR = nextR(elmR);                           // elmR menyimpan nilai dari next(q)
        if (parentR(q) == NULL and childR(q) == NULL) // jika elemen relasi tidak lagi menghubungkan antara penulis dengan buku
        {
            deleteRelasi(L, q); // relasi tidak lagi menghubungkan penulis dengan buku manapun, maka relasi akan terhapus
        }
    }
    // menghapus elemen parent jika sudah tidak ada relasi dengan buku
    q = findElmRelasiByParent(L, pParent);
    if (q == NULL)
    {
        deletePenulis(LP, pParent);
    }
}

int countSoldBooksFromParent(List_relasi L, adr_parent p)
{
    /*
    IS : Terdefinisi elemen penulis
    FS : Mengembalikan jumlah total buku terjual dari penulis p
    */
    adr_relasi elmR = firstR(L); // untuk menyimpan alamat elemen relasi untuk looping
    int total = 0;               // untuk menyimpan akumulasi dari total penjual buku

    while (elmR != NULL)
    {
        if (parentR(elmR) == p)
        {
            total += infoP(childR(elmR)).totalBukuTerjual;
        }
        elmR = nextR(elmR);
    }
    return total;
}