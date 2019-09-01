#include <bits/stdc++.h>
using namespace std;

const int MAX = 1010;

struct pt {
    double x, y;
    pt ()  { x = y = 0; }
    pt(double _x, double _y) : x(_x), y(_y) {}

    pt operator - (pt other) const {
        return pt(x - other.x, y - other.y);
    }
    pt operator + (pt other) const {
        return pt(x + other.x, y + other.y);
    }
    pt operator * (double k) const {
        return pt(x * k, y * k);
    }
};

int yi[MAX];
pt pts[MAX];

double dist(pt a, pt b){
    return hypot(a.x - b.x, a.y - b.y);
}

double inner(pt p1, pt p2){
    return p1.x * p2.x + p1.y * p2.y;
}

pt closestToLineSegment(pt p, pt a, pt b){
    double u = inner(p - a, b - a) / inner(b - a, b - a);
    if(u < 0.0) return a;
    if(u > 1.0) return b;
    return a + ((b - a) * u);
}

double distance(pt a, pt b, pt c, pt d){
    
    double res = dist(a, c);
    res = min(res, dist(a, d));
    res = min(res, dist(b, c));
    res = min(res, dist(b, d));
    pt x = closestToLineSegment(b, c, d);
    res = min(res, dist(b, closestToLineSegment(b, c, d)));
    res = min(res, dist(a, closestToLineSegment(a, c, d)));
    res = min(res, dist(c, closestToLineSegment(c, a, b)));
    res = min(res, dist(d, closestToLineSegment(d, a, b)));
    return res;

}

int main(){
    int n;
    while(cin >> n){
        int l, h;
        cin >> l >> h;
        for(int i = 0; i < n; i++){
            cin >> yi[i] >> pts[i].x >> pts[i].y;
        }
        double res = 1e9;

        for(int i = 0; i < n; i++){
            if(i % 2 == 0){
                res = min(res, distance(pt(0, yi[i]), pts[i], pt(l, 0), pt(l, h)));
            }else{
                res = min(res, distance(pt(l, yi[i]), pts[i], pt(0, 0), pt(0, h)));
            }
            if(i > 0){
                if(i % 2 == 0){
                    res = min(res, distance(pt(0, yi[i]), pts[i], pt(l, yi[i-1]), pts[i-1]));
                }else{
                    res = min(res, distance(pt(l, yi[i]), pts[i], pt(0, yi[i-1]), pts[i-1]));
                }
            }
        }
        cout << fixed << setprecision(2) << res << '\n';
    }
    return 0;
}