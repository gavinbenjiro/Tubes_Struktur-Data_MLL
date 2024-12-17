#ifndef list_parent_h
#define list_parent_h
#include <iostream>
using namespace std;

// Alias
#define firstP(L) L.first
#define infoP(P) P->info
#define nextP(P) P->next

// Implementasi Single-Linked List
struct penulis
{
    string idPenulis; // kode unik penulis
    string nama;
    int usia;
    string email;
    char jenisKelamin;
};

typedef penulis infotype_parent;
typedef struct elmList_parent *adr_parent;

struct elmList_parent
{
    infotype_parent info;
    adr_parent next;
};

struct List_parent
{
    adr_parent first;
};

// function & procedure
void createListParent(List_parent &L);
adr_parent newElmListParent(infotype_parent x);
void insertLastParent(List_parent &L, adr_parent p);
void deleteFirstParent(List_parent &L, adr_parent &p);
void deleteAfterParent(List_parent &L, adr_parent prec, adr_parent &p);
void deleteLastParent(List_parent &L, adr_parent &p);
void deletePenulis(List_parent &L, adr_parent p);
void showAllListParent(List_parent L);
adr_parent findElmParent(List_parent L, string id, string nama);
void changeDataParent(List_parent &L, adr_parent p);

#endif /* list_parent_h */