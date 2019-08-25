#include <bits/stdc++.h>
using namespace std;

int botas[2][65];

int main(){
    int n;
    while(cin >> n){
        memset(botas, 0, sizeof botas);
        int tam; char tipo;
        for(int i = 0; i < n; i++){
            cin >> tam >> tipo;
            if(tipo == 'D') botas[0][tam]++;
            if(tipo == 'E') botas[1][tam]++;
        }
        int res = 0;
        for(int t = 30; t <= 60; t++){
            res += min(botas[0][t], botas[1][t]);
        }
        cout << res << '\n';
    }
    return 0;
}