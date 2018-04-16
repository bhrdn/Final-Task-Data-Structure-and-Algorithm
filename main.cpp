#include "autoload.cpp"

int main(int argc, char const *argv[])
{
	int choice;
	do
	{
		cout << endl
		     << " 1. Penambahan data alat angkutan." << endl
		     << " 2. Penambahan data daerah." << endl
		     << " 3. Penentuan relasi alat angkutan dan daerah (dan sebalikknya)." << endl
		     << " 4. Menghapus data alat angkutan tertentu." << endl
		     << " 5. Manghapus data daerah tertentu." << endl
		     << " 6. Menampilkan data keseluruhan alat angkutan beserta daerah yang bisa dikujunginya." << endl
		     << " 7. Menampilkan data daerah yang bisa dilaui oleh alat angkutan tertentu." << endl
		     << " 8. Menampilkan data alat angkutan yang bisa mengunjungi suatu daerah tertentu." << endl
		     << " 9. Menampilkan data daerah yang paling mudah dan yang paling sulit sarana transportasinya." << endl
		     << " \nEnter your choice and press return: ";
		cin >> choice;

		switch (choice)
		{
			case 1:
				cout << 1;
				break;

			case 2:
				break;

			case 3:
				break;

			case 4:
				break;

			case 5:
				break;

			case 6:
				break;

			case 7:
				break;

			case 8:
				break;

			case 9:
				break;
			
			default:
				cout << "Not a Valid Choice. " << endl
				     << "Choose again." << endl;
				break;
		}

	} while (choice != 9);
	return 0;
}