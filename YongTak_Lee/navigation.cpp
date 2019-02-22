#include <iostream>
#include <queue>
#include <algorithm>
#include <memory.h>
using namespace std;
#define SIZE 7
int map[SIZE][SIZE] = {
  {18, 17, 16, 15, 14, 13, 12},
  {9, 11, 13, 15, 17, 19, 21},
  {18, 17, 16, 15, 14, 13, 12},
  {14, 16, 18, 20, 22, 24, 26},
  {16, 15, 14, 13, 12, 11, 10},
  {6, 8, 10, 12, 14, 16, 18},
  {22, 21, 20, 19, 18, 17, 16}
};
pair<int, int> chase[SIZE][SIZE];

typedef struct coordinate{
  int x, y;
}TPoint;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int temp_map[SIZE][SIZE];

int answer = 100000;
int start_y_idx = -1;
int end_y_idx = -1;
int find(int startX, int startY){
  int ans = 100000;

  // init temp_map

  for ( int y = 0; y < SIZE; y++ ){
    for ( int x = 0; x < SIZE; x++ ){
      temp_map[y][x] = 100000;
    }
  }
  queue<TPoint> q;

  TPoint temp = { .x = startX, .y = startY };
  q.push(temp);
  temp_map[startY][startX] = map[startY][startX];

  while ( !q.empty() ){
    int nowX = q.front().x;
    int nowY = q.front().y;
    q.pop();
    for ( int y = 0; y < SIZE; y++ ){
      for ( int x = 0; x < SIZE; x++ ){
        for ( int d = 0; d < 4; d++ ){
          int tX = nowX + dx[d];
          int tY = nowY + dy[d];

          if ( tX < 0 || tX >= SIZE || tY < 0 || tY >= SIZE ) continue;
          if ( temp_map[nowY][nowX] + map[tY][tX] >= temp_map[tY][tX] ) continue;

          chase[tY][tX] = make_pair(nowX, nowY);
          temp_map[tY][tX] = temp_map[nowY][nowX] + map[tY][tX];
          TPoint t = {.x = tX, .y = tY};
          q.push(t);
        }
      }
    }
  }

  int temp_idx = -1;
  for ( int y=0; y < SIZE; y++ ){
    if ( ans < temp_map[y][SIZE-1] ) continue;
    ans = min(ans, temp_map[y][SIZE-1]);
    temp_idx = y;
  }

  if ( answer > ans ) {
    start_y_idx = startY;
    end_y_idx = temp_idx;
    answer = ans;
  }
  // for debug
  for ( int y = 0; y < SIZE; y++ ){
    for ( int x = 0; x < SIZE; x++ ){
      cout << temp_map[y][x] << " ";
    }
    cout << endl;
  }
  cout << endl;

  return ans;
}
int main(){
  int ans = 100000;
  pair<int, int> ans_route[SIZE][SIZE];
  for ( int y = 0; y < SIZE; y++){
    int temp = find(0, y);

    if ( temp == answer ){
      for ( int y = 0; y < SIZE; y++ ){
        for (int x = 0; x < SIZE; x++ ){
          ans_route[y][x] = chase[y][x];
        }
      }
    }
  }

  vector<pair<int, int> > ans_v;
  int x = SIZE-1, y = end_y_idx;
  ans_v.push_back(make_pair(x, y));
  while ( true ){
    x = ans_v.back().first;
    y = ans_v.back().second;
    if ( x == 0 && y == start_y_idx ) break;
    ans_v.push_back(ans_route[y][x]);
  }
  for ( int i = ans_v.size()-1; i >= 0; i-- ){
    cout << "(" << ans_v[i].first << ", " << ans_v[i].second << ") ";
  }
  cout << "answer: "<< answer << endl;
  return 0;
}
