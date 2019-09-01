#include <bits/stdc++.h>
using namespace std;

struct pt {
    int x, y;
    pt() { x = y = 0; }
    pt(int _x, int _y) : x(_x), y(_y) {}
    bool operator < (const pt other) const {
        if(x != other.x) return x < other.x;
        return y < other.y;
    }
};

pt pts[1010];

int pd1[1010], pd2[1010];

int main(){
    int n;
    while(cin >> n){
        for(int i = 0; i < n; i++){
            cin >> pts[i].x >> pts[i].y;
        }
        sort(pts, pts+n);
        for(int i = 0; i < n; i++){
            pd1[i] = 1; pd2[i] = 1; 
            for(int j = 0; j < i; j++){
                if(pts[i].x > pts[j].x){
                    if(abs(pts[i].y - pts[j].y) != 2) continue;
                    if(pts[j].y > pts[i].y && pd1[i] < pd2[j] + 1){
                        pd1[i] = pd2[j] + 1;
                    }else if(pts[j].y < pts[i].y && pd2[i] < pd1[j] + 1){
                        pd2[i] = pd1[j] + 1;
                    }
                }
            }
        }
        int res = 0;
        for(int i = 0; i < n; i++){
            res = max(res, max(pd1[i], pd2[i]));
        }
        cout << res << '\n';
    }
    return 0;
}