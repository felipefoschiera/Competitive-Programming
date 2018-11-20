#include <cstdio>
#include <cmath>


int main(){
    int a, b, c;
    while(scanf("%d %d %d", &a, &b, &c) != EOF){
        double semi, areaTriangulo, raioCirculo, areaCirculo;
        semi = (a+b+c) / 2.0;
        areaTriangulo = sqrt(semi*(semi-a)*(semi-b)*(semi-c));
        raioCirculo = areaTriangulo / semi;
        areaCirculo = raioCirculo * raioCirculo * M_PI;
        double raioMaior = a*b*c / (4.0*areaTriangulo), areaMaior;
        areaMaior = M_PI * raioMaior * raioMaior;
        printf("%.4lf %.4lf %.4lf\n", areaMaior-areaTriangulo, areaTriangulo-areaCirculo, areaCirculo);
    }
    return 0;
}