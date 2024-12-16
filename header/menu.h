#ifndef menu_h
#define menu_h
#include "list_relasi.h"
#include <iostream>
using namespace std;

// Menu Utama
int menuUtama();

// Menu Parent
void menuShowAllParent();
void menuInsertParent();
void menuFindElmParent();
void menuChangeDataParent();

// Menu Child
void menuShowAllChild();
void menuInsertChild();
void menuFindElmChild();
void menuChangeDataChild();

// Menu Relasi
void menuShowAllParentAndChild();
void menuConnectRelasi();
void menuSearchChildFromParent();
void menuDeleteParentAndChild();
void menuDeleteChildFromParent();
void menuCountSoldBooks();

// Dummy Data
void elemenPenulis(List_parent &L);
void elemenBuku(List_child &L);
void elemenRelasi(List_relasi &L, List_parent LP, List_child LC);

#endif /* menu_h */