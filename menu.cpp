#include "menu.h"

void addDatas(string x, listParent &LP, listChild &LC, listRel &LR) {
	if (x == "angkutan")
	{
		do {
			system("clear");
			cin.ignore();
			cout << "> Plat Nomor: "; getline(cin, angkutan.kode);
			cout << "> Nama Angkutan: "; getline(cin, angkutan.nama);
			cout << endl;

			addrParent P = allocate(angkutan);
			insertFirst(LP, P);

			cout << "[*] Add datas, again? [y/t]: "; cin >> repeat;
		} while (repeat != 't');
	} else if (x == "daerah") {
		do {
			system("clear");
			cin.ignore();
			cout << "> Nama Daerah: "; getline(cin, daerah);
			cout << endl;

			addrChild P = allocate(daerah);
			insertLast(LC, P);

			cout << "[*] Add datas, again? [y/t]: "; cin >> repeat;
		} while (repeat != 't');
	} else if (x == "relasi") {
		do {
			system("clear");
			printInfo(LP);
			cout << "============================" << endl;
			printInfo(LC);
			cout << "============================" << endl;

			cin.ignore();
			cout << "> Kode Angkutan: "; getline(cin, angkutan.kode);
			cout << "> Nama Daerah: "; getline(cin, daerah);

			addrParent srcParent = findElm(LP, angkutan.kode);
			addrChild srcChild = findElm(LC, daerah);

			if (srcParent != NULL && srcChild != NULL)
			{
				addrRel datas = allocate(srcParent, srcChild);
				insertLast(LR, datas);
				printInfo(LR);
			} else
			{
				cout << "[*] Empty datas.." << endl;
			}

			cout << "[*] Add datas, again? [y/t]: "; cin >> repeat;
		} while (repeat != 't');
	}
}

void showDatas(string x, listParent &LP, listChild &LC, listRel &LR) {
	if (x == "all") {
		system("clear");

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
		cout << "> Nama Daerah: "; getline(cin, daerah);

		if (findElm(LC, daerah) == NULL)
		{
			cout << "[*] Empty datas.." << endl;
		} else {
			addrRel P = LR.first;
			if (P->next == LR.first) {
				cout << "-> " << (P->parent)->info.kode << " | " << (P->parent)->info.nama << endl;
			} else {
				while (P != LR.first) {
					if ((P->child)->info == daerah)
					{
						cout << "-> " << (P->parent)->info.kode << " " << (P->parent)->info.nama << endl;
					}
					P = P->next;
				}
			}
		}
		cin.ignore().get();

	} else if (x == "angkutan") {
		system("clear");

		cin.ignore();
		cout << "> Kode Angkutan: "; getline(cin, angkutan.kode);
		if (findElm(LP, angkutan.kode) == NULL)
		{
			cout << "[*] Empty datas.." << endl;
		} else {
			addrRel P = LR.first;
			if (P->next == LR.first) {
				cout << "-> " << (P->child)->info << endl;
			} else {
				while (P != LR.first) {
					if ((P->parent)->info.kode == angkutan.kode)
					{
						cout << "-> " << (P->child)->info << endl;
					}
					P = P->next;
				}
			}
		}

		cin.ignore().get();

	} else if (x == "sorting") {
		system("clear");
		cin.ignore();

		addrChild C = LC.first;
		while (C != NULL) {
			cout << C->info << " => " << totalChild(LR, C) << endl;
			// push x[index].child <- C
			// push x[index].total <- totalChild(LR, C)
			C = C->next;
		}

		// print sort(x, 'ASC')[0].child->info || sort(x, 'DESC')[0].child->info
		cin.ignore().get();
	}
}

void updateDatas(string x, listParent &LP, listChild &LC, listRel &LR) {
	if (x == "angkutan") {
		do {
			system("clear");
			cin.ignore();
			cout << "> Plat Nomor: "; getline(cin, angkutan.kode);
			cout << endl;

			addrParent srcParent = findElm(LP, angkutan.kode);

			if (srcParent != NULL)
			{
				system("clear");
				cout << "> Plat Nomor: "; getline(cin, srcParent->info.kode);
				cout << "> Nama Angkutan: "; getline(cin, srcParent->info.nama);

				printInfo(LP);
			}

			cout << "[*] Update datas, again? [y/t]: "; cin >> repeat;
		} while (repeat != 't');
	} else if (x == "daerah") {
		do {
			system("clear");
			cin.ignore();
			cout << "> Masukkan Nama Daerah: "; getline(cin, daerah);
			cout << endl;

			addrChild srcChild = findElm(LC, daerah);

			if (srcChild != NULL)
			{
				system("clear");
				cout << "> Nama Daerah: "; getline(cin, srcChild->info);

				printInfo(LC);
			}

			cout << "[*] Update datas, again? [y/t]: "; cin >> repeat;
		} while (repeat != 't');
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
			addrRel srcRelation = findElmParent(LR, srcAngkutan);
			if (srcRelation != NULL)
			{
				cout << "here" << endl;
				cin.ignore().get();
				// deleteRelation
				// deleteParent
			} else {
				// deleteParent
			}
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
			cout << "=== CREATE DATAS ===" << endl;
			cout << endl
			     << " 1. Add angkutan" << endl
			     << " 2. Add daerah" << endl
			     << " 3. Add relasi" << endl
			     << " 4. Back to dashboard menu" << endl
			     << "\n[*] Enter your choice and press <enter>: ";
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
			cout << "=== READ DATAS ===" << endl;
			cout << endl
			     << " 1. Tampilkan semua data" << endl
			     << " 2. Tampilkan data daerah (search by angkutan)" << endl
			     << " 3. Tampilkan data angkutan (search by daerah)" << endl
			     << " 4. Tampilkan daerah yang paling banyak angkutan (DESC)" << endl
			     << " 5. Back to dashboard menu" << endl
			     << "\n[*] Enter your choice and press <enter>: ";
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
				showDatas("sorting", LP, LC, LR);
				break;
			}
		} while (choice != 5);

	} else if (x == "update") {
		system("clear");
		do {
			system("clear");
			cout << "=== UPDATE DATAS ===" << endl;
			cout << endl
			     << " 1. Update angkutan" << endl
			     << " 2. Update daerah" << endl
			     << " 3. Back to dashboard menu" << endl
			     << "\n[*] Enter your choice and press <enter>: ";
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
			cout << "=== DELETE DATAS ===" << endl;
			cout << endl
			     << " 1. Delete angkutan" << endl
			     << " 2. Delete daerah" << endl
			     << " 3. Back to dashboard menu" << endl
			     << "\n[*] Enter your choice and press <enter>: ";
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
