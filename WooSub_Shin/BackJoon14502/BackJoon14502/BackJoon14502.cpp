// BackJoon14502.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include "algorithm"
#include "queue"
#include <iostream>

//using namespace std;

int SetVirus();
void SetWall(int x, int y, int nWallCnt);

int arrMap[8][8] = { 0, };

int	mx, my;
int nSafeMax = 0;

// 우, 하, 좌, 상 시계방향
int arrDirX[4] = {0, 1, 0, -1};
int arrDirY[4] = {1, 0, -1, 0};

std::queue<std::pair<int, int>> nQueue;

int main()
{
	std::cin >> mx >> my;

	for (int i = 0; i < mx; i++)
	{
		for (int j = 0; j < my; j++)
		{
			std::cin >> arrMap[i][j];
		}
	}

	SetWall(0, 0, 0);

	std::cout << nSafeMax << std::endl;

    return 0;
}

void SetWall(int x, int y, int nWallCnt)
{
	// 벽이 3개 세워졌으면 바이러스퍼트리고 루프 탈출
	if (nWallCnt == 3)
	{
		int nResultMax = SetVirus();
		if (nResultMax >= nSafeMax)
		{
			nSafeMax = nResultMax;
		}

		return;
	}


	for (int i = 0; i < mx; i++)
	{
		for (int j = 0; j < my; j++)
		{
			if (arrMap[i][j] == 0)
			{
				arrMap[i][j] = 1;
				SetWall(i,j, nWallCnt + 1);
				arrMap[i][j] = 0;
			}
		}
	}

	return;
} 

int SetVirus()
{
	int arrTempMap[8][8] = { 0, };

	std::copy(&arrMap[0][0], &arrMap[0][0] + 8 * 8, &arrTempMap[0][0]);

	//std::cout << "바이러스 유포 전";
	//for (int a = 0; a < mx; a++)
	//{
	//	std::cout << std::endl;
	//	for (int b = 0; b < my; b++)
	//	{
	//		std::cout << arrMap[a][b];
	//	}
	//}
	//int dd = 0;
	



	int nMax = 0;

	for (int i = 0; i < mx; i++)
	{
		for (int j = 0; j < my; j++)
		{ 
			if (arrTempMap[i][j] == 2)
			{ 

				// 바이러스의 위치를 찾았다면
				// BFS로 바이러스 퍼뜨리기
				nQueue.push(std::make_pair(i, j));
				
				while (!nQueue.empty())
				{
					auto autoQueue = nQueue.front(); //= nQueue.front
					nQueue.pop();
					int nFrontX = autoQueue.first;
					int nFrontY = autoQueue.second;

					for (int AdjLoop = 0; AdjLoop < 4; AdjLoop++)
					{
						int nAdjX = nFrontX + arrDirX[AdjLoop];
						int nAdjY = nFrontY + arrDirY[AdjLoop];

						if (nAdjX < 0 || nAdjY < 0 || nAdjX >= mx || nAdjY >= my) continue;

						if (arrTempMap[nAdjX][nAdjY] == 0)
						{
							nQueue.push(std::make_pair(nAdjX, nAdjY));
							arrTempMap[nAdjX][nAdjY] = 2;

							//std::cout << std::endl;
							//for (int a = 0; a < mx; a++)
							//{
							//	std::cout << std::endl;
							//	for (int b = 0; b < my; b++)
							//	{
							//		std::cout << arrTempMap[a][b];
							//	}
							//}
						}
					}
					
				}
				// 큐에 이제 쌓인게 없다면 바이러스 최대 범위까지 확장 끝
			}
		}
	}

	//std::cout << std::endl;
	//std::cout << "바이러스 유포 후";

	for (int nIterX = 0; nIterX < mx; nIterX++)
	{
		//std::cout << std::endl;
		for (int nIterY = 0; nIterY < my; nIterY++)
		{
			if (arrTempMap[nIterX][nIterY] == 0)
			{
				nMax++;
			}
			//std::cout << arrTempMap[nIterX][nIterY];
		}
	}

	

	return nMax;
}