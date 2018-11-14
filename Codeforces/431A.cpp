// Codeforces 431A - Black Square
// Felipe G> Foschiera
#include <cstdio>

const int MAX = 101010;

int main(){
    int v[4];
    for(int i = 0; i < 4; i++)
        scanf("%d", &v[i]);
    int cnt = 0;
    char s[MAX];
    scanf(" %s", s);
    for(int i = 0; s[i]; i++){
        cnt += v[s[i] - '0' - 1];
    }
    printf("%d\n", cnt);
    return 0; 
}