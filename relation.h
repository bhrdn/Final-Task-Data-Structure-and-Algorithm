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

addrRel allocate(addrParent P, addrChild C);
void deallocate(addrRel &P);
addrRel findElm(listRel L, addrParent P, addrChild C);
void printInfo(listRel L);
