#include "autoload.cpp"

int main(int argc, char const *argv[])
{

	// nambahi conto tok

	// do
	// {
	// 	showMenu();
	// 	switch (choice)
	// 	{
	// 		case 1:
	// 			showMenu('create');
	// 			break;

	// 		case 2:
	// 			showMenu('read');
	// 			break;

	// 		case 3:
	// 			showMenu('update');
	// 			break;

	// 		case 4:
	// 			showMenu('delete');
	// 			break;

	// 		case 5:
	// 			break;
			
	// 		default:
	// 			cout << "[x] Empty menu.." << endl;
	// 			break;
	// 	}
	// } while (choice != 5);

	listChild LC;
	addrChild AC;

	createList(LC);
	AC = alokasi("Daerah A");
	insertFirst(LC, AC);
	
	printInfo(LC);
	return 0;
}
