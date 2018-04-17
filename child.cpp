#include "child.h"

addrChild allocate(string x) {
    addrChild P = new elmChild;
    P->info = x;
    P->next = NULL;
    P->prev = NULL;
    return P;
}

void deallocate(addrChild &P) {
    delete P;
}

void createList(listChild &L) {
    L.first = NULL;
    L.last = NULL;
}

void insertFirst(listChild &L, addrChild P) {
    if (L.first == NULL) {
        L.last = P;
        L.first = P;
    } else {
        P->next = L.first;
        (L.first)->prev = P;
        L.first = P;
    }
}

void insertLast(listChild &L, addrChild P) {
    if (L.first == NULL && L.last == NULL) {
        insertFirst(L, P);
    }
    else {
        P->prev = L.last;
        (L.last)->next = P;
        L.last = P;
    }
}

void insertAfter(addrChild Prec, addrChild P) {
    (Prec->next)->prev = P;
    P->next = Prec->next;
    P->prev = Prec;
    Prec->next = P;
}

void deleteFirst(listChild &L, addrChild &P) {
    if (L.first != NULL) {
        P = L.first;
        if (L.first == L.last) {
            L.first = NULL;
            L.last = NULL;
            deallocate(P);
        }
        else {
            L.first = P->next;
            P->next = NULL;
            (L.first)->prev = NULL;
            deallocate(P);
        }
    }
}

void deleteLast(listChild &L, addrChild &P) {
    P = L.last;
    L.last = P->prev;
    (L.last)->next = NULL;
    P->prev = NULL;
    deallocate(P);
}

void deleteAfter(listChild &L, addrChild Prec, addrChild &P) {
    Prec->next = P->next;
    (P->next)->prev = Prec;
    P->next = NULL;
    P->prev = NULL;
    deallocate(P);
}

void printInfo(listChild L) {
    addrChild P = L.first;
    while (P != NULL) {
        cout << "-> " << P->info << endl;
        P = P->next;
    }
}

addrChild findElm(listChild L, string x) {
    addrChild P = L.first;
    while (P != NULL) {
        if (P->info == x) {
            return P;
        }
        P = P->next;
    }
    return NULL;
}


