typedef struct elmChild *addrChild;

struct elmChild {
	string info;
	addrChild next;
	addrChild prev;
};

struct listChild {
	addrChild first;
	addrChild last;
};

addrChild allocate(string x);
void deallocate(addrChild &P);
void createList(listChild &L);

// INSERT
void insertFirst(listChild &L, addrChild P);
void insertLast(listChild &L, addrChild P);
void insertAfter(addrChild Prec, addrChild P);
void insertSort(listChild &L, addrChild P);

// DELETE
void deleteFirst(listChild &L);
void deleteLast(listChild &L);
void deleteAfter(listChild &L, addrChild Prec, addrChild &P);
void deleteChild(listChild &L, addrChild &P);

void printInfo(listChild L);
addrChild findElm(listChild L, string x);