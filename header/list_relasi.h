#ifndef list_relasi_h
#define list_relasi_h
#include "list_child.h"
#include "list_parent.h"
#include <iostream>
using namespace std;

// Alias
#define firstR(L) L.first
#define nextR(P) P->next
#define childR(P) P->child
#define parentR(P) P->parent

// Implementasi Single-Linked List
typedef struct elmList_relasi *adr_relasi;

struct elmList_relasi
{
    adr_relasi next;
    adr_child child;
    adr_parent parent;
};

struct List_relasi
{
    adr_relasi first;
};

// function & procedure
void createListRelasi(List_relasi &L);
adr_relasi newElmListRelasi(adr_parent elmP, adr_child elmC);
void insertLastRelasi(List_relasi &L, adr_relasi p);
void deleteFirstRelasi(List_relasi &L, adr_relasi &p);
void deleteAfterRelasi(List_relasi &L, adr_relasi prec, adr_relasi &p);
void deleteLastRelasi(List_relasi &L, adr_relasi &p);
void deleteRelasi(List_relasi &L, adr_relasi p);
void connectRelasi(List_relasi &L, List_parent LP, List_child LC, string id, string nama, string isbn, string genre, string judul);
void showParentAndChild(List_relasi L, List_parent LP);
adr_relasi findElmRelasiByChild(List_relasi L, adr_child buku);
adr_relasi findElmRelasiByParent(List_relasi L, adr_parent penulis);
void searchChildFromParent(List_relasi L, adr_parent p);
void deleteParentAndRelasiToChild(List_relasi &L, List_parent &LP, List_child &LC, adr_parent p);
void deleteRelasiChildFromParent(List_relasi &L, List_parent &LP, List_child &LC, adr_parent pParent, adr_child pChild);
int countSoldBooksFromParent(List_relasi L, adr_parent p);

#endif /* list_relasi_h */