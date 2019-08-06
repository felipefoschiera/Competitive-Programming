#include <stdio.h>
using namespace std;

double f(int n){
    return (n == 1 ? 1.0 : 0.5);
}

double g(int n){
    double res = 0.0;
    for(int i = 1; i <= n; i++){
        res += f(i) / n;
    }
    return res;
}
int main(){
    /*  
     *  f(n) = 1/n + somatorio de i=2 a n-1 f(i)/n
     *  dá sempre 0.5
     */
    /*
        g(n) = somatorio de i=1 a n f(i)/n
    */
    int t;
    scanf("%d", &t);
    for(int tc = 1; tc <= t; tc++){
        int n, m;
        scanf("%d %d", &n, &m);
        printf("Case #%d: %.6f %.6f\n", tc, f(n), g(m));
        
        
    }
    return 0;
}