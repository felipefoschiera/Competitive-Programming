#include <stdio.h>
#include <vector>
using namespace std;
typedef vector<int> vi;

vi visited;
vector<vi> LG;
bool cycle = false;

void dfs(int s){
    visited[s] = 1;
    if(cycle) return;
    for(auto v : LG[s]){
        if(visited[v] == 1){
            cycle = true; return;
        }else if(!visited[v]){
            dfs(v);
        }
    }
    visited[s] = 2;
}
