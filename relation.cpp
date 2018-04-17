#include "relation.h"

void createList(listRel &L) {
    L.first = NULL;
}

addrRel allocate(addrParent P, addrChild C) {
    addrRel Q = new elmRel;
    Q->child = C;
    Q->parent = P;
    Q->next = NULL;
    return Q;
}

void insertFirst(listRel &L, addrRel P) {
    // P->next = L.first;
    // L.first = P;
    addrRel Q;
    if (L.first == NULL) {
        L.first = P;
        P->next = P;
    } else {
        Q = L.first;
        while (Q->next != L.first) {
            Q = Q->next;
        }
        P->next = L.first;
        Q->next = P;
        L.first = P;
    }
}

void printInfo(listRel L) {
    addrRel P = L.first;
    while (P != NULL) {
        cout << (P->parent)->info.kode << " -> " << (P->child)->info << endl;
        P = P->next;
    }
}


addrRel findElm(listRel L, addrParent P, addrChild C) {
    addrRel Q = L.first;
    while (Q != NULL) {
        if (Q->parent == P && Q->child == C) {
            return Q;
        }
        Q = Q->next;
    }
    return NULL;
}

void insertAfter(addrRel &Prec, addrRel P) {
    P->next = Prec->next;
    Prec->next = P;
}
