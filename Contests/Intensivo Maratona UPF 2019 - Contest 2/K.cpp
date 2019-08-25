#include <bits/stdc++.h>
using namespace std;

struct pt {
    int x, y;
    pt() { x = y = 0;}
    bool operator < (const pt other) const {
        return x < other.x;
    }
};

pt pts[3123];

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> pts[i].x >> pts[i].y;
    }
    sort(pts, pts+n);
    int res = 0;
    for(int i = 0; i < n; i++){
        int maxy = 1e9, miny = -1e9;
        for(int j = i+1; j < n; j++){
            if(pts[j].y > pts[i].y && pts[j].y < maxy){
                res++;
                maxy = pts[j].y;
            }else if(pts[j].y < pts[i].y && pts[j].y > miny){
                res++;
                miny = pts[j].y;
            }
        }
    }
    cout << res << '\n';
    return 0;
}