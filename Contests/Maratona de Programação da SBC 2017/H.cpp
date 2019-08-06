#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#define EPS 1e-5
#define INF ((int)1e9)
using namespace std;

typedef vector<int> vi;


struct pt {
    int x, y;
    pt() { x = y = 0;}
    pt(int _x, int _y): x(_x), y(_y) {}
    pt operator - (pt other) const {
        return pt(x - other.x, y - other.y);
    }
};

double cross(pt p1, pt p2){
    return p1.x * p2.y - p1.y * p2.x;
}

double distance(pt a, pt b){
    return hypot(a.x-b.x, a.y-b.y);
}

struct triangle {
    pt a, b, c;
    triangle() { a = b = c = pt(); }
    triangle(pt _a, pt _b, pt _c): a(_a), b(_b), c(_c) {}
    
    // 0 - inside, 1 - border, 2 - outside

    int isInside(pt p){
        double u = cross(b-a, p-a) * cross(b-a, c-a);
        double v = cross(c-b, p-b) * cross(c-b, a-b);
        double w = cross(a-c, p-c) * cross(a-c, b-c);
        if(u > 0.0 && v > 0.0 && w > 0.0) return 0;
        if(u < 0.0 || v < 0.0 || w < 0.0) return 2;
        else return 1;
    }
};

bool inside(pt u, triangle t){
    return t.isInside(u) != 2;
}



vector<vi> buildAdjList(int N, vector<pt> pts, pt A, pt B, vi &arr){
    vector<vi> LG(N, vi());
    arr.assign(N, 0);
    for(int u = 0; u < N; u++)  
        for(int w = u+1; w < N; w++){
            if(inside(pts[w], triangle(A, B, pts[u]))){
                LG[u].push_back(w);
                arr[w]++;
            }
        }
    return LG;
}

vi toposort(const vector<vi> &LG, vi arr, int N){
    vi ts;
    priority_queue<int, vector<int>, greater<int> > Q;
    for(int u = 0; u < N; u++) if(!arr[u]) Q.push(u);
    while(!Q.empty()){
        int u = Q.top(); Q.pop();
        ts.push_back(u);
        for(auto v : LG[u]){
            if(!(--arr[v])) Q.push(v);
        }
    }
    return ts;
}

bool compy(const pt &a, const pt &b) { return a.y > b.y; }

int solve(int N, vector<pt> &pts, const pt &A, const pt &B){
    sort(pts.begin(), pts.end(), compy);
    vector<int> arr;
    vector<vi> LG = buildAdjList(N, pts, A, B, arr);
    vi ts = toposort(LG, arr, N);
    vi dist(N, -INF);
    for(int i = 0; i < N; i++) if(arr[ts[i]] == 0) dist[ts[i]] = 1;
    for(int i = 0; i < N; i++){
        int u = ts[i];
        for(auto v : LG[u])
            if(dist[v] < dist[u] + 1) dist[v] = dist[u] + 1;    
    }
    int best = 0;
    for(int i = 0; i < N; i++) best = max(best, dist[i]);
    return best;
}


int main(){
    int N, A, B;
    while(scanf("%d %d %d", &N, &A, &B) != EOF){
        vector<pt> pts(N, pt());
        for(int i = 0; i < N; i++) scanf("%d %d", &pts[i].x, &pts[i].y);
        printf("%d\n", solve(N, pts, pt(A, 0), pt(B, 0)));
    }
    return 0;
}