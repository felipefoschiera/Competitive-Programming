#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

const int MAX = 101010;

int p[MAX], rnk[MAX], setSize[MAX];

int findSet(int x){
    return p[x] == x ? x : p[x] = findSet(p[x]);
}

bool isSameSet(int x, int y){
    return findSet(x) == findSet(y);
}

void unionSet(int x, int y){
    if(!isSameSet(x, y)){
        int i = findSet(x), j = findSet(y);
        if(rnk[i] > rnk[j]){
            p[j] = i;
            setSize[i] += setSize[j];
        }else{
            p[i] = j;
            setSize[j] += setSize[i];
            if(rnk[i] == rnk[j]) rnk[j]++;
        }
    }
}

int main(){
    int t; cin >> t;
    while(t--){
        for(int i = 0; i < MAX; i++){
            p[i] = i;
            rnk[i] = 0;
            setSize[i] = 1;
        }
        int ident = 0;
        unordered_map<string, int> id;
        int f; cin >> f;
        string a, b;
        while(f--){
            cin >> a >> b;
            if(id.find(a) == id.end())
                id[a] = ident++;
            if(id.find(b) == id.end())
                id[b] = ident++;
            unionSet(id[a], id[b]);
            cout << setSize[findSet(id[a])] << "\n";
        }
    }
    return 0;
}