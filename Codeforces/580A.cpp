// Codeforces 580A - Kara and First Steps
// Felipe G. Foschiera
#include <cstdio>

const int MAX = 101010;

int A[MAX];

inline int max(int a, int b) { return a > b ? a : b; }

int main(){
    int N;
    while(scanf("%d", &N) != EOF){
        for(int i = 0; i < N; i++)
            scanf("%d", &A[i]);
        int max_len = 1, cur_len = 1;
        for(int i = 1; i < N; i++){
            if(A[i] >= A[i-1]){
                cur_len++;
                max_len = max(max_len, cur_len);
            }else cur_len = 1;
        }
        printf("%d\n", max_len);
    }
    return 0;
} 