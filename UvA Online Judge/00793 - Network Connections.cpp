// UVa 00793 - Network Connections
// Felipe G. Foschiera
// chato pra caralho de ler esse input vai toma no cy
#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;

class UnionFind {
private:
    vi p, rank;
public:
    UnionFind(int N){
        p.assign(N, 0);
        rank.assign(N, 0);
        for(int i = 0; i < N; i++) p[i] = i;
    }
    int findSet(int i) { return (p[i] == i ? i : p[i] = findSet(p[i])); }
    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
    void unionSet(int i, int j){
        if(!isSameSet(i, j)){
            int x = findSet(i), y = findSet(j);
            if(rank[x] > rank[y]) p[y] = x;
            else {
                p[x] = y;
                if(rank[x] == rank[y]) rank[y]++;
            }
        }
    }
};

int main(){
    int T; 
    cin >> T;
    for(int t = 0; t < T; t++){
        int N; 
        cin >> N;
        cin.ignore();
        UnionFind uf(N);
        char op; int i, j;
        string s;
        int success = 0, failed = 0;
        while(true){
            if(!getline(cin, s) || s.empty()) break;
            sscanf(s.c_str(), "%c %d %d", &op, &i, &j);
            i--, j--;
            if(op == 'c'){
             uf.unionSet(i, j);
            }
            else if(op == 'q'){
                if(uf.isSameSet(i, j)) success++;
                else failed++;
            }
        }
        if(t != 0) cout << '\n';
        cout << success << ',' << failed << '\n';
    }
    return 0;
}