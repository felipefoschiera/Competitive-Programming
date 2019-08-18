#include <stdio.h>
#include <vector>
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;

vector<vii> LG;
vector<int> mark;

bool onpath(int u){
    for(auto e : LG[u])
        if(onpath(e.first)) mark[u] = 1; 
    return mark[u];
}

int solve(int u, int type){
    if(!mark[u]) return 0;
    int count = 0;
    for(auto e : LG[u]){
        if(mark[e.first]){
            if(type) count += solve(e.first, type) + e.second;
            else count = max(count, solve(e.first, type) + e.second);
        }
    }
    return count;
}

int main(){
    int N, F;
    while(scanf("%d %d", &N, &F) != EOF){
        LG.assign(N+1, vii());
        mark.assign(N+1, 0);
        int u, v, w;
        for(int i = 1; i < N; i++){
            scanf("%d %d %d", &u, &v, &w);
            LG[u].push_back(ii(v, w));
        }
        int f;
        for(int i = 0; i < F; i++){
            scanf("%d", &f);
            mark[f] = 1;
        }
        onpath(1);
        printf("%d\n", solve(1, 1) - solve(1, 0));

    }
    return 0;
}