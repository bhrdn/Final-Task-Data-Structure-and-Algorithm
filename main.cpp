#include "autoload.cpp"

int main(int argc, char const *argv[])
{
<<<<<<< HEAD
	int choice;
	do
	{
		system("clear");
		cout << "=== DATA ALAT TRANSPORT ===" << endl;
		cout << endl
		     << " 1. Create" << endl
		     << " 2. Read" << endl
		     << " 3. Update" << endl
		     << " 4. Delete" << endl
		     << " 5. Exit" << endl
		     << "\n[*] Enter your choice and press <enter>: ";
		cin >> choice;
=======

	// nambahi conto tok

	// do
	// {
	// 	showMenu();
	// 	switch (choice)
	// 	{
	// 		case 1:
	// 			showMenu('create');
	// 			break;
>>>>>>> 4820485d6c8b44906211a1cd39b91926e4861aae

		switch (choice)
		{
		case 1:
			showMenu("create");
			break;

		case 2:
			showMenu("read");
			break;

		case 3:
			showMenu("update");
			break;

		case 4:
			showMenu("delete");
			break;

		case 5:
			break;

<<<<<<< HEAD
		default:
			cout << "[x] Empty menu.." << endl;
			break;
		}
	} while (choice != 5);
=======
	createList(LC);
	AC = alokasi("Daerah A");
	insertFirst(LC, AC);
	
	printInfo(LC);
>>>>>>> 4820485d6c8b44906211a1cd39b91926e4861aae
	return 0;
}
