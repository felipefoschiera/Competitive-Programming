// URI 2498 - Ajude Vânia
// Felipe G. Foschiera
#include <stdio.h>
#include <string.h>
#define MAX 112
using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }

int ks[MAX], ks2[MAX];
int knapsack(int W, int wt[], int v[], int n){
    memset(ks, 0, sizeof ks); 
    memset(ks2, 0, sizeof ks2);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= W; j++)
            if(j - wt[i-1] >= 0)
                ks2[j] = max(ks[j], ks[j-wt[i-1]] + v[i-1]);
        for(int j = 1; j <= W; j++)
            ks[j] = ks2[j];
    }
    return ks[W];
}


int main(){
    int N, C, tc = 1;
    while(scanf("%d %d", &N, &C), (N+C)){
        int wt[N], v[N];
        for(int i = 0; i < N; i++)
            scanf("%d %d", &wt[i], &v[i]);
        printf("Caso %d: %d\n", tc++, knapsack(C, wt, v, N));
    }

    return 0;
}