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
    if (L.first == NULL) insertFirst(L, P);
    else {
        addrRel Q = L.first;
        while (Q->next != L.first) {
            Q = Q->next;
        }

        P->next = L.first;
        Q->next = P;
    }
}

void printInfo(listRel L) {
    if (L.first != NULL) {
        addrRel P = L.first;
        while (P->next != L.first) {
            cout << "-> [ " << (P->parent)->info.kode << " | " << (P->parent)->info.nama << " ] <---> " << (P->child)->info << endl;
            P = P->next;
        }
        cout << "-> [ " << (P->parent)->info.kode << " | " << (P->parent)->info.nama << " ] <---> " << (P->child)->info << endl;
    } else cout << "[-] Datas not found.." << endl;
}

void deleteRelationParent(listRel &L, addrParent &Q) {
    addrRel P = L.first;
    if (P->next == L.first && P->parent == Q) L.first = NULL;
    else {
        addrRel R;
        while (P->next != L.first && P->parent != Q) {
            R = P;
            P = P->next;
        }

        if ((L.first)->parent == Q) {
            while (R->next != L.first) {
                R = R->next;
            }

            L.first = P->next;
            R->next = L.first;
            P->next = NULL;
        } else if (P->next == L.first) {
            R->next = L.first;
            P->next = NULL;
        } else {
            R->next = P->next;
            P->next = NULL;
        }
    }
}

void deleteRelationChild(listRel &L, addrChild &Q) {
    addrRel P = L.first;
    if (P->next == L.first && P->child == Q) L.first = NULL;
    else {
        addrRel R;
        while (P->next != L.first && P->child != Q) {
            R = P;
            P = P->next;
        }

        if ((L.first)->child == Q) {
            while (R->next != L.first) {
                R = R->next;
            }

            L.first = P->next;
            R->next = L.first;
            P->next = NULL;
        } else if (P->next == L.first) {
            R->next = L.first;
            P->next = NULL;
        } else {
            R->next = P->next;
            P->next = NULL;
        }
    }
}

addrRel findParentRel(listRel L, addrParent Q) {
    addrRel P = L.first;
    if (L.first != NULL) {
        while (P->next != L.first) {
            if ((P->parent)->info.kode == Q->info.kode) {
                return P;
                break;
            }
            P = P->next;
        }

        if ((P->parent)->info.kode == Q->info.kode) return P;
        else return NULL;
    } else return NULL;
}

addrRel findChildRel(listRel L, addrChild Q) {
    addrRel P = L.first;
    if (L.first != NULL) {
        while (P->next != L.first) {
            if ((P->child)->info == Q->info) {
                return P;
                break;
            }
            P = P->next;
        }

        if ((P->child)->info == Q->info) return P;
        else return NULL;
    } else return NULL;
}