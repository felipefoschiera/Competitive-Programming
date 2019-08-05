#include <stdio.h>
#include <algorithm>
#include <set>
#include <math.h>
using namespace std;

#define px second
#define py first

const int MAX = 10101;
const int INF = 1e9;

typedef pair<double, double> pt;

pt pnts[MAX];

int compare(pt a, pt b){ 
    return a.px < b.px; 
}

double dist(pt a, pt b){
    return hypot(a.px-b.px, a.py-b.py);
}

double closest_pair(int n){
        sort(pnts,pnts+n,compare);
        double best = INF;
        set<pt> box;
        box.insert(pnts[0]);
        int left = 0;
        for (int i = 1; i < n; i++){
            while (left < i && pnts[i].px - pnts[left].px > best)
                box.erase(pnts[left++]);

            for(auto it = box.lower_bound({pnts[i].py - best, pnts[i].px - best}); it != box.end() && pnts[i].py + best >= it->py; ++it)
                best = min(best, dist(pnts[i], *it));

            box.insert(pnts[i]);
        }
        return best;
}
