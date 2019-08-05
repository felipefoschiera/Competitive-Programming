#include <bits/stdc++.h>
using namespace std;

#define MAX 16

int N;
double dist[MAX][MAX];
int posX[MAX], posY[MAX];
double memo[MAX][1 << MAX];


double tsp(int pos, int bitmask){
    if(bitmask == (1 << (N+1)) - 1) return dist[pos][0];
    if(memo[pos][bitmask] != -1.0) return memo[pos][bitmask];
    double ans = 2000000000.0;
    for(int nxt = 0; nxt <= N; nxt++)
        if(nxt != pos && !(bitmask & (1 << nxt)))
            ans = min(ans, dist[pos][nxt] + tsp(nxt, bitmask | (1 << nxt)));
    return memo[pos][bitmask] = ans;
}


double distance(int ax, int ay, int bx, int by){
    return hypot(ax-bx, ay-by);
}

int main(){
    while(scanf("%d", &N), N){
        scanf("%d %d", &posX[0], &posY[0]);
        for(int i = 1; i <= N; i++)
                scanf("%d %d", &posX[i], &posY[i]);
        
        for(int i = 0; i < N; i++)
            for(int j = i+1; j <= N; j++){
                dist[i][j] = dist[j][i] = distance(posX[i], posY[i], posX[j], posY[j]);
    }
        for(int i = 0; i < MAX; i++)
            for(int j = 0; j < (1 << MAX); j++)
                memo[i][j] = -1.0;

        printf("%.2lf\n", tsp(0, 1));
            
    }

    
    return 0;
    
}