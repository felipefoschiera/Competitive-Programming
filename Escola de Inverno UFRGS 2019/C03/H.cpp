#include <bits/stdc++.h>
using namespace std;
#define LEN 16

int main(){
    int i, j, idx, jdx;
    char s[3][16], acc;
    while(fgets(s[0], LEN, stdin) != NULL){
        acc = 0;
        for(i = 0; i < 3; i++){
            if(i) fgets(s[i], LEN, stdin);
            for(j = 0; s[i][j] != '\n'; j++){
                if(s[i][j] == '='){
                    idx = i;
                    jdx = j;
                }
            }
        }
        for(j = jdx+1; s[idx][j] != '\n'; j++){
            if(s[idx][j] != '.'){
                acc = s[idx][j];
                break;
            }
        }
        if(acc == 0){
            printf("You shall pass!!!\n");
        }
        else printf("%c\n", acc);
    }
    return 0;
}