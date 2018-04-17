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

addrParent allocate(infoParent x);
void deallocate(addrParent &P);
void createList(listParent &L);

// INSERT
void insertFirst(listParent &L, addrParent P);
void insertLast(listParent &L, addrParent P);
void insertAfter(listParent &L, addrParent Prec, addrParent P);

// DELETE
void deleteFirst(listParent &L, addrParent &P);
void deleteLast(listParent &L, addrParent &P);
void deleteAfter(listParent &L, addrParent Prec, addrParent &P);

void printInfo(listParent L);
addrParent findElm(listParent L, infoParent x);
