#include <stdio.h>
#include <bitset>
#include <string>
using namespace std;

int tom[] = {0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0};
string notas[] = {"do", "do#", "re", "re#", "mi", "fa", "fa#", "sol", "sol#", "la", "la#", "si"};

int main(){
    int N, v;
    scanf("%d", &N);
    bitset<12> bs;
    while(N--){
        scanf("%d", &v);
        v--;
        bs[v%12] = 1;
    }
    int ans = -1;
    for(int i = 0; i < 12; i++){
        bool ok = true;
        for(int j = 0; j < 12; j++){
            if(bs[(i+j)%12] && tom[j]){
                ok = false;
            }
        }
        if(ok){ ans = i; break; }
    }
    printf("%s\n", ans == -1 ? "desafinado" : notas[ans].c_str());

    return 0;   
}