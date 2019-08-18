#include <stdio.h>
#include <vector>
using namespace std;
#define MAX 112

typedef vector<int> vi;

int main(){
    int T, N, M, K, i, j, tot, best;
    char s[MAX];  
    scanf("%d", &T);
    while(T--){
        scanf("%d %d %d", &N, &M, &K);
        vi cnt(N, 0);
        for(i = 0; i < N; i++){
            scanf(" %s", s);
            for(j = 0; j < M; j++)
                cnt[i] += (s[j] == '*');
        }
        while(K--){
            best = 0;
            for(i = 0; i < N; i++){
                if(cnt[i] < cnt[best]){
                    best = i;
                }
            }
            cnt[best] = M - cnt[best];
        }
        tot = 0;
        for(i = 0; i < N; i++){
            tot += cnt[i];
        }
        printf("%d\n", tot);
    }
    return 0;
}
