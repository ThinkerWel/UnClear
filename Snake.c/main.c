#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996) .

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <conio.h>

void Move(void);
void Cordinate(void);
void Board(void);


typedef enum {STOP=0,UP,DOWN,LEFT,RIGHT} Direction;
Direction Dir;

bool gameOver ;
bool hit = false;
int tailX[200], tailY[200];
int x, y;
int score = 0;
int ntail = 3;
int fruitX, fruitY;
const int width = 50, height = 20;

void setup(void)
{
	gameOver = false;
	x = width / 2;
	y = height / 2;
	fruitX = rand() % 10;
	fruitY = rand() % 10;
	score = 0;

}


void draw() {
	
	system("cls");
	printf("Score:%d", score);
	printf("\n");
	int i;
	for (i = 0; i < width + 1; i++) { 
		printf("=");
	}
	printf("\n");
	int p;
	for (p = 0; p < height; p++) {
		int q;
		for (q = 0; q < width; q++) {
			if (q == 0 || q == width - 1) { 
				printf("!");
			}
			if (p == y && q == x) {
				printf("*");

			}
			else if (p == fruitY && q == fruitX) {
				printf("#");
			}
			else {
				int k = 0;
				bool print = false;
				for (k = 0; k < ntail; k++) {
					if (tailX[k] == q && tailY[k] == p) {
						printf("*");
						print = true;
					}
				}
				if (!print) { printf(" "); }
			}
		}
		printf("\n");
	}

	int j;
	for (j = 0; j < width + 1; j++) {
		printf("=");
	}

}


void Move(void)
{
	if (_kbhit()) {
		switch (_getch()) {
		case 'w':
			Dir = UP;
			hit = true;
			break;

		case 's':
			Dir = DOWN;
			hit = true;
			break;

		case 'a':
			Dir = LEFT;
			hit = true;
			break;

		case 'd':
			Dir = RIGHT;
			hit = true;
			break;

		case 'x':
			gameOver = true;
			break;
		}
	}
	else if (!hit)
	{
		x++;
	}

}

void Cordinate(void)
{
	switch (Dir)
	{
	case UP:y--;
		break;
		
	case DOWN:y++;
		break;
		
	case LEFT:x--;
		break;

	case RIGHT:x++;
		break;
	}
	if (x < 0 || width < x || y < 0 || height < y) {
		gameOver = true;
		system("cls");
	}
	if (x == fruitX && y == fruitY) {
		ntail++;
		score +=10;
		fruitX = rand() % width;
		fruitY = rand() % height;
	}
 }


int main(void) {
	setup();
	draw();
	while (!gameOver) {
		draw();
		Move();
		Cordinate();
	}

}
