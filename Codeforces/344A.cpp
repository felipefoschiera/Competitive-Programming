#include <cstdio>

int main(){
    int n, v;
    while(scanf("%d", &n) != EOF){
        int cnt = 0, prev = -1;
        for(int i = 0; i < n; i++){
            scanf("%d", &v);
            if(prev != -1){
                if((v == 1 && prev == 10 || (v == 10 && prev == 1))){
                    cnt++;
                }
            }
            prev = v;
        }
        printf("%d\n", ++cnt);
    }
    return 0;
}