#include <iostream>
#include <queue>
using namespace std;

int map[50][50];
int temp_map[50][50];
int visit[50][50];

int L, W; // ���� ���� ���� 

int Max = 0;

int direction[4][2] = { { 1, 0 },{ -1, 0 },{ 0, -1 },{ 0, 1 } }; // �����¿� Ž��

void bfs() {

	int TempY = 0; // ���� ��ǥ
	int TempX = 0; // ���� ��ǥ
	int hap = 0;
	
	queue<int> x; // ����
	queue<int> y; // ���� 

	for (int i = 0; i < L; i++) {
		for (int j = 0; j < W; j++) {

			if (map[i][j] == 2) {
				visit[i][j] = true; // Ž���� ��ġ true ������ ���� 

				x.push(j);  // ���� ��ǥ 
				y.push(i); // ���� ��ǥ
			}

		}
	}
	

	while (!x.empty() && !y.empty()) {

		int nowX = x.front();
		int nowY = y.front();
		x.pop();  // visit �� ��ǥ�� pop
		y.pop();  // visit �� ��ǥ�� pop

		for (int a = 0; a < 4; a++) {
			TempY = nowY + direction[a][0];
			TempX = nowX + direction[a][1];
			
			if (TempX < 0 || TempX >= W || TempY < 0 || TempY >= L) continue;   // map ���� �ʰ��� queue �� ���� ���� ex -�� �����ų� ��ũ�⺸�� Ŀ���ų� 

			if (map[TempY][TempX] == 0 && !visit[TempY][TempX]) {         // ���� �����¿� Ž������ 0�̰� visit ���� true�� �ƴ� ��� 

				visit[TempY][TempX] = true;       // �� ��ǥ���� true ��Ų��
				map[TempY][TempX] = 2;             // virus�� �۶߸���
				x.push(TempX);                    // �� ��ǥ���� queue�� �ִ´�
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
		for (int i = 0; i < L; i++) {         // �ٲ���� ���� ������ �ٲ۴� 
			for (int j = 0; j < W; j++) {
				temp_map[i][j] = map[i][j];
			}
		}
		bfs();
		memset(visit, 0, sizeof(visit));        // bfs�� ������ ������ 
		for (int i = 0; i < L; i++) {
			for (int j = 0; j < W; j++) {
				map[i][j] = temp_map[i][j];    
			}
		}

		return;
	}
	   // 0 �� ���� ������ ����� /1�� �����

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

	cin >> L >> W;             // ����, ���� ���� ���� 

	for (int i = 0; i < L; i++) {
		for (int j = 0; j < W; j++) {

			cin >> map[i][j];                 //  map �Է� �ޱ�
		}
	}

	search(3);

	cout << Max << endl;
}