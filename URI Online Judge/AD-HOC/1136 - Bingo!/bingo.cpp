#include <cstdio>
#include <cstring>
using namespace std;

inline int abs(int x) { return x < 0 ? -x : x; }

int main(){
    int N, B;
    while(scanf("%d %d", &N, &B), (N+B)){
        int v[B];
        for(int i = 0; i < B; i++) scanf("%d", v+i);
        int somas[N+1];
        memset(somas, 0, sizeof somas);
        for(int i = 0; i < B; i++)
            for(int j = 0; j < B; j++)
                somas[abs(v[i]-v[j])] = 1;
        bool ok = true;
        for(int i = 0; i <= N; i++) if(!somas[i]) ok = false;
        printf("%c\n", ok ? 'Y' : 'N');

    }
    return 0;
}