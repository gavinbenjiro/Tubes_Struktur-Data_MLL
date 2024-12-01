#ifndef list_relasi_h
#define list_relasi_h
#include "list_child.h"
#include "list_parent.h"
#include <iostream>
using namespace std;

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