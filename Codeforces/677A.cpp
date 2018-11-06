#include <cstdio>

int main(){
    int n, h;
    scanf("%d %d", &n, &h);
    int cnt = 0, ht;
    for(int i = 0; i < n; i++){
        scanf("%d", &ht);
        cnt++;
        if(ht > h) cnt++;
    }
    printf("%d\n", cnt);
    return 0;
}