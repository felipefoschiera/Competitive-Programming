#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int a, int b){ return a > b; }

int main(){
    int N, i, tot, ans;
    while(scanf("%d", &N) != EOF){
        tot = 0;
        vector<int> v(N, 0);
        for(i = 0; i < N; i++){
            scanf("%d", &v[i]);
            tot += v[i];
        }
        sort(v.begin(), v.end(), cmp);
        ans = 2;
        if((v[0] * 100) / tot >= 45){
            ans = 1;
        }
        else if((v[0] * 100) / tot >= 40){
            bool has10 = true;
            for(i = 1; i < N && has10; i++)
                if(((v[0] - v[i]) * 100) / tot < 10)
                    has10 = false;
            if(has10) ans = 1;
        }
        printf("%d\n", ans);
    }
    return 0;
}
