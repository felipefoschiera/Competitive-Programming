#include <stdio.h>

int main(){
    int ocur[26] = {0};
    int cnt = 0;
    char a[101];
    scanf("%s", a);
    for(int i = 0; a[i]; i++){
        if(!ocur[a[i] - 'a']){
            cnt++;
            ocur[a[i] - 'a']++;
        }
    }
    printf("%s\n", (cnt&1) ? "IGNORE HIM!" : "CHAT WITH HER!");
    return 0;
}