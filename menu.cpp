#include "init.h"
int choice; char repeat;

void addDatas(string x) {
	if (x == "angkutan")
	{
		do {
			system("clear");
			cout << "> Plat Nomor: " << endl;
			cout << "> Nama Angkutan: " << endl;

			// TODO FOR ADD (ANGKUTAN)
			// 1. insertParent

			cout << "[*] Add datas, again? [y/t]: "; cin >> repeat;
		} while (repeat != 't');
	} else if (x == "daerah") {
		do {
			system("clear");
			string daerah;
			cout << "> Nama Daerah: "; cin >> daerah; cout << endl;

			// TODO FOR ADD (DAERAH)
			// 1. insertChild

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

void showMenu(string option) {
	if (option == "create") {
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
	} else if (option == "read") {
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

	} else if (option == "update") {
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

	} else if (option == "delete") {
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