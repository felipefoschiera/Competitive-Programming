#include <iostream>
#include <string.h>
#include <vector>
#define MAX 1112
using namespace std;
typedef vector<int> vi;

int ks[MAX], ks2[MAX];
int knapsack(int W, vi wt, vi v, int n){
    memset(ks, 0, sizeof ks); 
    memset(ks2, 0, sizeof ks2);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= W; j++)
            if(j - wt[i-1] >= 0)
                ks2[j] = max(ks[j], ks[j-wt[i-1]] + v[i-1]);
        for(int j = 1; j <= W; j++)
            ks[j] = ks2[j];
    }
    return ks[W];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N, R;
    while(cin >> N >> R){
        int x, y;
        char z;
        vi bc, bg, cg;
        vi p_bc, p_bg, p_cg;
        for(int i = 0; i < N; i++){
            cin >> x >> z >> y;
            if(z == 'B'){
                bc.push_back(x);
                bg.push_back(x);
                p_bc.push_back(y);
                p_bg.push_back(y);
            }
            if(z == 'C'){
                bc.push_back(x);
                cg.push_back(x);
                p_bc.push_back(y);
                p_cg.push_back(y);
            }
            if(z == 'G'){
                bg.push_back(x);
                cg.push_back(x);
                p_bg.push_back(y);
                p_cg.push_back(y);
            }
        }
        int ans = max(knapsack(R, p_bc, bc, bc.size()), max(knapsack(R, p_bg, bg, bg.size()), knapsack(R, p_cg, cg, cg.size())));
        cout << ans << '\n';
    }

    return 0;
}
