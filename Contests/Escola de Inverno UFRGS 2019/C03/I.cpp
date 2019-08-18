#include <stdio.h>
#include <vector>
using namespace std;

typedef vector<int> vi;

vector<vi> LG; 
vi toposort;
vi vis;
bool cyc;

void ts(int u){
    vis[u] = true;
    if(cyc) return;
    for(int v : LG[u]){
        if(vis[v] == 1){
            cyc = true; return;
        }
        else if(!vis[v]){
            ts(v);
        }
    }
    toposort.push_back(u);
    vis[u] = 2;
}

int main(){
    int e, u, v;
    char s[8];
    while(scanf("%s ", s) != EOF){
        LG.assign(5, vi());
        for(e = 0; e < 5; e++){
            if(e) scanf("%s ", s);
            u = s[0] - 'A';
            v = s[2] - 'A';
            if(s[1] == '<'){
                swap(u, v); 
            }
            LG[u].push_back(v);
        }
        cyc = false;
        toposort.clear();
        vis.assign(5, 0);
        for(int u = 0; u < 5 && !cyc; u++){
            if(!vis[u]) ts(u);
        }
        if(cyc){
            printf("impossible\n");
        }
        else{
            for(int i = 0; i < 5; i++){
                putchar(toposort[i] + 'A');
            }
            putchar('\n');
        }
    }
    return 0;
}