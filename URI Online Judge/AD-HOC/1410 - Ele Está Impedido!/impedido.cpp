#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    int A, D;
    while(scanf("%d %d", &A, &D), (A+D)){
        int ataq[A], def[D];
        for(int i = 0; i < A; i++) scanf("%d", ataq+i);
        for(int i = 0; i < D; i++) scanf("%d", def+i);
        sort(ataq, ataq+A);
        sort(def, def+D);
        int closest_attacker = ataq[0];
        int def1 = def[0], def2 = def[1];
        bool impedido = false;
        if(closest_attacker < def2) impedido = true;
        if(closest_attacker == def1 && def1 == def2) impedido = false;
        printf("%s\n", impedido ? "Y" : "N");

    }
    return 0;
}