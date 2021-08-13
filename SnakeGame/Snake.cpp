#include"Snake.h"
void gotoxy(int x, int y)
{
	static HANDLE h = NULL;
	if (!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x, y };
	SetConsoleCursorPosition(h, c);
}

void DrawBoard()
{
	gotoxy(0, 0);
	for (int i = 0; i < width; i++)
	{
		cout << '-';
	}
	for (int i = 0; i < height; i++)
	{
		gotoxy(0, i);
		cout << '|';
	}
	gotoxy(0, height);
	for (int i = 0; i < width; i++)
	{
		cout << '-';
	}

	for (int i = 0; i < height; i++)
	{
		gotoxy(width, i);
		cout << '|';
	}
}

Snake::Snake()
{
	body.push_back(Point{ width/2,height/2 });
	body.push_back(Point{ width/2,height/2-1 });
	body.push_back(Point{ width/2,height/2-2 });
}

void Snake::DrawSnake()
{
	for (int i = 0; i < body.size(); i++)
	{
		gotoxy(body[i].x, body[i].y);
		if (i == 0)
		{
			cout << '@';
		}
		else
			cout << '*';
	}
}

void Snake::Move(char direction)
{
	for (int i = body.size()-1; i > 0; i--)
	{
		body[i] = body[i - 1];
	}
	if (direction == 'w')
	{
		body[0].y -= 1;
	}
	else if (direction == 's')
	{
		body[0].y += 1;
	}
	else if (direction == 'a')
	{
		body[0].x -= 1;
	}
	else if (direction == 'd')
	{
		body[0].x += 1;
	}
}

void Snake::Grow()
{
	Point tail = body.back();
	tail.x -= 1;
	body.push_back(tail);
}

bool Snake::SelfBite()
{
	for (int i = 1; i < body.size() - 1; i++)
	{
		if (body[0] == body[i])
			return false;
	}
	return true;
}

Food::Food()
{
	srand(time(NULL));
	body.x = rand() % width + 1;
	body.y = rand() % height + 1;
}
void Food::CreateNewFoode()
{
	srand(time(NULL));
	body.x = rand() % (width-1) + 1;
	body.y = rand() % (height-1) + 1;
}

void Food::drawFood()
{
	gotoxy(body.x,body.y);
	cout << 'O';
}

void Menu()
{
	int choice;
	do
	{
		DrawBoard();
		gotoxy(width / 3, 1);
		cout << "SNAKE GAME";
		gotoxy(width / 3, 2);
		cout << "PlayGame:<1>";
		gotoxy(width / 3, 3);
		cout << "TUTORIAL<2>";
		gotoxy(width / 3, 4);
		cout << "Quit:<0>";
		gotoxy(width / 4, 5);
		cout << "Your Choice: ";
		cin >> choice;
		if (choice == 2)
		{

			system("cls");
			DrawBoard();
			gotoxy(7, 4);
			cout << "|W- UP|-|S-DOWN|";
			gotoxy(6.5, 5);
			cout << "|A-LEFT|-|D-RIGHT|";
			gotoxy(3, 6);
			cout << "**Please turn of UNIKEY** ";
			gotoxy(0, 7);
			system("pause");
		}
		if (choice == 1)
		{
			int choice2;
			do
			{
				system("cls");
				Board game;
				game.Start();
				DrawBoard();
				gotoxy(width / 3, 1);
				cout << "GAME OVER ";
				gotoxy(width / 3.5, 2);
				cout << "PlayAgain:<1> ";
				gotoxy(width / 3.5, 3);
				cout << "Quit:<0> ";
				gotoxy(width / 4, 4);
				cout << "Your Choice: ";
				cin >> choice2;
			} while (choice2 == 1);
		}
		system("cls");
	} while (choice != 0);
}
