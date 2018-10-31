// Codeforces 479A - Expression
// Felipe G. Foschiera
#include <cstdio>

inline int max(int a, int b) { return a > b ? a : b; }

int main(){
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    int res = max(a+b+c, max((a+b)*c, max(a*(b+c), max(a*b*c, max(a+b*c, a*b+c)))));
    printf("%d\n", res);
    return 0;
}