//
//  main.c
//  Coding
//
//  Created by tak on 16/01/2019.
//  Copyright © 2019 tak. All rights reserved.
//

#include <stdio.h>

int checked[500][500] = {0, };

int get_max(int num[500][500], int width, int height, int x, int y, int count){
    if ( count >= 4 || checked[y][x] == 1){
        return 0;
    }
    
    checked[y][x] = 1;
    int left = 0;
    int right = 0;
    int down = 0;
    int up = 0;
    
    if ( x > 0 ){
        left = get_max(num, width, height, x-1, y, count+1);
    }
    if ( x < width-1 ){
        right = get_max(num, width, height, x+1, y, count+1);
    }
    if ( y < height-1 ){
        down = get_max(num, width, height, x, y+1, count+1);
    }
    if ( y > 0 ){
        up = get_max(num, width, height, x, y-1, count+1);
    }
    
    int max = 0;
    if ( max < left ){
        max = left;
    }
    if ( max < right ){
        max = right;
    }
    if ( max < down ){
        max = down;
    }
    if ( max < up ){
        max = up;
        
    }
    
    checked[y][x] = 0;
    
    return max + num[y][x];
}

int main(int argc, const char * argv[]) {
    int N; // vertical
    int M; // horizontal
    int num[500][500] = {0, };
    scanf("%d %d", &N, &M);
    
    int j, k;
    
    for(j = 0; j < N; j++){
        for(k = 0; k < M; k++){
            scanf("%d", &num[j][k]);
        }
    }
    
    int max = 0;
    for(j = 0; j < N; j++){
        for(k = 0; k < M; k++){
            int tmp = get_max(num, M, N, k, j, 0);
            if( tmp > max ){
                max = tmp;
            }
            int sum = 0;
            
            if ( j > 0 && j < N-1 && k < M-1 ){
                sum = num[j][k] + num[j-1][k] + num[j+1][k] + num[j][k+1];
            }
            if ( sum > max ){
                max = sum;
            }
            if ( j > 0 && j < N-1 && k > 0 ){
                sum = num[j][k] + num[j-1][k] + num[j+1][k] + num[j][k-1];
            }
            if ( sum > max ){
                max = sum;
            }
            if ( j > 0 && k < M-1 && k > 0 ){
                sum = num[j][k] + num[j-1][k] + num[j][k-1] + num[j][k+1];
            }
            if ( sum > max ){
                max = sum;
            }
            if ( j < N-1 && k < M-1 && k > 0 ){
                sum = num[j][k] + num[j+1][k] + num[j][k-1] + num[j][k+1];
            }
            if ( sum > max ){
                max = sum;
            }
        }
    }
    
    //output
    printf("%d\n", max);
    return 0;
}
