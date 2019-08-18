#include <stdio.h>
#include <algorithm>
using namespace std;

bool cmp(int a, int b){
    return a > b;
}

int main(){
    int S;
    while(scanf("%d", &S) != EOF){
        int Q[S], v[S];
        for(int i = 0; i < S; i++) scanf("%d", Q+i);
        for(int i = 0; i < S; i++) scanf("%d", v+i);
        sort(Q, Q+S, cmp);
        sort(v, v+S, cmp);
        int i = 0, j = 0, count = 0;
        while(j < S){
            if(v[i] > Q[j]){
                count++, i++, j++;
            }else{
                j++;        
            }
        }
        printf("%d\n", count);
        
    }
    return 0;
}