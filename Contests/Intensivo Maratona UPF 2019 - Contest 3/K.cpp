#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int hp[1010], mana[1010];

ll pd[1010][2010];
int N, p;
const int INF = 1e9;


ll solve(int idx, int vida){
    if(vida <= 0) return 0;
    if(idx == N){
        return (vida <= 0 ? 0 : INF);
    }
    if(pd[idx][vida] != -1)
        return pd[idx][vida];
    
    ll res = mana[idx] + solve(idx+1, vida - hp[idx]);
    res = min(res, solve(idx+1, vida));
    return pd[idx][vida] = res;
}

int main(){
    while(cin >> N >> p){
        for(int i = 0; i < N; i++){
            cin >> hp[i] >> mana[i];
        }
        memset(pd, -1, sizeof pd);
        ll res = solve(0, p);
        cout << (res >= INF ? -1 : res) << '\n';
    }
    return 0;
}