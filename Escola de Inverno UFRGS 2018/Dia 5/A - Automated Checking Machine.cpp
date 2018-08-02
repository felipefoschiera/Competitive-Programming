#include <stdio.h>

int main(){
    int v1[5];
    int v2[5];
    while(scanf("%d", v1) != EOF){
        for(int i = 1; i < 5; i++)
            scanf("%d", v1+i);
        
        for(int i = 0; i < 5; i++)
            scanf("%d", v2+i);
        bool ok = true;
        for(int i = 0; i < 5; i++){
            if(v1[i] == v2[i]) ok = false;
        }
        printf("%c\n", ok ? 'Y' : 'N');
    }
    return 0;
}