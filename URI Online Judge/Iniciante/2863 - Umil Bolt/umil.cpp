#include <cstdio>

int main(){
    int T;
    while(scanf("%d", &T) != EOF){
        double smallest = 12.0, f;
        while(T--){
            scanf("%lf", &f);
            if(f < smallest) smallest = f;
        }
        printf("%.2lf\n", smallest);
    }
    return 0;
}