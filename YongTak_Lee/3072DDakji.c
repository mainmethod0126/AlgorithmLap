//
//  3072DDakji.c
//  
//
//  Created by tak on 15/01/2019.
//

#include <stdio.h>

int main(){
    int N;
    
    scanf("%d", &N);
    
    int count_a = 0;
    int count_b = 0;
    
    int j = 0;
    
    for( j = 0; j < N; j++){
        scanf("%d", &count_a);
        int a_ddakji[4] = {0, };
        int b_ddakji[4] = {0, };
        int k = 0;
        
        for(k = 0; k < count_a; k++){
            int tmp;
            scanf("%d", &tmp);
            
            a_ddakji[tmp-1] += 1;
        }
	scanf("%d", &count_b);
        for(k = 0; k < count_b; k++){
            int tmp;
            scanf("%d", &tmp);
            
            b_ddakji[tmp-1] += 1;
        }
        int printed = 0;
        for(k = 3; k >= 0; k--){
	    printf("%d, %d\n", a_ddakji[k], b_ddakji[k]);
            if(a_ddakji[k] > b_ddakji[k]){
                printf("A\n");
                printed = 1;
                break;
            } else if (a_ddakji[k] < b_ddakji[k]){
                printf("B\n");
                printed = 1;
                break;
            }
        }
        
        if ( printed != 1){
            printf("D\n");
        }
    }
    return 0;
}
