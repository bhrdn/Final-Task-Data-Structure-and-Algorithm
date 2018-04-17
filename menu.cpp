#include "menu.h"

void addDatas(string x) {
	// List Parent & Child
	listParent daftarAngkutan;
	createList(daftarAngkutan);
	listChild daftarDaerah;
	createList(daftarDaerah);

	if (x == "angkutan")
	{
		infoParent angkutan;

		do {
			system("clear");
			cin.ignore();
			cout << "> Plat Nomor: ";getline(cin, angkutan.kode);
			cout << "> Nama Angkutan: ";getline(cin, angkutan.nama);
			cout << endl;

			addrParent P = alokasi(angkutan);
			insertFirst(daftarAngkutan, P);

			cout << "[*] Add datas, again? [y/t]: "; cin >> repeat;
		} while (repeat != 't');
	} else if (x == "daerah") {

		string daerah;

		do {
			system("clear");
			cin.ignore();
			cout << "> Nama Daerah: "; getline(cin, daerah);
			cout << endl;

			addrChild P = allocate(daerah);
			insertLast(daftarDaerah, P);

			cout << "[*] Add datas, again? [y/t]: "; cin >> repeat;
		} while (repeat != 't');
	} else if (x == "relasi") {
		do {
			system("clear");
			string daerah;
			cout << "> Nama Angkutan: " << endl;
			cout << "> Nama Daerah: " << endl;

			// TODO FOR ADD RELATION
			// 1. findAddr
			// 2. insertRelation

			cout << "[*] Add datas, again? [y/t]: "; cin >> repeat;
		} while (repeat != 't');
	}
}

void showDatas(string x) {
	if (x == "all") {
		// print all
	} else if (x == "daerah") {
		// 1. find angkutan
		// 2, print daerah
	} else if (x == "angkutan") {
		// 1. find daerah
		// 2. print angkutan
	} else if (x == "sorting") {
		// print daerah dengan angkutan terbanyak - sedikit (DESC)
	}
}

void updateDatas(string x) {
	if (x == "angkutan") {

	} else {
		// daerah
	}
}

void deleteDatas(string x) {
	if (x == "angkutan") {
		// 1. find addr parent
		// 2. find addr relasi
		// 3. delete it
	} else {
		// delete child
	}
}

void showMenu(string x) {
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
				addDatas("angkutan");
				break;

			case 2:
				addDatas("daerah");
				break;

			case 3:
				addDatas("relasi");
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
				showDatas("all");
				break;

			case 2:
				showDatas("daerah");
				break;

			case 3:
				showDatas("angkutan");
				break;

			case 4:
				showDatas("sorting");
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
				updateDatas("angkutan");
				break;

			case 2:
				updateDatas("daerah");
				break;
			}
		} while (choice != 3);

	} else if (x == "delete") {
		system("clear");
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
				deleteDatas("angkutan");
				break;

			case 2:
				deleteDatas("daerah");
				break;
			}
		} while (choice != 3);
	}
}
