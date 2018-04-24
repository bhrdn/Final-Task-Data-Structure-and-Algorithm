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
    if (L.first == NULL) {
        L.first = P;
    } else {
        P->next = L.first;
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
    }
}

void insertAfter(listParent &L, addrParent Prec, addrParent P) {
    P->next = Prec->next;
    Prec->next = P;
}

void deleteFirst(listParent &L, addrParent &P) {
    if (L.first != NULL) {
        if ((L.first)->next == NULL) {
            P = L.first;
            L.first = NULL;
        } else {
            P = L.first;
            L.first = (L.first)->next;
            P->next = NULL;
        }
    }

    deallocate(P);
}

void deleteLast(listParent &L, addrParent &P) {
    if (L.first != NULL) {
        if ((L.first)->next == NULL) {
            P = L.first;
            L.first = NULL;
        }
        else {
            addrParent Q = L.first;
            while ((Q->next)->next != NULL) {
                Q = Q->next;
            }
            P = Q->next;
            Q->next = NULL;
        }
    }

    deallocate(P);
}

void deleteAfter(listParent &L, addrParent Prec, addrParent &P) {
    P = Prec->next;
    Prec->next = P->next;
    P->next = NULL;

    deallocate(P);
}

void deleteParent(listParent &L, addrParent &P) {
    if (L.first != P)
    {
        addrParent X = L.first;
        while (X->next != NULL && X->next != P) {
            X = X->next;
        }
        X->next = NULL;
        deallocate(X);
    } else deleteFirst(L, P);
}

void printInfo(listParent L) {
    addrParent P = L.first;
    if (L.first != NULL) {
        do {
            cout << "-> " << P->info.kode << " | " << P->info.nama << endl;
            P = P->next;
        } while ((P) != NULL);
    }
}

// small bug (first)
addrParent findElm(listParent L, string x) {
    addrParent P;
    if (L.first != NULL) {
        addrParent Q = L.first;
        if (Q->info.kode == x) {
            P = Q;
        } else {
            while ((Q != NULL) && (Q->info.kode != x)) {
                Q = Q->next;
            };
            (Q == L.first) ? P = NULL : P = Q;
        }
    }
    return P;
}
