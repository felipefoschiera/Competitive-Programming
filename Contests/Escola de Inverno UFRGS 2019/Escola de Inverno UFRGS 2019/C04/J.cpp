#include<bits/stdc++.h>
using namespace std;
#define MAXN 112345

int main(){
    int N, S, J, D;
    int i, wa, wb;
    char s[MAXN];
    while(scanf("%d %d %d %d", &N, &S, &J, &D) != EOF){
        scanf(" %s", s);
        wa = wb = 0;
        int pta = 0, ptb = 0;
        for(i = 0; s[i]; i++){
            pta += (s[i] == 'A');
            ptb += (s[i] == 'B');
            int diff = abs(pta-ptb);
            if(pta >= J && pta > ptb && diff >= D){
                wa++;
                pta = 0; ptb = 0;
            }else if(ptb >= J && ptb > pta && diff >= D){
                wb++;
                pta = 0; ptb = 0;
            }
        }
        printf("%d %d\n", wa, wb);
    }
    return 0;
}
