// URI 1483 - Jogo do Bicho
// Felipe G. Foschiera
#include <cstdio>

int grupo[26];

void geraGrupo(){
    for(int i = 0, k = 1; i < 25; i++, k += 4){
        grupo[i] = k;
    }
    grupo[25] = 101;
}

bool sameGroup(int a, int b){
    if(a == 0 && b == 0) return true;
    for(int i = 0; i < 25; i++){
        if(a >= grupo[i] && a < grupo[i+1] && b >= grupo[i] && b < grupo[i+1]) return true;
    }
    return false;   
}

int main(){
    geraGrupo();
    double v;
    int n, m;
    while(scanf("%lf %d %d", &v, &n, &m), v+n+m){
        double result;
        if(n % 10000 == m % 10000) result = v * 3000;
        else if(n % 1000 == m % 1000) result = v * 500;
        else if(n % 100 == m % 100) result = v * 50;
        else if(sameGroup(n % 100, m % 100)) result = v * 16;
        else result = 0;
        printf("%.2lf\n", result);
    }
    return 0;
}