#include <stdio.h>
#include <vector>
#include <set>
#define MAX 11234
#define INF ((int)1e9)
using namespace std;

int M, N, L, K;
vector<int> count;
set<int> tabuas;

int pieces(int quant, int compr){
    if((quant * 100) % L != 0) return INF;
    int need = (quant * 100) / L, cnt = 0;
    vector<int> copy = count;
    set<int>::reverse_iterator rit;
    for(rit = tabuas.rbegin(); rit != tabuas.rend();){
        if(need <= 0) break;
        int el = *rit;
        int other = compr - el; 
        if(el > compr){
            rit++; continue;
        }
        if(other == 0){
            if(copy[el] <= 0){ rit ++; continue;}
            copy[el]--;
            cnt++;
        }else{
            if(el == other) {
                if(copy[el] <= 1) { rit++; continue; }
            }else{
                if(copy[el] <= 0 || copy[other] <= 0) { rit++; continue; }
            }
            copy[el]--, copy[other]--;
            cnt += 2;
        }
        need--;
    }
    if(need) return INF;
    return cnt;
}


int main(){
    while(scanf("%d %d", &M, &N), (N+M)){
        scanf("%d %d", &L, &K);
        int v;
        tabuas.clear();
        count.assign(MAX, 0);
        count[0] = INF;
        for(int i = 0; i < K; i++){
            scanf("%d", &v);
            tabuas.insert(v);
            count[v]++;
        }
        int ans = INF;
        ans = min(ans, min(pieces(N, M), pieces(M, N)));     
        if(ans >= INF) printf("impossivel\n");
        else printf("%d\n", ans);  
    }
    return 0;
}