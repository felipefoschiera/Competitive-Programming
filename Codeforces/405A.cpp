#include <cstdio>
#include <algorithm>

int main(){
    int n;
    scanf("%d", &n);
    int v[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &v[i]);
    std::sort(v, v+n);
    for(int i = 0; i < n; i++)
        printf("%d%c", v[i], (i == n-1 ? '\n' : ' '));
    return 0;
}