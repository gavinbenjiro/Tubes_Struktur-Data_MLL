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

#endif /* menu_h */