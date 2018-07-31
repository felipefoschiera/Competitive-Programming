#include <stdio.h>

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        int min = 101;
        int max = -1;
        int v;
        for(int i = 0; i < n; i++){
            scanf("%d", &v);
            if(v > max) max = v;
            if(v < min) min = v;
        }
        printf("%d\n", 2*(max-min));
    }
    return 0;
}