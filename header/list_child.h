#ifndef list_child_h
#define list_child_h
#include <iostream>
using namespace std;

// Alias
#define firstC(L) L.first
#define lastC(L) L.last
#define infoC(P) P->info
#define nextC(P) P->next
#define prevC(P) P->prev

// Implementasi Double-Linked List
struct buku
{
    string isbn;
    string judul;
    string penerbit;
    string tahunTerbit;
    string genre;
    int harga;
    float rating;
    int totalBukuTerjual;
};

typedef buku infotype_child;
typedef struct elmList_child *adr_child;

struct elmList_child
{
    infotype_child info;
    adr_child next;
    adr_child prev;
};

struct List_child
{
    adr_child first;
    adr_child last;
};

// function & procedure

#endif /* list_child_h */