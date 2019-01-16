// Tetromino_WooSub.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// Title : 테트로미노
// QuizLink : https://www.acmicpc.net/problem/14500

#include "pch.h"
#include <vector>
#include <iostream>

void solution(int nN, int nM);
int DFS(int nHeight, int nWidth, int nDepth, std::vector< std::vector<int> >& vecInputBoard, std::vector< std::vector<bool> >& vecVisitBoard);

// 검색 시계방향 으로 돌릴거임
static int nArrDirectionX[4] = {1, 0, -1, 0};
static int nArrDirectionY[4] = {0, 1, 0, -1};

int main()
{
	int nN, nM;

	std::cin >> nN;
	std::cin >> nM;
	std::cout << std::endl;

	solution(nN, nM);

}

void solution(int nN, int nM)
{
	// 그냥 벡터 다루는 연습 좀 하려고 배열말고 벡터 씀
	// 2차원 배열 선언 및 초기화
	
	// 입력값이 들어갈 InputBoard
	std::vector< std::vector<int> > vecInputBoard(nM, std::vector<int>(nN));

	// DFS 탐색을 위해서 탐색이 진행된 위치와 탐색이 이루지지 않은 위치를 구별하기 위한 VisitBoard
	std::vector< std::vector<bool> > vecVisitBoard(nM, std::vector<bool>(nN));

	int a = 0;

	for (int nHeight = 0; nHeight < nM; nHeight++)
	{
		for (int nWidth = 0; nWidth < nN; nWidth++)
		{
			// 맨 처음 루트 노드 부터 시작. Vector[0][0]
			vecVisitBoard[nHeight][nWidth] = true;
			int nMax = DFS(nHeight, nWidth, 1, vecInputBoard, vecVisitBoard);
			// 한번 다 돌고 오면 다시 초기화.
			vecVisitBoard[nHeight][nWidth] = false;
		}
	}

}

//DFS
int DFS(int nHeight, int nWidth, int nDepth, std::vector< std::vector<int> >& vecInputBoard, std::vector< std::vector<bool> >& vecVisitBoard)
{
	// 테트로미노 도형 깊이는 4가 끝임
	if (nDepth == 4)
	{
		return vecInputBoard[nHeight][nWidth];
	}

	int nSum = 0;

	for (int i = 0; i < 4; i++)
	{
		// 현 위치에서 -1, +1 등을 해줘서 방향 정하기
		// 암튼 나는 시계방향으로 돌리도록 nArrDirection 배열을 지정했음.
		int nSearchWidth = nWidth + nArrDirectionX[i];
		int nSearchHeight = nHeight + nArrDirectionY[i];

		// 검색할 위치가 Board의 끝라인을 벗어나는지 파악해야함 안그럼 없는 자리 읽어오려고 해서 오류난다.
		if (0 <= nSearchWidth && nSearchHeight <= 500 && 0 <= nSearchHeight && nSearchHeight <= 500)
		{
			// Board영역을 벗어나지 않았다면
			// 탐색이 이루어졌던 자리인지 파악해야함
			if (vecVisitBoard[nSearchHeight][nSearchWidth] == false)
			{
				vecVisitBoard[nSearchHeight][nSearchWidth] = true;
				int nResult = vecInputBoard[nHeight][nWidth] + DFS(nSearchHeight, nSearchWidth, nDepth + 1, vecInputBoard, vecVisitBoard);
				if (nResult > nSum)
				{
					nSum = nResult;
				}
				vecVisitBoard[nSearchHeight][nSearchWidth] = false;
			}
		}
	}

	return nSum;

}