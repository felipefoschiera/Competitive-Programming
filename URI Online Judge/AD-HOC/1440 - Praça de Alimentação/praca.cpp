#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, char> acao;

int timeSeconds(int hora, int min, int seg) { return seg + (hora*3600) + (min*60); }
inline int max(int a, int b) { return a > b ? a : b; }
bool comp(acao a, acao b) { return a.first < b.first; }

int main(){
    int N;
    while(scanf("%d", &N), N){
        vector<acao> acoes;
        int entradas = 0;
        for(int i = 0; i < N; i++){
            int h, m, s;
            char op;
            scanf("%d:%d:%d %c", &h, &m, &s, &op);
            if(op == 'E') entradas++;
            acoes.push_back(acao(timeSeconds(h, m, s), op));
        }
        sort(acoes.begin(), acoes.end(), comp);
        for(int i = 0; i < N; i++){
            if(acoes[i].second == '?'){
                if(entradas < N/2)
                    entradas++, acoes[i].second = 'E';
                else acoes[i].second = 'S';
            }
        }
        int maximo = 0, in = 0;

        for(int i = 0; i < N; i++){
            if(acoes[i].second == 'E') in++;
            else in--;
            maximo = max(maximo, in);
        }
        printf("%d\n", maximo);
    }
    return 0;
}