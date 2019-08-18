#include <bits/stdc++.h>
using namespace std;


#define EPS (1e-9)

struct point {
    int x, y;
    point() { x = y = 0; }
    point(int _x, int _y) : x(_x), y(_y) {}
    
    bool operator == (point other) const {
        return x == other.x && y == other.y;
    }
    
    point operator - (point other) const {
        return point(x - other.x, y - other.y);
    }
    
    bool operator < (point other) const {
        if(x != other.x)
            return x < other.x;
        return y < other.y;
    }
};



double dist(point p1, point p2){
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

point pivot(0, 0);

double inner(point p1, point p2){
    return p1.x * p2.x + p1.y * p2.y;
}

double cross(point p1, point p2){
    return p1.x * p2.y - p1.y * p2.x;
}   

int leftmostIndex(vector<point> &P){
    int ans = 0;
    for(int i = 1; i < (int)P.size(); i++){
        if(P[i] < P[ans]) ans = i;
    }
    return ans;
}

bool ccw(point p, point q, point r){
    return cross(q-p, r-p) > 0;
}

bool collinear(point p, point q, point r){
    return cross(p-q, r-p) == 0;   
}


bool angleCmp(point a, point b){
    if(collinear(pivot, a, b))
        return inner(pivot-a, pivot-a) < inner(pivot-b, pivot-b);
    return cross(a-pivot, b-pivot) >= 0;
}

vector<point> convexHull(vector<point> P){
    int i, j, n = (int)P.size();
    if(n <= 2) return P;
    int P0 = leftmostIndex(P);
    swap(P[0], P[P0]);
    pivot = P[0];
    sort(++P.begin(), P.end(), angleCmp);
    vector<point> S;
    S.push_back(P[n-1]);
    S.push_back(P[0]);
    S.push_back(P[1]);
    for(i = 2; i < n;){
        j = (int)S.size()-1;
        if(ccw(S[j-1], S[j], P[i])) S.push_back(P[i++]);
        else S.pop_back();
    }
    
    reverse(S.begin(), S.end());
    S.pop_back();
    reverse(S.begin(), S.end());
    return S;
}

double angle(point a, point o, point b){
    return acos(inner(a-o, b-o) / (dist(o, a) * dist(o, b)));
}

bool between(point p, point q, point r){
    return collinear(p, q, r) && inner(p - q, r - q) <= 0;
}


bool inPolygon(point p, vector<point> &P){
    if(P.size() == 0) return false;
    double sum = 0.0;
    int n = P.size();
    for(int i = 0; i < n; i++){
        if(P[i] == p || between(P[i], p, P[(i+1)%n]))
            return true;
        if(ccw(p, P[i], P[(i+1)%n])) sum += angle(P[i], p, P[(i+1)%n]);
        else sum -= angle(P[i], p, P[(i+1)%n]);  
    }
    return fabs(fabs(sum) - 2*acos(-1.0)) < EPS;
}

int main(){
    int t;
    scanf("%d", &t);
    for(int tc = 1; tc <= t; tc++){
    
        if(tc != 1) printf("\n");
        int n, m;
        scanf("%d %d", &n, &m);
        vector<point> pts;
        double x, y;
        for(int i = 0; i < n; i++){
            scanf("%lf %lf", &x, &y);
            pts.push_back(point(x, y));
        }
        
        vector<point> polygon = convexHull(pts);
        
        
        printf("Case %d\n", tc);
        for(auto el : polygon){
            printf("%d %d\n", el.x, el.y);
        }
        printf("%d %d\n", polygon[0].x, polygon[0].y);
        
        for(int i = 0; i < m; i++){
            point p;
            scanf("%d %d", &p.x, &p.y);
            printf("%d %d is ", p.x, p.y);
            bool ok = false;
            int m = polygon.size(); 
            for(int i = 0; i < m; i++){
                if(between(polygon[i], p, polygon[(i+1)%m])){
                    printf("safe!\n");
                    ok = true;
                    break;        
                }
            }
            if(!ok){
                bool x = inPolygon(p, polygon);
                if(x) printf("unsafe!\n");
                else printf("safe!\n");
           }
        }
    
    }
    return 0;
}