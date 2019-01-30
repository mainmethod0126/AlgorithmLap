#include <stdio.h>
#define n_max 100000

int get_2(int n){
  long long num = 1;

  do {
    num = num << n;
    num %= 1000000;
    n -= 20;
  } while ( n > 0 );

  return (int)num;
}
void scan_stick(int disks[], int count, int stick){
  int i;
  int read;

  for ( i = 0; i < count; i++ ){
    scanf("%d", &read);
    disks[read-1] = stick;
  }
}
int main(){
  int n;
  int disks[n_max] = {0, };

  int x1, x2, x3;
  scanf("%d", &n);
  scanf("%d%d%d", &x1, &x2, &x3);

  scan_stick(disks, x1, 1);
  scan_stick(disks, x2, 2);
  scan_stick(disks, x3, 3);

  int i;
  int target = disks[n-1];

  int now = disks[0];
  int sum = 0;

  if ( n == 1 ){
    printf("%d\n%d", target, sum);
    return 0;
  }

  int connection = 0;
  for ( i = 0; i < n; i++ ){
    if ( now == disks[i]){
      connection += 1;
    } else {
      if ( connection == 1 ){
        if ( now == target){

        } else {
          sum += 1;
        }
        
        sum += get_2(i-1) - 1;
      } else {
        sum += get_2(i) - 1;
      }
      connection = 1;
      now = disks[i];
    }
  }

  printf("%d\n%d\n", target, sum);
  return 0;
}
