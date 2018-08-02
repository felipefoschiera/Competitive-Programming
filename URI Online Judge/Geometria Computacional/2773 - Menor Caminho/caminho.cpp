#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;


struct point{
    long long x, y;
    point(){
        x = y = 0;
    }
    point(long long _x, long long _y): x(_x), y(_y) {}
};

double distance(point a, point b){
    return hypot(a.x - b.x, a.y - b.y);
}


int main(){
    ios_base::sync_with_stdio(false);
    long long Xi, Yi, Xf, Yf, V, Xl, Yl, Xr, Yr;
    while(cin >> Xi >> Yi >> Xf >> Yf >> V){
        point inicio, fim, v1, v2, v3, v4;        
        inicio = point(Xi, Yi);
        fim = point(Xf, Yf);

        cin >> Xl >> Yl >> Xr >> Yr;

        v1 = point(Xl, Yl);
        v2 = point(Xr, Yr);
        v3 = point(Xr, Yl);
        v4 = point(Xl, Yr);
        double dist_vert1, dist_vert2, d_total_v1, d_total_v2, menor, t;
        dist_vert1 = distance(inicio, v1);
        dist_vert2 = distance(inicio, v4);
        d_total_v1 = dist_vert1 + distance(v1, v3) + distance(v3, fim);
        d_total_v2 = dist_vert2 + distance(v4, v2) + distance(v2, fim);
        menor = min(d_total_v1, d_total_v2);
        t = menor / V;
        cout << fixed << setprecision(1) << t << endl;
    }
    return 0;
}