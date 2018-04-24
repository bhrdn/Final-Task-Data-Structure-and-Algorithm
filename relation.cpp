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

int totalChild(listRel LR, addrChild C) {
    int i; // counter
    addrRel Q = LR.first;
    while (Q != LR.first) {
        if (Q->child == C)
        {
            cout << Q->child->info << endl;
            i++;
        }
        Q = Q->next;
    }

    return i;
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
    if (L.first != NULL)
    {
        addrRel P = L.first;
        while (P->next != L.first) {
            cout << (P->parent)->info.kode << " -> " << (P->child)->info << endl;
            P = P->next;
        }
        cout << (P->parent)->info.kode << " -> " << (P->child)->info << endl;
    }
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

/*
    void deleteFirst(listRel &L, addrRel &P) {
        P = L.first;
        if (P != NULL){
            if (P->next == L.frist) {
                next(P) = NULL;
                L.first = NULL;
            }
            else {
                addrRel Q = L.first;
                while (Q->next != L.first) {
                    Q = Q->next;
                }
                L.first = P->next;
                Q->next = P->next;
                P->next = NULL;
            }
        }

        deallocate(P);
    }

    void deleteLast(listRel &L, addrRel &P) {
        P = L.first;
        if (P != NULL) {
            if (P->next = L.first) {
                P->next = NULL;
                L.first = NULL;
            }
            else {
                addrRel Q = L.first;
                while (Q->next->next != L.first) {
                    Q = Q->next;
                }
                P = Q->next;
                Q->next = P->next;
                P->next = NULL;
            }
        }

        deallocate(P);
    }

    void deleteAfter(listRel &L, addrRel Prec, addrRel &P) {
        if (L.first != NULL && Prec != NULL) {
            if(Prec->next == L.first){
                deleteFirst(L, P);
            }
            else {
                P = Prec->next;
                Prec->next = P->next;
                P->next = NULL;
                deallocate(P);
            }
        }
    }

    void deleteRelation(listRel &L, addrParent P, addrRel R){
        R = L.first;
        while (//kondisi sampai nextnya first && R->next->parent != P) {
            
            // Jika parentnya sesuai jalanin delete
            
            if (R->parent == P) {
            if (R == L.first) {
                deleteFirst(L, P);
            }
            else if (R->next == L.first) {
                deleteLast(L, P);
            }
            else
                //delete yg tengah
            }
            
            R = R->next;
        }
        
    }
*/