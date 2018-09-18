#include <cstdio>

inline int abs(int i) { return i < 0 ? -i : i; }

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int a, b, res;
        char op;
        scanf("%d %c %d %*c %d", &a, &op, &b, &res);
        int right;
        if(op == '+')
            right = a + b;
        else if(op == '-')
            right = a - b;
        else if(op == 'x')
            right = a * b;
        int diff = abs(right - res);
        printf("E");
        while(diff--) printf("r");
        printf("ou!\n");
    }
    return 0;
}