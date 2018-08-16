#include <cstdio>
#include <vector>
using namespace std;

typedef vector<int> vi;

int testa(vi v, int m){
    int ind = 0;
    vi temp = v;
    while((int)temp.size() > 1){
        if(temp[ind] == 13) return testa(v, m+1);
        temp.erase(temp.begin() + ind);
        ind = (ind + m - 1) % (int)temp.size();
    }
    if(temp[0] == 13) return m;
    return 0;
}


int main(){
    int N;
    while(scanf("%d", &N), N){
        vi v(N);
        for(int i = 0; i < N; i++) v[i] = i+1;
        printf("%d\n", testa(v, 1));
    }
    return 0;
}