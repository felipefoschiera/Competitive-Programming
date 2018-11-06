#include <cstdio>
#include <string>

int main(){
    char s[112];
    scanf(" %s", s);
    int lo = 0, up = 0;
    for(int i = 0; s[i]; i++){
        lo += (s[i] >= 'a' && s[i] <= 'z');
        up += (s[i] >= 'A' && s[i] <= 'Z');
    }
    for(int i = 0; s[i]; i++){
        printf("%c", (lo >= up) ? tolower(s[i]) : toupper(s[i]));
    }
    printf("\n");
    return 0;
}