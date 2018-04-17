#include "parent.h"

addrParent allocate(infoParent x) {
    addrParent P;
    P = new elmParent;
    P->info = x;
    P->next = NULL;
    return P;
}

void deallocate(addrParent &P) {
    delete P;
}

void createList(listParent &L) {
    L.first = NULL;
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

void insertLast(listParent &L, addrParent P) {
    if (L.first == NULL)
    {
        insertFirst(L, P);
    } else {
        addrParent Q = L.first;
        while (Q->next != NULL) {
            Q = Q->next;
        }

        Q->next = P;
        Q = NULL;
        P = NULL;
    }
}

void insertAfter(listParent &L, addrParent Prec, addrParent P) {
    P->next = Prec->next;
    Prec->next = P;
}

void deleteFirst(listParent &L, addrParent &P) {
    if (L.first != NULL) {
        P = L.first;
        L.first = P->next;
        deallocate(P);
        P->next = NULL;
    }
}

void deleteLast(listParent &L, addrParent &P) {
    addrParent Q = L.first;
    while (Q->next != P) {
        Q = Q->next;
    }
    Q->next = NULL;
    deallocate(P);
}

void deleteAfter(listParent &L, addrParent Prec, addrParent &P) {
    Prec->next = P->next;
    deallocate(P);
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
