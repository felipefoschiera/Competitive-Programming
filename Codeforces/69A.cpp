#include <stdio.h>
int v[3];

int main(){ 
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++){
            int f;
            scanf("%d", &f);
            v[j] += f;
        }
    }
    printf(v[0] == 0 && v[1] == 0 && v[2] == 0 ? "YES\n" : "NO\n");
    return 0;   
}

