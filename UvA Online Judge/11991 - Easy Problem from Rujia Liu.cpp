// UvA 11991 - Easy Problem from Rujia Liu
// Felipe G. Foschiera

#include <stdio.h>
#include <map>
#include <vector>
using namespace std;

int main(){
    int N, M;
    while(scanf("%d %d", &N, &M) != EOF){
        map<int, vector<int> > inds;
        int v;
        for(int i = 1; i <= N; i++){
            scanf("%d", &v);
            inds[v].push_back(i);
        }
        int k;
        while(M--){
            scanf("%d %d", &k, &v);
            if(inds.find(v) != inds.end()){
                if(k > (int)inds[v].size()) printf("0\n");
                else printf("%d\n", inds[v][k-1]); 
            }else printf("0\n");
        }
    }
    return 0;
}