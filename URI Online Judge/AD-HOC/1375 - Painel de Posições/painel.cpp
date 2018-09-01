#include <cstdio>

int main(){
    int N;
    while(scanf("%d", &N), N){
        bool ok = true;
        int v[N];
        for(int i = 0; i < N; i++) v[i] = -1;
        int c, p;
        for(int i = 0; i < N; i++){
            scanf("%d %d", &c, &p);
            if(i+p >= 0 && i+p < N && (v[i+p] == -1)) v[i+p] = c;
            else ok = false;
        }
        if(!ok) printf("-1\n");
        else {
            for(int i = 0; i < N; i++){
                printf("%d%c", v[i], (i == N-1 ? '\n' : ' '));
            }
        }
    }
    return 0;
}