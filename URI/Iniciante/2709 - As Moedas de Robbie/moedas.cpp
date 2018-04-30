// Felipe G. Foschiera
// URI 2709 - As Moedas de Robbie
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

bool isPrime(int n){
    if(n == 2 || n == 3) return true;
    if(n % 2 == 0 || n < 2) return false;
    int raiz = pow(n, 0.5);
    for(int i = 3; i <= raiz; i++){
        if(n % i == 0) return false;
    }
    return true; 
}

int main() {
    int M;
    while(cin >> M){
        vector<int> moedas;
        for(int i = 0; i < M; i++){
            int V;
            cin >> V;
            moedas.push_back(V);
        }
        int N;
        cin >> N;
        int soma = 0;
        for(int i = M-1; i >= 0; i -= N){
            soma += moedas[i];
        }
        if(!isPrime(soma)){
            cout << "Bad boy! I’ll hit you.\n";
        }else{
            cout << "You’re a coastal aircraft, Robbie, a large silver aircraft.\n";
        }

    }
    return 0;
}