// Felipe G. Foschiera
// URI 1267 - Biblioteca Pascal
#include <stdio.h>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
int main() {
    while(1) {
        int N, D;
        cin >> N >> D;
        if(N == 0 && D == 0) break;
        vector<int> presencas(N, 0);
        bool existe = false;
        for(int i = 0; i < D; i++){
            for(int j = 0; j < N; j++){
                int s;                
                cin >> s;
                if(s == 1){
                    presencas[j]++;
                    if(presencas[j] == D){
                        existe = true;
                    }
                }
            }
        }
        if(existe){
            cout << "yes\n";
        }else{
            cout << "no\n";
        }
    }
}