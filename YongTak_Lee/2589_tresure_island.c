#include <stdio.h>
#define true 1
#define false 0

int recursive(char map[50][51], int checked[50][50], int height, int width, int j, int k, int count){
  if ( j < 0 || j >= height || k < 0 || k >= width ){
    return 0;
  }
  if ( map[j][k] == 'W' || checked[j][k] == true){
    return 0;
  }

  checked[j][k] = true;




  checked[j][k] = false;
  return 1;
}

void init_checked(int checked[50][50]){
  int j, k;
  for ( j = 0; j < height; j++ ){
    for ( k = 0; k < width; k++ ){
      checked[j][k] = 0;
    }
  }
}

int main(){
  char map[50][51];
  int checked[50][50];
  int height, width;

  scanf("%d %d", &height, &width);

  int j, k;
  for ( j = 0; j < height; j++ ){
    scanf("%s", map[j]);
  }

  int max = 0;
  int temp;
  for ( j = 0; j < height; j++ ){
    for ( k = 0; k < width; k++ ){
      init_checked(checked);
      int temp = recursive(map, checked, height, width, j, k, 0);
      if ( temp > max ){
        max = temp;
      }
    }
  }

  printf("%d", max);

  return 0;
}
