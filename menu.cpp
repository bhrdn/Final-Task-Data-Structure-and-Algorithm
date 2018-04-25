#include "menu.h"

void printBanner() {
	cout << R"(
  ==============================================
 | FINAL TASK DATA STRUCTURE AND ALGORITHM 2018 |
  ==============================================

 ---------------+---------------
           ___ /^^[___              _
          /|^+----+   |#___________//
        ( -+ |____|    ______-----+/
         ==_________--'            \
           ~_|___|__

 [Data Alat Transport]
 - Habib Bahruddin (1301174412)
 - Husna Assabiila Yassarah (1301174079)
	)";
}

void addDatas(string x, listParent &LP, listChild &LC, listRel &LR) {
	if (x == "angkutan")
	{
		do {
			system("clear");
			cin.ignore();
			cout << "[ ADD DATAS (Angkutan)]" << endl;
			cout << "> Plat Nomor: "; getline(cin, angkutan.kode);
			cout << "> Nama Angkutan: "; getline(cin, angkutan.nama);

			if (findElm(LP, angkutan.kode) == false)
			{
				addrParent P = allocate(angkutan);
				insertFirst(LP, P);
			} else cout << endl << "[-] Duplicate datas.." << endl;

			cout << endl << "[*] Add datas, again? [y/t]: "; cin >> repeat;
		} while (repeat != 't' && repeat != 'T');
	} else if (x == "daerah") {
		do {
			system("clear");
			cin.ignore();
			cout << "[ ADD DATAS (Daerah)]" << endl;
			cout << "> Nama Daerah: "; getline(cin, daerah);

			if (findElm(LC, daerah) == false)
			{
				addrChild P = allocate(daerah);
				insertLast(LC, P);
			} else cout << endl << "[-] Duplicate datas.." << endl;

			cout << endl << "[*] Add datas, again? [y/t]: "; cin >> repeat;
		} while (repeat != 't' && repeat != 'T');
	} else if (x == "relasi") {
		do {
			system("clear");
			cin.ignore();
			cout << " [ ADD NEW RELATION - From Parent to Child ]" << endl << endl;

			cout << "[*] Datas Parent (Angkutan)" << endl;
			printInfo(LP);
			cout << endl;

			cout << "[*] Datas Child (Daerah)" << endl;
			printInfo(LC);
			cout << endl;

			cout << "> Kode Angkutan: "; getline(cin, angkutan.kode);
			cout << "> Nama Daerah: "; getline(cin, daerah);

			addrParent srcParent = findElm(LP, angkutan.kode);
			addrChild srcChild = findElm(LC, daerah);

			if (srcParent != NULL && srcChild != NULL)
			{
				addrRel datas = allocate(srcParent, srcChild);
				insertLast(LR, datas);
			} else
			{
				cout << endl << "[-] Datas not found.." << endl;
			}

			cout << endl << "[*] Add datas, again? [y/t]: "; cin >> repeat;
		} while (repeat != 't' && repeat != 'T');
	}
}

void showDatas(string x, listParent &LP, listChild &LC, listRel &LR) {
	if (x == "all") {
		system("clear");
		cin.ignore();

		cout << " [ SHOW ALL DATAS ] " << endl << endl;

		cout << "[*] Data Angkutan" << endl;
		printInfo(LP); cout << endl;

		cout << "[*] Data Daerah" << endl;
		printInfo(LC); cout << endl;

		cout << "[*] Data Relasi" << endl;
		printInfo(LR);

		cin.ignore().get();
	} else if (x == "daerah") {
		system("clear");
		cin.ignore();

		cout << " [ SHOW DATAS PARENT (Angkutan) - search by child (Daerah)]" << endl;
		cout << "> Nama Daerah: "; getline(cin, daerah);

		addrChild srcChild = findElm(LC, daerah);
		if (srcChild == NULL)
		{
			cout << endl << "[-] Datas not found.." << endl;
		} else if (LR.first != NULL) {
			addrRel P = LR.first;
			while (P->next != LR.first) {
				if (P->child == srcChild)
				{
					cout << "-> " << (P->parent)->info.kode << " | " << (P->parent)->info.nama << endl;
				}
				P = P->next;
			}

			if (P->child == srcChild)
			{
				cout << "-> " << (P->parent)->info.kode << " | " << (P->parent)->info.nama << endl;
			}
		}
		cin.ignore().get();

	} else if (x == "angkutan") {
		system("clear");
		cin.ignore();

		cout << " [ SHOW DATAS CHILD (Daerah) - search by parent (Angkutan)]" << endl;
		cout << "> Kode Angkutan: "; getline(cin, angkutan.kode);

		addrParent srcParent = findElm(LP, angkutan.kode);
		if (srcParent == NULL)
		{
			cout << endl << "[-] Datas not found.." << endl;
		} else if (LR.first != NULL) {
			addrRel P = LR.first;
			while (P->next != LR.first) {
				if (P->parent == srcParent)
				{
					cout << "-> " << (P->child)->info << endl;
				}
				P = P->next;
			}

			if (P->parent == srcParent)
			{
				cout << "-> " << (P->child)->info << endl;
			}
		}

		cin.ignore().get();
	} else if (x == "minmax") {
		system("clear");
		cin.ignore();

		cout << " [ SHOW THE EASIEST AND MOST DIFFICULT DATAS CHILD (Daerah) ] " << endl;

		addrChild C = LC.first; int max = 0, min = 1, i;
		while (C != NULL) {
			addrRel Q = LR.first; i = 0;
			while (Q->next != LR.first) {
				(Q->child != C) ? : i++;
				Q = Q->next;
			} (Q->child != C) ? : i++;

			if (i > max) max = i;
			if (i != 0 && i < min) min = i;
			C = C->next;
		}

		C = LC.first; string MIN, MAX;
		while (C != NULL) {
			addrRel Q = LR.first; i = 0;
			while (Q->next != LR.first) {
				(Q->child != C) ? : i++;
				Q = Q->next;
			} (Q->child != C) ? : i++;

			if (i == max) MAX = C->info;
			if (i == min) MIN = C->info;

			C = C->next;
		}

		// if (MAX- != MIN->info) cout << "[*] Difficult: " << MAX->info << " | Easiest: " << MIN->info << endl;
		// else cout << "[-] MIN == MAX" << endl;
		if (MIN != MAX)
		{
			cout << "[*] Difficult: " << MAX << " | Easiest: " << MIN << endl;
		}
		cin.ignore().get();
	}
}

void updateDatas(string x, listParent &LP, listChild &LC, listRel &LR) {
	if (x == "angkutan") {
		do {
			system("clear");
			cin.ignore();

			cout << " [ UPDATE DATAS PARENT (Angkutan) ]" << endl << endl;
			cout << "> Plat Nomor: "; getline(cin, angkutan.kode);

			addrParent srcParent = findElm(LP, angkutan.kode);
			if (srcParent != NULL)
			{
				system("clear");
				cout << " [ NEW DATAS ] " << endl << endl;
				cout << "> Plat Nomor: "; getline(cin, srcParent->info.kode);
				cout << "> Nama Angkutan: "; getline(cin, srcParent->info.nama);
			} else cout << endl << "[-] Datas not found.." << endl;

			cout << "[*] Update datas, again? [y/t]: "; cin >> repeat;
		} while (repeat != 't' && repeat != 'T');
	} else if (x == "daerah") {
		do {
			system("clear");
			cin.ignore();

			cout << " [ UPDATE DATAS PARENT (Angkutan) ]" << endl << endl;
			cout << "> Masukkan Nama Daerah: "; getline(cin, daerah);

			addrChild srcChild = findElm(LC, daerah);
			if (srcChild != NULL)
			{
				system("clear");
				cout << " [ NEW DATAS ] " << endl << endl;
				cout << "> Nama Daerah: "; getline(cin, srcChild->info);
			} else cout << endl << "[-] Datas not found.." << endl;

			cout << "[*] Update datas, again? [y/t]: "; cin >> repeat;
		} while (repeat != 't' && repeat != 'T');
	}
}

void deleteDatas(string x, listParent &LP, listChild &LC, listRel &LR) {
	system("clear");
	cin.ignore();
	if (x == "angkutan") {
		cout << "> Plat Nomor: "; getline(cin, angkutan.kode);
		addrParent srcAngkutan = findElm(LP, angkutan.kode);

		if (srcAngkutan != NULL)
		{
			addrRel Q = LR.first;
			if (Q->next == LR.first && (Q->next)->parent == srcAngkutan)
			{
				Q->next = NULL;
				LR.first = NULL;
			} else {
				addrRel P;
				while (Q->next != LR.first && (Q->next)->parent != srcAngkutan) {
					P = Q;
					Q = Q->next;
				}

				if (srcAngkutan == (LR.first)->parent)
				{
					while (P->next != LR.first) {
						P = P->next;
					}

					LR.first = Q->next;
					P->next = LR.first;
					Q->next = NULL;
				} else if (Q->next == LR.first) {
					P->next = LR.first;
					Q->next = NULL;
				} else {
					P->next = Q->next;
					Q->next = NULL;
				}
			}

			deleteParent(LP, srcAngkutan);
		}
	} else if (x == "daerah") {
		cout << "> Daerah: "; getline(cin, daerah);
		addrChild srcDaerah = findElm(LC, daerah);

		if (srcDaerah != NULL)
		{
			addrRel srcRelation = findElmChild(LR, srcDaerah);
			if (srcRelation != NULL)
			{
				cout << "here" << endl;
				cin.ignore().get();
				// deleteRelation
				// deleteChild
			} else {
				// deleteChild
			}
		}
	}
}

void showMenu(string x, listParent &LP, listChild &LC, listRel &LR) {
	if (x == "create") {
		system("clear");
		do {
			system("clear");
			cout << " [ CREATE DATAS ]" << endl;
			cout << endl
			     << " [1] Add datas (Angkutan)" << endl
			     << " [2] Add datas (Daerah)" << endl
			     << " [3] Add new Relation" << endl
			     << " [4] Back to dashboard menu" << endl << endl
			     << " [*] Enter your choice and press <enter>: ";
			cin >> choice;

			switch (choice) {
			case 1:
				addDatas("angkutan", LP, LC, LR);
				break;

			case 2:
				addDatas("daerah", LP, LC, LR);
				break;

			case 3:
				addDatas("relasi", LP, LC, LR);
				break;
			}
		} while (choice != 4);
	} else if (x == "read") {
		system("clear");
		do {
			system("clear");
			cout << " [ SHOW DATAS ]" << endl;
			cout << endl
			     << " [1] Show all datas" << endl
			     << " [2] Show datas (Daerah) - (search by Angkutan)" << endl
			     << " [3] Show datas (Angkutan) - (search by Daerah)" << endl
			     << " [4] Show the easiest and most difficult datas of the transport area." << endl
			     << " [5] Back to dashboard menu" << endl << endl
			     << " [*] Enter your choice and press <enter>: ";
			cin >> choice;

			switch (choice) {
			case 1:
				showDatas("all", LP, LC, LR);
				break;

			case 2:
				showDatas("angkutan", LP, LC, LR);
				break;

			case 3:
				showDatas("daerah", LP, LC, LR);
				break;

			case 4:
				showDatas("minmax", LP, LC, LR);
				break;
			}
		} while (choice != 5);

	} else if (x == "update") {
		system("clear");
		do {
			system("clear");
			cout << " [ UPDATE DATAS ]" << endl;
			cout << endl
			     << " [1] Update angkutan" << endl
			     << " [2] Update daerah" << endl
			     << " [3] Back to dashboard menu" << endl << endl
			     << " [*] Enter your choice and press <enter>: ";
			cin >> choice;

			switch (choice) {
			case 1:
				updateDatas("angkutan", LP, LC, LR);
				break;

			case 2:
				updateDatas("daerah", LP, LC, LR);
				break;
			}
		} while (choice != 3);

	} else if (x == "delete") {
		do {
			system("clear");
			cout << " [ DELETE DATAS ] " << endl;
			cout << endl
			     << " [1] Delete Angkutan" << endl
			     << " [2] Delete Daerah" << endl
			     << " [3] Back to dashboard menu" << endl << endl
			     << " [*] Enter your choice and press <enter>: ";
			cin >> choice;

			switch (choice) {
			case 1:
				deleteDatas("angkutan", LP, LC, LR);
				break;

			case 2:
				deleteDatas("daerah", LP, LC, LR);
				break;
			}
		} while (choice != 3);
	}
}
