#include <stdio.h>

int main(){
    double pi = 3.1415;
    int r, l;
    scanf("%d %d", &r, &l);
    double v = (4.0/3.0) * (pi * (double)(r * r * r));
    printf("%d\n", (int)l / (int)v);
    return 0;
}