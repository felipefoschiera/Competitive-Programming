#include <cstdio>

int main(){
    int n, a, b, c;
    while(scanf("%d", &n) != EOF){
        int res = 0;
        for(int i = 0; i < n; i++){
            int cnt = 0;
            scanf("%d %d %d", &a, &b, &c);
            cnt = a + b + c;
            res += (cnt > 1);
        }
        printf("%d\n", res);
    }
    return 0;  
}