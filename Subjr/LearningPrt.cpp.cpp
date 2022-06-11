#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>

using namespace std;
 


class Jorney {
private:
	string city;
	int days;
	float wallet;

public:
	void TurAgents(void);
	void Instruction(void);
	void CopyAdd(bool isFrom);
};

void Jorney::TurAgents(void)
{
	Jorney pc;
	int  choice=0;
	ofstream fout;
	fout.open("text.txt",ofstream::app);		

	ifstream line;
	line.open("text.txt");

	if (!fout.is_open()) {
		cout << "Field open file";
	}

	do{
	cout << "Enter city in want to fly to : ";
	cin >> city;
	cout << "Enter period days: ";
	cin >> days;
	cout << "Enter your balance now :";
	cin >> wallet;

		if (city == "Derbent") {

			fout << "Your balance now : " << wallet;

			if (days > 6) {
				cout << "\nYou have discount,celebrate !!! \n";
				wallet = (days * 1200 / 2);
			
			}
			else {
				days *= 1200;

			}
		}

		else if (city == "Moscow") {
			if (days > 6) {
				cout << "\nYou have discount,celebrate !!! ";
				wallet = days * 1600 / 2;
			}
			else {

				wallet = days * 1600;
			}
		}

		else if (city == "Monako") {

			if (days > 6) {
				cout << "\nYou have discount,celebrate !!! \n";
				wallet = days * 2500 / 2;
			}
			else {
				wallet = days * 2500;

			}
		}
		else if (wallet == 0) {
			cout << "You have not moneyy in your wallet !!! \n";
		}
		
		fout << "\nYour balance end : " << wallet - days << "  " << "\nQuantity days in other city : " << days ;
		cout << "\n\nYour balance end : " << wallet - days << "  " << "\nQuantity days in other city : " << days;

		cin >> choice;
	} while (choice == 1);
		
	fout.close();
	line.close();
}


void Jorney::CopyAdd(bool isFrom)
{
	if (isFrom) {
		Instruction();
	}
	else {
		TurAgents();
	}
}

void Jorney::Instruction(void)
{
	cout << "1)User might buy ticket in other city on two or three \n";
	cout << "2)Also might buy ticket and in advance\n";
	cout << "3)When buying ticket on seven days,user receives discount %50\n";
}

int main(void)
{

	Jorney pc;
	do {

		switch (_getch()) {
		case '1': bool unt;
			cout << " : ";
			cin >> unt;
			pc.CopyAdd(unt);
			break;
		}

	} while (_getch() != 'e');
	
}
