typedef struct elmRel *addrRel;

struct elmRel {
	addrRel next;
	addrChild child;
	addrParent parent;
};

struct listRel {
	addrRel first;
};

void createList(listRel &L);
void insertFirst(listRel &L, addrRel P);
void insertLast(listRel &L, addrRel P);
void insertAfter(addrRel Prec, addrRel P);
void deleteFirst(listRel &L, addrRel P);
void deleteLast(listRel &L, addrRel &P);
void deleteAfter(addrRel Prec, addrRel &P);
void deleteRelationParent(listRel &L, addrParent &Q);

addrRel allocate(addrParent P, addrChild C);
void deallocate(addrRel &P);
void printInfo(listRel L);
addrRel findParentRel(listRel L, addrParent Q);
addrRel findChildRel(listRel L, addrChild Q);