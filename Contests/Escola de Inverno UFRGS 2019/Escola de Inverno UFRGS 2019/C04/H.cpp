#include <bits/stdc++.h>
using namespace std;
#define MAX 11

int main(){
    int T, n, i, a[MAX], x, mA;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        mA = 0;
        for(i = 0; i < n; i++){
            scanf("%d", a+i);
            mA = max(mA, a[i]);
        }
        x = max(3*a[0], 4);
        x = max(x, mA+1);
        if(x&1) x++;
        printf("%d\n", x);
    }
    return 0;
}