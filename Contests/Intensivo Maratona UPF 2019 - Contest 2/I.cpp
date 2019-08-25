#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

typedef pair<ll, pair<ll, ll>> ii;

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        ll a, b;
        vector<ii> focos;
        for(int i = 0; i < n; i++){
            scanf("%lld %lld", &a, &b);
            focos.push_back({a, {0, i}});
            focos.push_back({b, {1, i}});
        }
        // ordena os focos por valor do inicio ou fim do intervalo (e marca inicio ou fim)
        sort(focos.begin(), focos.end());
        int cnt = 0;
        set<int> aberto;
        for(auto f : focos){
            // quando acha um fechamento de um intervalo atualmente aberto, conta um e limpa o conjunto (tira foto do intervalo)
            if(f.second.first == 1 && aberto.find(f.second.second) != aberto.end()){
                cnt++;
                aberto.clear();
            }else{
                aberto.insert(f.second.second);
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}