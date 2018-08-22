#include <cstdio>
#include <vector>
#include <algorithm>
#define MAX 101
using namespace std;

int main(){
    int N;
    while(scanf("%d", &N) != EOF){
        vector<vector<int>> ocur;
        ocur.assign(MAX, vector<int>());
        int v[N];
        for(int i = 0; i < N; i++){
            scanf("%d", v+i);
            ocur[v[i]].push_back(i);
        }
        for(int i = 0; i < N; i++){
            int lowest_ind = N+1, best_el = -1;
            for(int k = v[i]+1; k <= 100; k++){
                auto it = upper_bound(ocur[k].begin(), ocur[k].end(), i);
                if(it == ocur[k].end()) continue;
                if(*it < lowest_ind) { lowest_ind = *it; best_el = k; }
            }
            if(lowest_ind != N+1) printf("%d", best_el);
            else printf("*");
            printf("%c", i == N - 1 ? '\n' : ' ');
        }
        

    }
    return 0;
}