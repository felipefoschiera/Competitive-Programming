// URI 2396 - Corrida
// Felipe G. Foschiera
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<long long, int> li;

int main(){
    int N, M;
    long long tempo, tempo_total;
    vector<li> posicoes;
    scanf("%d %d", &N, &M);
    for(int i = 1; i <= N; i++){
        tempo_total = 0;
        for(int j = 0; j < M; j++){
            scanf("%lld", &tempo);
            tempo_total += tempo;
        }
        posicoes.push_back(li(tempo_total, i));
    }
    sort(posicoes.begin(), posicoes.end());
    printf("%d\n%d\n%d\n", posicoes[0].second, posicoes[1].second, posicoes[2].second);
    return 0;
}