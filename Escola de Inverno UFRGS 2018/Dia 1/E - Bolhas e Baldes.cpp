#include <stdio.h>
#include <string.h>
#define MAX 112345

int ft[MAX];

void update(int k, int v){
    while(k < MAX){
        ft[k] += v;
        k += (k & (-k));
    }
}

int rsq(int b){
    int sum = 0;
    while(b > 0){
        sum += ft[b];
        b -= (b & (-b));
    }
    return sum;
}


int main(){
    int N;
    while(scanf("%d", &N), N){
        int count = 0;
        memset(ft, 0, sizeof ft);
        for(int i = 0; i < N; i++){
            int v;
            scanf("%d", &v);
            count += i - rsq(v);
            update(v, 1);
        }
        printf(count&1 ? "Marcelo\n" : "Carlos\n");
    
    }
    return 0;
}