#include <cstdio>

int main(){
    int c;
    scanf("%d", &c);
    while(c--){
        int d;
        scanf("%d", &d);
        printf("%s!\n", d <= 8000 ? "Inseto" : "Mais de 8000");
    }
    return 0;
}