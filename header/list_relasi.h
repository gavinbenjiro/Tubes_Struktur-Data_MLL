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

#endif /* list_relasi_h */