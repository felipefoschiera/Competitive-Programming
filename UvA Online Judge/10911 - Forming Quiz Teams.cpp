#include <stdio.h>
#include <vector>
#include <math.h>
using namespace std;
#define MAX 17

int N, target;
double dist[MAX][MAX];
double memo[1 << MAX];

double solve(int bitmask){
    if(memo[bitmask] != -1.0) return memo[bitmask];
    if(bitmask == target) return memo[bitmask] = 0.0;
    double ans = 2000000000.0;
    int p1, p2;
    for(p1 = 0; p1 < 2 * N; p1++)
        if(!(bitmask & (1 << p1)))
            break;
    for(p2 = p1+1; p2 < 2 * N; p2++)
        if(!(bitmask & (1 << p2)))
            ans = min(ans, dist[p1][p2] + solve(bitmask | (1 << p1) | (1 << p2)));
    return memo[bitmask] = ans;
}

int main(){
    int tc = 1;
    while(scanf("%d", &N), N){
        int x[MAX], y[MAX];
        for(int i = 0; i < 2 * N; i++)
            scanf("%*s %d %d", &x[i], &y[i]);
        for(int i = 0; i < 2 * N - 1; i++)
            for(int j = i+1; j < 2 * N; j++)
                dist[i][j] = dist[j][i] = hypot(x[i] - x[j], y[i] - y[j]);
        for(int i = 0; i < (1 << MAX); i++) memo[i] = -1.0;
        target = (1 << (2*N)) - 1;
        double res = solve(0);
        printf("Case %d: %.2lf\n", tc++, res);
    }
    return 0;
}