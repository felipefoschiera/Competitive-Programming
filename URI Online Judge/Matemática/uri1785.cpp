#include <cstdio>
#include <algorithm>
using namespace std;

bool cmp(const int a, const int b) { return a > b; }

int getEl(int X, bool rev){
    int v[4];
    for(int i = 0; i < 4; i++){
        v[i] = X % 10;
        X /= 10;
    }
    if(rev) sort(v, v+4, cmp);
    else sort(v, v+4);
    int novo = 0;
    for(int i = 0; i < 4; i++)
        novo = novo * 10 + v[i];
    return novo;
}

int kaprekar(int X){
    int cnt = 0;
    bool ok = true;
    while(X != 6174){
        int maior = getEl(X, true);
        int menor = getEl(X, false);
        X = maior - menor;
        cnt++;
        if(X == 0) { ok = false; break; }
    }
    return ok ? cnt : -1;
}

int main(){
    int t;
    scanf("%d", &t);
    for(int tc = 1; tc <= t; tc++){
        int n;
        scanf("%d", &n);
        int res = kaprekar(n);
        printf("Caso #%d: %d\n", tc, res);
    }
    return 0;
}