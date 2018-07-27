#include <stdio.h>
#define MAX 11234

int main(){
    int N, v[MAX];
    while(scanf("%d", &N), N != 0){
        for(int i = 0; i < N; i++) scanf("%d", v+i);
        int desc = 1, count = 0;
        if(v[N-1] < v[0]) desc = 0;
        for(int i = 1; i <= N; i++){
            if((v[i%N] > v[(i-1)%N] && (desc)) || (v[i%N] < v[(i-1)%N] && (!desc)))
            {
                count++;
                desc ^= 1;
            }
        }
        printf("%d\n", count);
        
    }
    return 0;
}
