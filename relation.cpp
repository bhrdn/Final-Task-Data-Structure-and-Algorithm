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
    if (L.first == NULL) {
        L.first = P;
        P->next = L.first;
    } else {
        addrRel Q = L.first;
        while (Q->next != L.first) {
            Q = Q->next;
        }   

        P->next = L.first;
        Q->next = P;
        L.first = P;
    }
}

void insertLast(listRel &L, addrRel P) {
    if (L.first == NULL)
    {
        insertFirst(L, P);
    } else {
        addrRel Q = L.first;
        while (Q->next != L.first) {
            Q = Q->next;
        }

        P->next = L.first;
        Q->next = P;
    }
}

void printInfo(listRel L) {
    addrRel P = L.first;
    while (P->next != L.first) {
        cout << (P->parent)->info.kode << " -> " << (P->child)->info << endl;
        P = P->next;
    }
    cout << (P->parent)->info.kode << " -> " << (P->child)->info << endl;
}

addrRel findElmParent(listRel L, addrParent P) {
    addrRel Q = L.first;
    while (Q != L.first) {
        if (Q->parent == P) {
            return Q;
            break;
        }
        Q = Q->next;
    }
    return NULL;
}

addrRel findElmChild(listRel L, addrChild P) {
    addrRel Q = L.first;
    while (Q != L.first) {
        if (Q->child == P) {
            return Q;
            break;
        }
        Q = Q->next;
    }
    return NULL;
}