#include "child.h"

void createList(listChild &L) {
    L.first = NULL;
    L.last = NULL;
}

addrChild alokasi(string x) {
    addrChild P = new elmChild;
    P->info = x;
    P->next = NULL;
    P->prev = NULL;
    return P;
}

void insertFirst(listChild &L, addrChild P) {
    if(L.first == NULL) {
        L.last = P;
        L.first = P;
    } else {
        P->next = L.first;
        (L.first)->prev = P;
        L.first = P;
    }
}

void printInfo(listChild L) {
    addrChild P = L.first;
    while(P != NULL) {
        cout<< "->" << P->info <<endl;
        P = P->next;
    }
}


addrChild findElm(listChild L, string x) {
    addrChild P = L.first;
    while(P != NULL) {
        if(P->info==x) {
            return P;
        }
        P = P->next;
    }
    return NULL;
}

void insertAfter(addrChild &Prec, addrChild P) {
    (Prec->next)->prev = P;
    P->next = Prec->next;
    P->prev = Prec;
    Prec->next = P;
}
