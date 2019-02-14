#include <iostream>
#include <queue>
using namespace std;

int map[50][50];
int temp_map[50][50];
int visit[50][50];

int L, W; // 가로 세로 변수 

int Max = 0;

int direction[4][2] = { { 1, 0 },{ -1, 0 },{ 0, -1 },{ 0, 1 } }; // 상하좌우 탐색

void bfs() {

	int TempY = 0; // 세로 좌표
	int TempX = 0; // 가로 좌표
	int hap = 0;
	
	queue<int> x; // 가로
	queue<int> y; // 세로 

	for (int i = 0; i < L; i++) {
		for (int j = 0; j < W; j++) {

			if (map[i][j] == 2) {
				visit[i][j] = true; // 탐색한 위치 true 값으로 선택 

				x.push(j);  // 가로 좌표 
				y.push(i); // 세로 좌표
			}

		}
	}
	

	while (!x.empty() && !y.empty()) {

		int nowX = x.front();
		int nowY = y.front();
		x.pop();  // visit 된 좌표를 pop
		y.pop();  // visit 된 좌표를 pop

		for (int a = 0; a < 4; a++) {
			TempY = nowY + direction[a][0];
			TempX = nowX + direction[a][1];
			
			if (TempX < 0 || TempX >= W || TempY < 0 || TempY >= L) continue;   // map 범위 초과시 queue 에 넣지 않음 ex -가 나오거나 맵크기보다 커지거나 

			if (map[TempY][TempX] == 0 && !visit[TempY][TempX]) {         // 만약 상하좌우 탐색값이 0이고 visit 값이 true가 아닌 경우 

				visit[TempY][TempX] = true;       // 그 좌표값을 true 시킨다
				map[TempY][TempX] = 2;             // virus를 퍼뜨린다
				x.push(TempX);                    // 그 좌표값을 queue에 넣는다
				y.push(TempY);

			}
		}
	}

	for (int i = 0; i < L; i++) {
		for (int j = 0; j < W; j++) {

			if (map[i][j] == 0)
				hap++;

		}
	}
	if (hap > Max) {
		Max = hap;
	}

}


void search(int count) {
	if (count == 0) {
		for (int i = 0; i < L; i++) {         // 바뀐맵을 원래 맵으로 바꾼다 
			for (int j = 0; j < W; j++) {
				temp_map[i][j] = map[i][j];
			}
		}
		bfs();
		memset(visit, 0, sizeof(visit));        // bfs를 수행할 때마다 
		for (int i = 0; i < L; i++) {
			for (int j = 0; j < W; j++) {
				map[i][j] = temp_map[i][j];    
			}
		}

		return;
	}
	   // 0 인 방을 벽으로 세운다 /1로 만든다

	for (int i = 0; i < L; i++) {
		for (int j = 0; j < W; j++) {
			
			if (map[i][j] == 0) {
				map[i][j] = 1;
				search(count - 1);
				map[i][j] = 0;
			}
		}

	}
}


int main() {

	cin >> L >> W;             // 가로, 세로 넓이 지정 

	for (int i = 0; i < L; i++) {
		for (int j = 0; j < W; j++) {

			cin >> map[i][j];                 //  map 입력 받기
		}
	}

	search(3);

	cout << Max << endl;
}