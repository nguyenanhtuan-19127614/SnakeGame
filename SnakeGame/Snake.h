#pragma once
#ifndef Snake.h
#define Snake_H
#include <iostream>
#include <vector>
#include<windows.h>
#include <conio.h>
#include <stdlib.h>     
#include <time.h>

using namespace std;
#define height 30
#define width 30
struct Point
{
	int x, y;
	
};
inline
bool operator==(const Point& x, const Point& y) {
	if (x.x == y.x and x.y == y.y)
	{
		return true;
	}
	return false;
}
void gotoxy(int x, int y);
void DrawBoard();

class Snake
{
protected:
	vector<Point> body;
public:
	Snake();
	Point GetHead()
	{
		return body[0];
	}
	int GetSize()
	{
		return body.size();
	}
	void DrawSnake();
	void Grow();
	void Move(char direction);
	bool SelfBite();
};

class Food
{
protected:
	Point body;
public:
	Food();
	Point GetPoint()
	{
		return body;
	}
	void drawFood();
	void CreateNewFoode();
};

class Board
{
protected:
	Snake player;
	Food foods;
	bool result;
public:
	Board() 
	{ 	
		result = true;
		DrawBoard();
		foods.drawFood();
		player.DrawSnake();
	};

	void rule()
	{
		if (player.GetHead() == foods.GetPoint())
		{
			player.Grow();
			foods.CreateNewFoode();
		}
		
		if (player.GetHead().x == width or player.GetHead().x == 0 
			or player.GetHead().y == height or player.GetHead().y==0)
		{
			result = false;
		}

		if (player.SelfBite() == false)
		{
			result = false;
		}
	}

	void Start()
	{
		
		char button = 's';
		while (true)
		{
			
			if (_kbhit())
			{
				button = _getch();
				if (int(button) == 27)
				{
					break;
				}
			}

			rule();
			if (result == false)
				break;

			DrawBoard();
			foods.drawFood();
			player.Move(button);
			player.DrawSnake();
			Sleep(500);
			system("cls");
		}
	}
};

#endif // !Snake.h
