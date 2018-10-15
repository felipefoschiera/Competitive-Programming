#include <cstdio>

bool possivel(int n, int v){
    for(int i = 1; i <= v; i++){
        int k = i, ind = 0;
        while(k > 0){
            for(int j = 0; j < k; j++){
                ind += k;
                if(ind == n) return true;
            }
            k--;
        }
    }
    return false;
}

int main(){
    int n, v;
    while(scanf("%d %d", &n, &v), n+v){
        printf("%spossivel\n", (possivel(n, v) ? "" : "im"));
    }
    return 0;
}