/**
 *  URI 2177 - Rio 2016
 *  Felipe G. Foschiera
 */ 
#include <stdio.h>
#include <cmath>
#include <vector>
using namespace std;

double distance(int x, int y, int x1, int y1){
    return hypot(x-x1, y-y1);
}


int main(){
    int x, y, n;
    scanf("%d %d %d", &x, &y, &n);
    int xi, yi, ti;
    vector<int> consegue;
    for(int i = 1; i <= n; i++){
        scanf("%d %d %d", &xi, &yi, &ti);
        double dist = distance(x, y, xi, yi);
        if(dist < ti) consegue.push_back(i);
    }
    if(consegue.size() > 0){
        for(int i = 0; i < consegue.size(); i++){
            if(i != consegue.size() - 1){
                printf("%d ", consegue[i]);
            }else{
                printf("%d\n", consegue[i]);
            }
        }
    }else{
        printf("-1\n");
    }

    return 0;
}