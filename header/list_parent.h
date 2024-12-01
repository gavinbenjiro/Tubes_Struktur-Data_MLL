#ifndef list_parent_h
#define list_parent_h
#include <iostream>
using namespace std;

// Implementasi Single-Linked List
struct penulis
{
    string idPenulis;
    string nama;
    int usia;
    string email;
    string jenisKelamin;
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

#endif /* list_parent_h */