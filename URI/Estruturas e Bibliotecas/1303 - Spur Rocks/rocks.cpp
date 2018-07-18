/**
 *  URI 1303 - Spur Rocks
 *  Felipe G. Foschiera - UPF
 */
#include <stdio.h>
#include <algorithm>
#define eps 1e-9
using namespace std;

struct team {
    int id, pontos = 0, feitos = 0, tomados = 0;
    bool operator < (const team& a) const{
        if(pontos != a.pontos) return pontos > a.pontos;
        else {
            double avgA, avgB;
            avgA = tomados == 0 ? (double)feitos : (double)feitos / (double)tomados;
            avgB = a.tomados == 0 ? (double)a.feitos : (double)a.feitos / (double)a.tomados;
            if(avgA + eps != avgB + eps) return avgA + eps > avgB + eps;
            else {
            if(feitos != a.feitos) return feitos > a.feitos;
            else return id < a.id;
            }
        }
    }
};



int main(){
    int N, inst = 1;
    while(scanf("%d", &N), N){
        if(inst != 1) printf("\n");     
        printf("Instancia %d\n", inst++);
        if(N == 1) printf("1\n");
        int part = N*(N-1) / 2;
        team times[N];
        for(int i = 1; i <= N; i++) times[i-1].id = i;
        for(int i = 0; i < part; i++){
            int x, y, z, w;
            scanf("%d %d %d %d", &x, &y, &z, &w);
            times[x-1].feitos += y, times[z-1].feitos += w;
            times[x-1].tomados += w, times[z-1].tomados += y;
            times[x-1].pontos += (y > w ? 2 : 1), times[z-1].pontos += (y > w ? 1 : 2);
        }
        sort(times, times+N);
        for(int i = 0; i < N; i++)
            printf("%d%c", times[i].id, (i == N-1 ? '\n' : ' '));
    }
    return 0;
}