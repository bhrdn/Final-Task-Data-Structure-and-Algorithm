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
    if (L.first == NULL && L.last == NULL) {
        L.first = P;
        L.last = P;
    }
    else {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}

void insertLast(listChild &L, addrChild P) {
    if (L.first == NULL && L.last == NULL) {
        L.first = P;
        L.last = P;
    }
    else {
        P->prev = L.last;
        L.last->next = P;
        L.last = P;
    };
}

void insertAfter(addrChild Prec, addrChild P) {
    (Prec->next)->prev = P;
    P->next = Prec->next;
    P->prev = Prec;
    Prec->next = P;
}

void deleteFirst(listChild &L) {
    if (L.first == NULL && L.last == NULL) {
        cout << "Empty" << endl;
    } else if (L.first == L.last) {
        L.first = NULL;
        L.last = NULL;
    } else {
        addrChild P = L.first;
        L.first = P->next;
        P->next = NULL;
        L.first->prev = NULL;
    }
}

void deleteLast(listChild &L) {
    if (L.first == NULL && L.last == NULL) {
        cout << "Empty" << endl;
    } else if (L.first == L.last) {
        L.first = NULL;
        L.last = NULL;
    } else {
        addrChild P = L.last;
        L.last = P->prev;
        P->prev = NULL;
        L.last->next = NULL;
    }
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
    addrChild Q;
    if(L.first == NULL && L.last == NULL) {
        Q = NULL;
    } else {
        Q = L.first;
        while (Q != NULL && Q->info != x) {
            Q = Q->next;
        };
    }

    return ((Q == NULL) ? NULL : Q);
}


