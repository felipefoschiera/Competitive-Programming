// Codeforces 25A - IQ Test
// Felipe G. Foschiera
#include <cstdio>

int main(){
    int n, v;
    while(scanf("%d", &n) != EOF){
        int par_cnt = 0, impar_cnt = 0;
        int par_ind = -1, impar_ind = -1;
        for(int i = 1; i <= n; i++){
            scanf("%d", &v);
            if(v&1)
                impar_cnt++, impar_ind = i;
            else
                par_cnt++, par_ind = i;
            
        }
        printf("%d\n", (impar_cnt == 1) ? impar_ind : par_ind);
    }
    return 0;
}