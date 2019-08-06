#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int n;
int x[10], y[10];

double dist(int i, int j){
    return hypot(x[i]-x[j], y[i]-y[j]);
}

int main(){
    int tc = 1;
    while(scanf("%d", &n), n){
        vector<int> comp;
        for(int i = 0; i < n; i++){
            scanf("%d %d", &x[i], &y[i]);
            comp.push_back(i);
        }
        vector<int> res;
        double bestCost = 1e16;
        do {
            double cost = 0.0;
            for(int i = 0; i < n-1; i++)
                cost += dist(comp[i], comp[i+1])+16.0;
            if(cost < bestCost){
                bestCost = cost;
                res = comp;
            }
        }while(next_permutation(comp.begin(), comp.end()));

        printf("**********************************************************\n");
        printf("Network #%d\n", tc++);
        for(int i = 0; i < n-1; i++){
            printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n", x[res[i]], y[res[i]], x[res[i+1]], y[res[i+1]], dist(res[i], res[i+1])+16.00);
        }
        printf("Number of feet of cable required is %.2lf.\n", bestCost);
    }
    return 0;
}