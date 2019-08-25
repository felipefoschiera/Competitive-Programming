#include <bits/stdc++.h>
using namespace std;

int est[1010];

int main(){
    int c, n;
    while(cin >> c >> n){
        char op;
        for(int i = 0; i < 1010; i++) est[i] = 0;
        int placa, tam, res = 0;
        for(int e = 0; e < n; e++){
            cin >> op >> placa;
            if(op == 'C'){
                cin >> tam;
                int pos = -1;
                for(int i = 1; i <= c-tam+1; i++){
                    if(est[i] == 0){
                        int cntr = 0;
                        for(int j = 0; j < tam; j++){
                            if(est[i+j] != 0) break;
                            cntr++;
                        }
                        if(cntr == tam) {pos = i; break; }
                    }
                }
                if(pos != -1){
                    for(int i = pos; i < pos+tam; i++){
                        est[i] = placa;
                    }
                    res++;
                }
            }else if(op == 'S'){
                for(int i = 1; i <= c; i++){
                    if(est[i] == placa){
                        est[i] = 0;
                    }
                }   
            }
        }
        cout << res*10 << '\n';
    }
    return 0;
}