// Felipe G. Foschiera
// URI 1222 - Concurso de Contos
#include <iostream>
#include <math.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int N, L, C;
    while(cin >> N >> L >> C){
        int cmp_linha = 0, linhas = 1;
        for(int i = 0; i < N; i++){
            string palavra;
            cin >> palavra;
            int tam = palavra.length();
            if(i != N-1 && (tam + cmp_linha != C)) tam++;
            if(tam + cmp_linha <= C) cmp_linha += tam;
            else{
                linhas++;
                cmp_linha = tam;
            } 
        }
        cout << ceil(float(linhas) / float(L)) << endl;

    }

    return 0;
}