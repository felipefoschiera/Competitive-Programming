#include <cstdio>
#include <string>

int main(){
    char s[1123];
    scanf(" %s", s);
    for(int i = 0; s[i]; i++){
        printf("%c", (i == 0) ? toupper(s[i]) : s[i]);
    }
    printf("\n");
    return 0;
}