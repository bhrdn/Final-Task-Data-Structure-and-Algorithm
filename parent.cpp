#include "parent.h"

void createList(listParent &L) {
    L.first = NULL;
}

addrParent alokasi(infoParent x) {
    addrParent P;
    P = new elmParent;
    P->info = x;
    P->next = NULL;
    return P;
}

void insertFirst(listParent &L, addrParent P) {
    addrParent Q;
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

void printInfo(listParent L) {
    addrParent P = L.first;
    if (L.first != NULL) {
        do {
            cout << P->info.kode << " | " << P->info.nama << endl;
            P = P->next;
        } while ((P) != L.first);
    }
}

addrParent findElm(listParent L, string x) {
    addrParent P = L.first;
    do {
        if (P->info.kode == x) {
            return P;
        }
        P = P->next;
    } while (P != L.first);
    return NULL;
}
