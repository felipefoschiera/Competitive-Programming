#include <iostream>
using namespace std;

int main(){
    int n;
    while(cin >> n, n){
        int soma = 0, best = 0, v;
        for(int i = 0; i < n; i++){
            cin >> v;
            soma = max(soma+v, v);
            best = max(best, soma);
        }
        if(best == 0) cout << "Losing streak.\n";
        else cout << "The maximum winning streak is " << best << ".\n";
    }
    return 0;
}