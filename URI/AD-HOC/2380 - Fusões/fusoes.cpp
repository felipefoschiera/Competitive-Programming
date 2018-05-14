#include <stdio.h>
#include <vector>
using namespace std;

class UnionFind{
private:
    vector<int> p;
public:
    UnionFind(int N){
        p.assign(N, 0);
        for(int i = 0; i < N; i++)
            p[i] = i;
    }
    int findSet(int i){
        return (p[i] == i) ? i : (p[i] = findSet(p[i]));
    }
    bool isSameSet(int i, int j){
        return findSet(i) == findSet(j);
    }
    void unionSet(int i, int j){
        if(!isSameSet(i, j)){
            int x = findSet(i), y = findSet(j);
            p[x] = j;
        }
    }
};

int main(){
    int N, op;
    scanf("%d %d ", &N, &op);
    char c;
    int a, b;
    UnionFind UF(N);
    while(op--){
        scanf("%c %d %d ", &c, &a, &b);
        a--, b--;
        if(c == 'C')
            printf(UF.isSameSet(a, b) ? "S\n" : "N\n");
        else
            UF.unionSet(a, b);
        
    }
    return 0;
}