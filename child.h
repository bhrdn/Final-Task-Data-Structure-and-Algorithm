#include "init.h"

typedef struct elmChild *addrChild;

struct elmChild{
    string info;
    addrChild next;
    addrChild prev;
};

struct listChild{
    addrChild first;
    addrChild last;
};

void createList(listChild &L);
void insertFirst(listChild &L, addrChild P);
void insertLast(listChild &L, addrChild P);
void insertAfter(addrChild Prec, addrChild P);
void deleteFirst(listChild &L, addrChild &P);
void deleteLast(listChild &L, addrChild &P);
void deleteAfter(addrChild Prec, addrChild &P);

addrChild alokasi(string x);
void dealokasi(addrChild &P);
addrChild findElm(listChild L, string x);
void printInfo(listChild L);