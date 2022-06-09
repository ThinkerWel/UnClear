using namespace std;

void RecordingInFile(void);
void ViewFile(void);

int main(void)
{


	cout << "\nEnter choice : ";

	switch (_getch()) 
	{
	case '1':RecordingInFile();
		break;

	case '2':
		cout << "1.Output by character\n";
		cout << "2.Output by line\n";
		ViewFile();
		break;
	}
}


void ViewFile(void)
{
	ofstream fp;
	ifstream openFile;
	string nameFp="test.txt";
	
	fp.open(nameFp, ofstream::app);
	openFile.open(nameFp);

	if (!fp.is_open() || !openFile.is_open()) {
		cout << "Failed open file";
	}
	else {
		int choice = 0;
		cout << "Enter : ";
		cin >> choice;
		char ch;

		if (choice == 1) {
			while (openFile.get(ch)) {
				cout << ch;

			}
		}

		else if (choice == 2) {
			while (!openFile.eof()) {
				string str;
				str = "";
				getline(openFile, str);
				cout  << str<<" ";
			}
		}

	}
	openFile.close();
	fp.close();
}

void RecordingInFile(void)
{
	ofstream record;
	int choice = 0;
	cout << "\n\nEnter : ";
	cin >> choice;

	if (choice == 1) {
		record.open("test.txt");
	}
	else if (choice == 2) {
		record.open("test.txt", ofstream::app);
	}

	string str;
	cout << "\nString : ";
	cin>>str;
	record << str;

	record.close();
}
