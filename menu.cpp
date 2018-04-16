#include "init.h"

void showMenu(string option) {
	int choice; char repeat;

	if (option == "create")
	{
		system("clear");
		do
		{
			system("clear");
			cout << "=== CREATE DATAS ===" << endl;
			cout << endl
			     << " 1. Add angkutan" << endl
			     << " 2. Add daerah" << endl
			     << " 3. Add relasi"
			     << " 4. Back to dashboard menu" << endl
			     << "\n[*] Enter your choice and press <enter>: ";
			cin >> choice;

			switch (choice)
			{
			case 1:
				do {
					system("clear");
					cout << "> Plat Nomor: " << endl;
					cout << "> Nama Angkutan: " << endl;

					// TODO FOR ADD (ANGKUTAN)
					// 1. insertParent
					
					cout << "[*] Add datas, again? [y/t]: "; cin >> repeat;
				} while (repeat != 't');

				break;

			case 2:
				do {
					system("clear");
					string daerah;
					cout << "> Nama Daerah: "; cin >> daerah; cout << endl;

					// TODO FOR ADD (DAERAH)
					// 1. insertChild

					cout << "[*] Add datas, again? [y/t]: "; cin >> repeat;
				} while (repeat != 't');
				break;

			case 3:
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
				break;
			}
		} while (choice != 4);
	} else if (option == "read")
	{

	} else if (option == "update")
	{

	} else if (option == "delete")
	{

	}
}

void addDatas(string x) {
	// TODO
}

void deleteDatas(string x) {
	// TODO
}

void showDatas(string x) {
	// TODO
}