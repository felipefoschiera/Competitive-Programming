// Felipe G. Foschiera
// URI 2680 - Folha de Pagamentos
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        int m;
        cin >> m;
        int j = 1;
        int soma = 0;
        while(j*j <= m){
            if(m % j == 0){
                soma += j;
                int calc = (int) m / j;
                if(calc != j){
                    soma += calc;
                }
            }
            j++;
        }
        cout << soma << '\n';
    }


    return 0;
}