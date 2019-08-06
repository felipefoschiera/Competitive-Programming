#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

vector<int> adj[110];
string beverage[110];
int incomingDeg[110];

map<string, int> id;
vector<int> ts;

void kahn(int n){
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < n; i++)
        if(incomingDeg[i] == 0) pq.push(i);
    
    while(!pq.empty()){
        int u = pq.top();
        pq.pop();
        ts.push_back(u);
        for(auto v : adj[u]){
            incomingDeg[v]--;
            if(incomingDeg[v] == 0) pq.push(v);
        }
    }
}

int main(){
    int n, tc = 1;
    while(cin >> n){
        string s, a, b;
        int cntr = 0,  m;
        ts.clear(); id.clear();
        for(int i = 0; i < n; i++){
            adj[i].clear();
            incomingDeg[i] = 0;
        }
        for(int i = 0; i < n; i++){
            cin >> s;
            id[s] = cntr;
            beverage[cntr++] = s;
        }
        cin >> m;
        while(m--){
            cin >> a >> b;
            adj[id[a]].push_back(id[b]);
            incomingDeg[id[b]]++;
        }
        kahn(n);
        cout << "Case #" << tc++ << ": Dilbert should drink beverages in this order: ";
        for(int k = 0; k < ts.size(); k++){
            cout << beverage[ts[k]] << (k==ts.size()-1 ? "." : " ");
        }
        cout << "\n\n";
    }
    return 0;
}