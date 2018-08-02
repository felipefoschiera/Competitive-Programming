#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAX 1023

int difference(int a, int b){
    return min(abs(a-b), 24-abs(a-b));
}

int main(){
    int N, i, v[MAX];
    while(scanf("%d", &N) != EOF){
        for(i = 0; i < N; i++){
            scanf("%d", v+i);
        }
        sort(v, v+N);
        int ans1 = 0;
        for(i = 0; i < N; i += 2){
            ans1 += difference(v[i], v[i+1]);
        }
        int ans2 = difference(v[0], v[N-1]);
        for(int i = 1; i < N-1; i += 2){
            ans2 += difference(v[i], v[i+1]);
        }
        printf("%d\n", min(ans1, ans2));
    }
    return 0;
}