/**
 *  URI 1982 - Novos Computadores
 *  Felipe G. Foschiera
 */
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct Point {
    int x, y;
};

double distance(Point a, Point b){
    return hypot(a.x - b.x, a.y - b.y);
}

/**
 *  0 - colinear, 1 - clockwise, 2 - counterclockwise
 */
int orientation(Point p, Point q, Point r){
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);
    if(val == 0) return 0;
    return (val > 0) ? 1 : 2;
}

void convexHull(Point points[], int n){
    if(n < 3) return;
    vector<Point> hull;

    int l = 0;
    for(int i = 1; i < n; i++){
        if(points[i].x < points[l].x)
            l = i;
    }
    
    int p = l, q;
    do{
        hull.push_back(points[p]);
        q = (p+1) % n;
        for(int i = 0; i < n; i++){
            if(orientation(points[p], points[i], points[q]) == 2)
                q = i;
            
        }
        p = q;
    }while(p != l);
    double dist = 0;
    int size = hull.size();
    for(int i = 1; i < size; i++){
        dist += distance(hull[i], hull[i-1]);
    }
    dist += distance(hull[0], hull[size-1]);
    printf("Tera que comprar uma fita de tamanho %.2lf.\n", dist);
}

int main(){
    int n;
    while(scanf("%d", &n) && n){
        Point points[n];
        for(int i = 0; i < n; i++){
            scanf("%d %d", &points[i].x, &points[i].y);
        }
        convexHull(points, n);
    }
   
    return 0;
}