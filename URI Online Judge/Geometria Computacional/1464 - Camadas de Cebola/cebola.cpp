/**
 *  URI 1464 - Camadas de Cebola
 *  Felipe G. Foschiera
 */
#include <stdio.h>
#include <vector>
using namespace std;

struct Point{
    int x, y;
};

int orientation(Point p, Point q, Point r){
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);
    if(val == 0) return 0;
    return (val > 0) ? 1 : 2;
}

int camadas;

void convexHull(Point points[], int n){
    if(n < 3) return;
    vector<Point> hull;
    vector<int> inHull(n, 0);
    int l = 0;
    for(int i = 1; i < n; i++){
        if(points[i].x < points[l].x)
            l = i;
    }
    int p = l, q;
    do{
        hull.push_back(points[p]);
        q = (p+1) % n;

        inHull[p] = 1;
        for(int i = 0; i < n; i++){
            if(orientation(points[p], points[i], points[q]) == 2){
                q = i;
            }
        }
        p = q;
    }while(p != l);
    int next = n - hull.size();
    Point nextPts[next]; 
    int cnt = 0;   
    for(int i = 0; i < n; i++){
        if(inHull[i] == 0){
            nextPts[cnt] = points[i];
            cnt++;
        }
    }
    camadas++;
    convexHull(nextPts, next);
}

int main(){
    int N;
    while(scanf("%d", &N) && (N)){
    Point points[N];
    for(int i = 0; i < N; i++){
        scanf("%d %d", &points[i].x, &points[i].y);
    }
    camadas = 0;
    convexHull(points, N);
    printf((camadas&1) ? "Take this onion to the lab!\n" : "Do not take this onion to the lab!\n");
}
    return 0;
}