#include "pch.h"
#include <iostream>

int DFS(int i, int j, int nSum);
int MaxSearchDFS(int i, int j);
int MaxCheck();
int InitArr();

#define W 0
#define L 1

static bool arrTreasureIsland_Map[50][50];

// 방문 완료 배열 확인.
static bool arrCheckIndex[50][50];

// 이동 비용 확인 배열
static int arrMoveCost[50][50] = { 1000000000, };

// 행
static int arrDirectionX[] = { 0, 1, 0, - 1 };

// 열
static int arrDirectionY[] = { 1, 0, -1, 0 };

int x = 0, y = 0;

int MAX = 0;

using namespace std;


int main()
{
	std::cout << "Hello World!\n";

	cin >> x >> y;

	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			char chInput;
			cin >> chInput;

			if (chInput == 'W' || chInput == 'w')
			{
				arrTreasureIsland_Map[i][j] = 0;
			}
			else if (chInput == 'L' || chInput == 'l')
			{
				arrTreasureIsland_Map[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			arrCheckIndex[i][j] = true;
			DFS(i, j, 0);
			arrCheckIndex[i][j] = false;

			arrCheckIndex[i][j] = true;
			MaxSearchDFS(i, j);
			arrCheckIndex[i][j] = false;

			InitArr();
		}
	}
	cout << endl;
	cout << MAX << endl;
}

int DFS(int i, int j, int nSum)
{
	if (!arrTreasureIsland_Map[i][j])
	{
		return false;
	}

	if (arrMoveCost[i][j] > nSum)
	{
		arrMoveCost[i][j] = nSum;
	}

	else if (arrMoveCost[i][j] < nSum)
	{
		return false;
	}

	nSum++;

	for (int k = 0; k < 4; k++)
	{
		int Dx = i;
		int Dy = j;

		Dx = Dx + arrDirectionX[k];
		Dy = Dy + arrDirectionY[k];

		if (Dx < x && Dy < y)
		{
			if (arrCheckIndex[Dx][Dy] == false)
			{
				arrCheckIndex[Dx][Dy] = true;
				DFS(Dx, Dy, nSum);
				arrCheckIndex[Dx][Dy] = false;
			}
		}
	}

	return true;
}

int MaxSearchDFS(int i, int j)
{
	if (!arrTreasureIsland_Map[i][j])
	{
		return false;
	}

	for (int k = 0; k < 4; k++)
	{
		int Dx = i;
		int Dy = j;

		Dx = Dx + arrDirectionX[k];
		Dy = Dy + arrDirectionY[k];

		if (Dx < x && Dy < y)
		{
			if (arrCheckIndex[Dx][Dy] == false)
			{
				arrCheckIndex[Dx][Dy] = true;
				MaxSearchDFS(Dx, Dy);
				arrCheckIndex[Dx][Dy] = false;
			}
		}
	}

	if (MAX < arrMoveCost[i][j])
	{
		MAX = arrMoveCost[i][j];
	}

	return true;
}


//int MaxCheck()
//{
//	for (int i = 0; i  < x; i++)
//	{
//		for (int j = 0; j < y; j++)
//		{
//			if (arrMoveCost[i][j] > MAX &&  arrMoveCost[i][j] < 1000000000)
//			{
//				MAX = arrMoveCost[i][j];
//			}
//		}
//	}
//
//	return 0;
//}

int InitArr()
{
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			arrMoveCost[i][j] = 1000000000;
		}
	}
	
	return 0;
}