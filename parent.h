#include "init.h"

typedef struct elmParent *addrParent;

struct infoParent
{
	string kode;
	string nama;
};

struct elmParent {
    infoParent info;
    addrParent next;
};

struct listParent {
    addrParent first;
};

void createList(listParent &L);
void insertFirst(listParent &L, addrParent P);
void insertAfter(listParent &L, addrParent Prec, addrParent P);
void insertLast(listParent &L, addrParent P);
void deleteFirst(listParent &L, addrParent &P);
void deleteLast(listParent &L, addrParent &P);
void deleteAfter(listParent &L, addrParent Prec, addrParent &P);

addrParent alokasi(infoParent x);
void dealokasi(addrParent &P);
addrParent findElm(listParent L, infoParent x);
void printInfo(listParent L);
