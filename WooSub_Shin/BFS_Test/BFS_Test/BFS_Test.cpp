// BFS_Test.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include "algorithm"
#include "queue"

std::queue<std::pair<int, int>> nQueue;
int x, y;
int arrMap[100][100] = { 0, };
bool arrVisitCheck[100][100] = { 0, };

// 우, 우하, 하, 좌하, 좌, 좌상, 상, 우상
int arrDirX[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int arrDirY[8] = {1, 1, 0, -1, -1, -1, 0, 1};

void BFS(int nStartX, int nStartY);

int main()
{
    std::cout << "BFS TEST" << std::endl; 

	std::cin >> x >> y;

	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < x; j++)
		{
			std::cin >> arrMap[i][j];
		}
	}

	// 입력값 확인
	for (int i = 0; i < x; i++)
	{
		std::cout << std::endl;
		for (int j = 0; j < x; j++)
		{
			std::cout << arrMap[i][j];
		}
	}

	// 시작위치 임의로 2, 2
	BFS(2, 2);

	std::cout << std::endl;
	std::cout << "BFS TEST END" << std::endl;
}

void BFS(int nStartX, int nStartY)
{
	//  시작지점 스택에 쌓기
	nQueue.push(std::make_pair(nStartX, nStartY));
	arrVisitCheck[nStartX][nStartY] = 1;

	while (!nQueue.empty())
	{
		// 시작지점을 기준으로
		auto FrontResult = nQueue.front();
		nQueue.pop();
		int nX = FrontResult.first;
		int nY = FrontResult.second;

		// 인근 노드 8개를 큐에 삽입
		for (int nDirNum = 0; nDirNum < 8; nDirNum++)
		{
			int nAdjX = nX + arrDirX[nDirNum];
			int nAdjY = nY + arrDirY[nDirNum];

			// 배열 영역 벗어난 곳 탐색 못하게 범위지정
			if (nAdjX < 0 || nAdjY < 0 || nAdjX >= x || nAdjY >= y) continue;
			// 스택에 한번 쌓인 놈은 다시 스택에 못넣게
			if (arrVisitCheck[nAdjX][nAdjY] == 1) continue;
			// 스택에 한번 쌓았던 놈들은 방문 체크
			arrVisitCheck[nAdjX][nAdjY] = 1;
			nQueue.push(std::make_pair(nAdjX, nAdjY));
		}
	
		// 탐색 순서를 보기위해서
		arrMap[nX][nY] = 1;
		
		// 탐색 순서 보기위한 for문
		std::cout << std::endl;
		for (int i = 0; i < x; i++)
		{
			std::cout << std::endl;
			for (int j = 0; j < y; j++)
			{
				std::cout << arrMap[i][j];
			}
		}
		// 더미코드
		int n = 0;
	}
	// 더미코드
	int n = 0;
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
