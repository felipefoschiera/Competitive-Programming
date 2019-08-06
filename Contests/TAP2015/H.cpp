#include <bits/stdc++.h>
using namespace std;

int cntSort(int n){
    vector<int> cnt(10, 0);
    while(n > 0){
        cnt[n%10]++;
        n /= 10;
    }
    int m = 0;
    for(int i = 0; i < 10; i++){
        while(cnt[i]--){
            m *= 10;
            m += i;
        }
    }
    return m;
}

int main(){
    int n, m;
    while(scanf("%d", &n) != EOF){
        assert(cntSort(321) == 123);
        int cnt = 0;
        while(n != 0){
            m = cntSort(n);
            n -= m;
            cnt++;
        }
        printf("%d\n", cnt);
    }
    return 0;
}