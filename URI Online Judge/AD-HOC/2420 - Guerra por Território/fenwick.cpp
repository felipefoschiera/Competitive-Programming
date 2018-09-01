#include <cstdio>
#include <vector>
using namespace std;

class FenwickTree {
private:
    vector<int> ft;
public:
    FenwickTree(int N){
        ft.assign(N+1, 0);
    }
    void update(int k, int v){
        for(; k < (int)ft.size(); k += (k & (-k)))
            ft[k] += v;
    }
    int query(int b){
        int sum = 0;
        for(; b; b -= (b & (-b))) sum += ft[b];
        return sum;
    }
    int query(int a, int b){
        return query(b) - (a == 1 ? 0 : query(a-1));
    }
};

int main(){
    int N;
    while(scanf("%d", &N) != EOF){
        int v[N];
        FenwickTree ft(N);
        for(int i = 1; i <= N; i++){
            scanf("%d", &v[i]);
            ft.update(i, v[i]);
        }
        int secao;
        for(int i = 1; i <= N; i++){
            int fs = ft.query(i);
            int sec = ft.query(i+1, N);
            if(fs == sec) { secao = i; break; }
        }
        printf("%d\n", secao);
    }
    return 0;
}