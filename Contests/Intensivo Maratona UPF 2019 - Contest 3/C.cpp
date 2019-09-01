#include <bits/stdc++.h>
using namespace std;

const int K = 26;

struct Vertex {
    int next[K];
    bool leaf = false;

    Vertex() {
        for(int i = 0; i < K; i++) next[i] = -1;
    }
};

vector<Vertex> trie;


void add_string(string const& s){
    int v = 0;
    for(char ch : s){
        int c = ch - 'a';
        if(trie[v].next[c] == -1){
            trie[v].next[c] = trie.size();
            trie.push_back(Vertex());
        }else{
        }
        v = trie[v].next[c];
    }
    trie[v].leaf = true;
}

int find(string const& s){
    int v = 0, res = 1;
    int m = s.size();
    for(int x = 0; x < m; x++){
        int c = s[x] - 'a';
        v = trie[v].next[c];   
        int caminhos = 0;
        for(int i = 0; i < K; i++){
            if(trie[v].next[i] != -1){
                caminhos++;
            }
        }
        if(trie[v].leaf && x == m-1){
            return res;
        }
        if(caminhos > 1 || (caminhos == 1 && trie[v].leaf && x < m-1)){
            res++;
        }
    }
    return res;
}


int main(){
    int n;
    vector<string> strs;
    while(cin >> n){
        strs.clear();
        trie.clear();
        trie.push_back(Vertex());
        string s;
        for(int i = 0; i < n; i++){
            cin >> s;
            strs.push_back(s);
            add_string(s);
        }
        int r = 0;
        for(int i = 0; i < n; i++){
            int x = find(strs[i]);
            r += x;
        }
        double res = (double) r / n;
        cout << fixed << setprecision(2) << res << '\n';
        

    }
    return 0;
}