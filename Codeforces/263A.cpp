#include <cstdio>

inline int abs(int x) { return x < 0 ? -x : x; }

int main(){
    int y, x, v;
    for(int i = 1; i <= 5; i++){
        for(int j = 1; j <= 5; j++){
            scanf("%d", &v);
            if(v) y = i, x = j;
        }
    }
    printf("%d\n", abs(y-3) + abs(x-3));
    return 0;   
}