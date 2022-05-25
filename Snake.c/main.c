bool gameOver ;
bool hit=false;
int x, y, score = 0;
const int width = 40, height = 20;
int tailX[200], tailY[200];
int ntail = 3;
int fruitX, fruitY;

typedef enum{STOP=0,UP,DOWN,LEFT,RIGHT} Direction ;
Direction Dir;


void setup(void)
{
	Dir = STOP;
	x = width / 2;
	y = height / 2;
	fruitX = rand() % width;
	fruitY = rand() % height;
	score = 0;
}

void draw(void)
{
	int i, j, k;
	system("cls");
	printf("Score = %d \n\n", score);
	
	for (i = 0; i < width; i++)
	{
		printf("=");
	}
	printf("\n");

	for (j = 0; j < height; j++)
	{
		for (k = 0; k < width; k++)
		{
			if (k == 0 || k == width - 1)
			{
				printf("!");
			}
			if (j == y && k == x)
			{
				printf("*");
			}
			else if (j == fruitY && k == fruitX) {
				printf("#");
			}
			else {
				int d;
				bool print = false;
				for (d = 0; d < ntail; d++) {
					if (tailX[d] == k && tailY[d] == j) {
						printf("*");
						print = true;
					}
				}

				if (!print)	{
					printf(" ");
				}
			}
		}
		printf("\n");
	}

	for (int u = 0; u < width+1; u++) {
		printf("=");
	}
}

void input(void)
{
	if (_kbhit())
	{
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
	else if (!hit){
		x++;
	}
}

void logic(void)
{
	int lastX = tailX[0];
	int lastY = tailY[0];
	int last2X, last2Y;
	tailX[0] = x;
	tailY[0] = y;

	int i = 0; 
	
	for (i = 0; i < ntail; i++)
	{
		last2X = tailX[i];
		last2Y = tailY[i];
		tailX[i] = lastX;
		tailY[i] =  lastY;
		lastX = last2X;
		lastY = last2Y;
	}

	switch (Dir){
	case UP:y--;
		break;

	case DOWN:y++;
		break;

	case LEFT:x--;
		break;
		
	case RIGHT:x++;
		break;

	}
	if (x < 0 || width < x || y < 0 || y > height)
	{
		gameOver = true;
		printf("GOOD BYE LOOSER ");
	}
	if (x == fruitX && y == fruitY) {
		ntail++;
		score = +10;
		fruitX = rand() % width;
		fruitY = rand() % height;
	}
}




int main(void)
{
	setup();
	draw();

	while (!gameOver)
	{
		draw();
		input();
		logic();
	}
}
