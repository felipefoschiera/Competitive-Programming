#include <stdio.h>
#include <set>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

struct circle {
    double x, y, r;
    bool operator < (const circle other) const {
        if(r != other.r)
            return r < other.r;
        if(x != other.x)
            return x < other.x;
        return y < other.y;
    }
    bool intersects(circle other){
        double centerDist = (x-other.x)*(x-other.x) + (y-other.y)*(y-other.y);
        return (r-other.r)*(r-other.r) <= centerDist && centerDist <= (r+other.r)*(r+other.r);
    }
};

const int MAXN = 150150;

circle C[MAXN];
vector<int> adj[MAXN];

int n, res = 0;

void dfs(int orig, int v){
    if(!C[orig].intersects(C[v]))
        return;
    res += 2;
    if(res > 2*n){
        return;
    }
    for(auto x : adj[v])
        dfs(orig, x);
    
}


int main(){
    scanf("%d", &n);
    double x, y, r;
    for(int i = 0; i < n; i++){
        scanf("%lf %lf %lf", &C[i].x, &C[i].y, &C[i].r);
    }
    sort(C, C+n);
    set<int> in;
    for(int i = 0; i < n; i++){
        for(auto inside : in){
            if(C[i].intersects(C[inside])){
                dfs(i, inside);
            }else{
                adj[i].push_back(inside);
            }
        }
        for(auto x : adj[i])
            in.erase(x);
        in.insert(i);
    }
    if(res > 2*n){
        printf("greater\n");
    }else printf("%d\n", res);
    return 0;
}