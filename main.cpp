#include "autoload.cpp"

int main(int argc, char const *argv[])
{
	// List Parent & Child
	listParent daftarAngkutan;
	createList(daftarAngkutan);
	listChild daftarDaerah;
	createList(daftarDaerah);
	
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

		switch (choice)
		{
		case 1:
			showMenu("create", daftarAngkutan, daftarDaerah);
			break;

		case 2:
			showMenu("read", daftarAngkutan, daftarDaerah);
			break;

		case 3:
			showMenu("update", daftarAngkutan, daftarDaerah);
			break;

		case 4:
			showMenu("delete", daftarAngkutan, daftarDaerah);
			break;
		}
	} while (choice != 5);

	return 0;
}