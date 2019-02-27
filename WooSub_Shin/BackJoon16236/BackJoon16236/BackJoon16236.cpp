// BackJoon16236.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct  SHARK
{
	int shark_x;
	int shark_y;
	int shark_Size;
	int	shark_eatcount;
	int	shark_movecount;
};

void SearchFish();

SHARK shark;

int map[20][20];
bool visit[20][20];
int X, Y;

// 방향 탐색을 위한 배열~~ 상하좌우 탐색할꼬야~ 그러니까 사이즈가 4
// 위, 오른쪽, 아래, 왼쪽 순서로 가자 (시계방향 이게 편하더라~)~~
int DirX[4] = { -1, 0, 1, 0 };
int DirY[4] = { 0, 1, 0, -1 };

int main()
{
	cin >> X;
	Y = X;

	for (int i = 0; i < X; i++)
	{ 
		for (int j = 0; j < Y; j++)
		{
			cin >> map[i][j];
			// 상어 위치 입력해놓기
			if (map[i][j] == 9)
			{ 
				shark.shark_x = i;
				shark.shark_y = j;
				// 초기에 아기상어의 크기는 2다!
				shark.shark_Size = 2;
			}
		}
	}

	// 상어의 이동 시작~~ 아기상어~~ 뚜루루뚤~
	SearchFish();
}

void SearchFish()
{
	// 2차원 배열 전체 탐색할거니까 BFS나 DFS쓸건데 가까운데 있는놈 찾을거니까 BFS가 맞는듯
	queue<pair<int, int>> Queue;

	// 처음 아기상어의 위치를 큐에 넣어준다~~ 이곳을 기점으로 아기상어는 먹이를 찾아나서는대... 과연 먹이를 찾을 수 있을 것인가!!
	Queue.push(make_pair(shark.shark_x, shark.shark_y));
	visit[shark.shark_x][shark.shark_y] = true;

	// 더이상 맵에서 큐에 넣을 내용이 없을때까지~ 즉 큐가 비었다면 탈출 안비어있다면! while 반복!
	while (!Queue.empty())
	{
		// 현재 아기상어의 위치를 꺼내서~~ 이놈 주변 범위를 큐에 저장하고~~ 거기에 물고기들이 있는지~~~
		auto Front = Queue.front();
		Queue.pop();
		shark.shark_x = Front.first;
		shark.shark_y = Front.second;
		map[shark.shark_x][shark.shark_y] = 9;

		// 상어 이동 위치좀 보자
		for (int i = 0; i < X; i++)
		{
			cout << endl;
			for (int j = 0; j < Y; j++)
			{
				cout << map[i][j];
			}
		}
		cout << endl;
		
		// 현재 샤크의 위치에 물고기가 있었더라면~
		// 9는 상어의 위치
		if (map[Front.first][Front.second] >= 0 && map[Front.first][Front.second] < 9)
		{
			shark.shark_eatcount++;

			// 아기상어가 물고기를 먹었어! 그러면 이제 다시 탐색해야되!
			// 그런데 이미 스택에 한번 들어갔던 애들은 방문 처리가되서 스택에 못넣네? 길이 막혀버렸네?
			// 그럼 길을 다시 열어준다!
			// 방문 배열 0으로 초기화! 근데 이 코드 되는건가?
			memset(visit, 0, sizeof(visit));
		}
		// 먹은 물고기의 숫자가 아기상어의 사이즈와 동일시 되면 아기상어의 사이즈를 늘려준다~
		if (shark.shark_eatcount == shark.shark_Size)
		{
			shark.shark_Size + 1;
		}
		

		// 상하좌우에 있는지~~
		for (int i = 0; i < 4; i++)
		{
			int SearchDirX = Front.first + DirX[i];
			int SearchDirY = Front.second + DirY[i];
		

			// Map범위를 벗어나는지 먼저 확인하고~~ 벗어나면 쌩까고~
			if (SearchDirX >= X || SearchDirX < 0 || SearchDirY >= Y || SearchDirY < 0) continue;
			// 한번 갔던 곳이라면 큐에 안넣고 넘어가~~
			if (visit[SearchDirX][SearchDirY] == true) continue;
			// 자 이제 예외사항으로 상어의 사이즈보다 크거나 같으면~ 그놈도 큐에 안들어가
			if (map[SearchDirX][SearchDirY] >= shark.shark_Size) continue;

			// 물고기 크기로 크는게 아니라 마릿수지~~
			// 그렇다면~~ 한마리 먹을때마다 아기상어의 크기가 ++~!
			Queue.push(make_pair(SearchDirX, SearchDirY));
			// 큐에 한번 들어간 놈은 방문 체크!
			visit[SearchDirX][SearchDirY] = true;
			
			// 큐에 넣은놈이 0이 아니라면 일단 물고기란 소리니까 여기에서 검색조건에 들어온거면 샤크사이즈보다는 작은 물고기
		}

		map[shark.shark_x][shark.shark_y] = 0;

		// 아기상어가 이동할 위치가 저장되어있는 스택에서 하나 뽑았다는 것은 아기상어가 이동했다는 말과 같다 그러므로 무브 카운트 ++
		shark.shark_movecount++;
	}

	cout << shark.shark_movecount;
}

