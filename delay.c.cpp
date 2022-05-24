#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996) .

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

void Board();
int Check(void);
int  pointGame();
void menu(void);
void View(void);

char numbers[12] = { '1','2','3','4','5','6','7','8','9' };
char symbolX, symbolO;
char player_X1[22], player_O2[22];


int main(void)
{
	system("color 3");
	menu();
	FILE* fp;
	fp = fopen("openly.txt", "a+");

	char answerd;
	char symbol;
	char score=1;
	int choice;
	int player = 1;
semilar:

	printf("\n\n\tEnter  :  ");
	scanf("%c", &answerd);;
	if (answerd == 'S')
	{
		printf("\n\tEnter name player1 : ");
		scanf("%s", player_X1);
		printf("\n\tEnter name player2 : ");
		scanf("%s", player_O2);
		fprintf(fp, "%s   \n %s", player_X1, player_O2);
		if (strcmp(player_O2, player_X1) == 0)
		{
			printf("\n\tName simelar !!! ");
			goto semilar;
		}
		else {
			pointGame();
			system("color fc");
			Board();

			do {

				player = ((player % 2) ? 1 : 2);
				if (player == 1)
					printf("\n\tEnter from 1 - 9  ", player_X1);
				else
					printf("\n\t Enter from 1 - 9 ", player_O2);
				scanf("%d", &choice);

				symbol = ((player == 1) ? symbolX : symbolO);
				printf("\n\tEnter from 1 - 9 ", player_O2);

				if (choice == 1 && numbers[0] == '1')
					numbers[0] = symbol;
				else if (choice == 2 && numbers[1] == '2')
					numbers[1] = symbol;
				else if (choice == 3 && numbers[2] == '3')
					numbers[2] = symbol;
				else if (choice == 4 && numbers[3] == '4')
					numbers[3] = symbol;
				else if (choice == 5 && numbers[4] == '5')
					numbers[4] = symbol;
				else if (choice == 6 && numbers[5] == '6')
					numbers[5] = symbol;
				else if (choice == 7 && numbers[6] == '7')
					numbers[6] = symbol;
				else if (choice == 8 && numbers[7] == '8')
					numbers[7] = symbol;
				else if (choice == 9 && numbers[8] == '9')
					numbers[8] = symbol;
				else
				{
					printf("\n\t Wrong !! !");
					player--;
				}
				score = Check();
				player++;
				Board();
			} while (score == -1);

			if (score == 1)
			{
				if (player == 2)
				{
					printf("\n Wins %s ", player_X1);
					fprintf(fp, "Winner %s  Count = %d\n", player_X1, player);
				}
				else {
					printf("\nWins %s ", player_O2);
					fprintf(fp, "Winner %s  Count = %d\n", player_O2, player);
				}
			}
		}
	}
	else if (answerd == 'L')
	{
		fprintf(fp, "%s", player_X1);
		printf(" %s  ", player_O2, player);
	}
}

void menu(void)
{
	printf("\n\t\t :::::: Tic Tac Toe Game ::::::: \n");
	printf("\n\t1.For start Game,enter 'S'  ");
	printf("\n\t2.List winner,enter 'L' ");
	printf("\n\t2.Name of player wins ");
	printf("\n\t3.Exit ");
}

void Board()
{
	system("cls");
		printf("\n %s (%c) -  %s  (%c) - \n\n\n", player_X1, symbolX, player_O2, symbolO);

		printf(" %c |  %c  |  %c\n", numbers[0], numbers[1], numbers[2]);
		printf("   |     |    \n");
		printf("---|-----|----\n");
		printf(" %c |  %c  |  %c\n", numbers[3], numbers[4], numbers[5]);
		printf("   |     |    \n");
		printf("---|-----|----\n");
		printf(" %c |  %c  |  %c\n", numbers[6], numbers[7], numbers[8]);
		printf("   |     |    \n");
		printf("---|-----|----\n");
}

int Check(void)
{
	if (numbers[0] == numbers[1] && numbers[1] == numbers[2])
		return 1;
	else if (numbers[3] == numbers[4] && numbers[4] == numbers[5])
		return 1;
	else if (numbers[6] == numbers[7] && numbers[7] == numbers[8])
		return 1;
	else if (numbers[0] == numbers[3] && numbers[3] == numbers[6])
		return 1;
	else if (numbers[1] == numbers[4] && numbers[4] == numbers[7])
		return 1;
	else if (numbers[2] == numbers[5] && numbers[5] == numbers[8])
		return 1;
	else if (numbers[0] == numbers[4] && numbers[4] == numbers[8])
		return 1;
	else if (numbers[2] == numbers[4] && numbers[4] == numbers[6])
		return 1;
	else if (numbers[0] != '1' && numbers[1] != '2' && numbers[2] != '3' && numbers[3] != '4' && numbers[4] != '5' && numbers[5] != '6' && numbers[6] != '7' && numbers[7] != '8' && numbers[8] != '9')
		return 0;
	else
		return -1;
}

int pointGame()
{
	char man;
repeat:
	printf(" %s Enter (X/O) :  ", player_X1);
	man = getchar();
	scanf("%c", &man);

	if (man == 'X')
	{
		symbolX = 'X';
		symbolO = 'o';
	}
	else if (man == 'O')
	{
		symbolX = 'O';
		symbolO = 'X';
	}
	else {
		printf("\n\t Wrong !!! ");
		goto repeat;
	}
	return 1;
}

