#include <stdio.h>
int main(){
  int N; // 1 <= N <= 15
  int T[15];
  int P[15];
  int save[15] = {0, };

  scanf("%d", &N);

  int i = 0;
  int j = 0;

  for ( i = 0; i < N; i++ ){
    scanf("%d %d", &T[i], &P[i]);
  }

  for ( i = 0; i < N; i++ ){
    for ( j = 0; j <= i; j++){
      if ( j + T[j] > i+1 ){
        continue;
      }
      if ( j > 0 ){
        if ( save[j-1] + P[j] > save[i] ){
          save[i] = save[j-1] + P[j];
        }
      } else {
        save[i] = P[j];
      }
    }
  }

  printf("%d\n", save[N-1]);
  return 0;
}
