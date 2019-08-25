#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

map<char, ii> pos;
string s1 = "adgjmptw #";
string s2 = "behknqux";
string s3 = "cfilorvy";
string s4 = "sz";

int quadrante(char c){
    ii p = pos[c];
    return p.first + 3 * p.second;
}

ii posquad(int q){
    return {q%3, q/3};
}

double dist(ii a, ii b){
    return hypot(a.first-b.first, a.second-b.second) / 30.0;
}

int moves(char c){
    if(s1.find(c) != string::npos) return 1;
    if(s2.find(c) != string::npos) return 2;
    if(s3.find(c) != string::npos) return 3;
    if(s4.find(c) != string::npos) return 4;
    return 0;
}

void init(){
    for(char c : "abc") pos[c] = {1, 0};
    for(char c : "def") pos[c] = {2, 0};
    for(char c : "ghi") pos[c] = {0, 1};
    for(char c : "jkl") pos[c] = {1, 1};
    for(char c : "mno") pos[c] = {2, 1};
    for(char c : "pqrs") pos[c] = {0, 2};
    for(char c : "tuv") pos[c] = {1, 2};
    for(char c : "wxyz") pos[c] = {2, 2};
    pos[' '] = {1, 3};
    pos['#'] = {2, 3};
}


double pd[400][14][14];

double solve(int idx, vector<char> &movs, int quad1, int quad2){
    if(idx == movs.size()) return 0;
    if(pd[idx][quad1][quad2] != -1.0)
        return pd[idx][quad1][quad2];
    int newqd = quadrante(movs[idx]);
    double d1 = dist(posquad(quad1), posquad(newqd));
    double d2 = dist(posquad(quad2), posquad(newqd));   
    double res = d1 + solve(idx+1, movs, newqd, quad2);
    res = min(res, d2 + solve(idx+1, movs, quad1, newqd));
    return pd[idx][quad1][quad2] = res;
}

int main(){ 
    init();
    string s;
    while(getline(cin, s)){
        int cliques = 0;
        vector<char> vis;
        for(int i = 0; i < s.size(); i++){
            char c = s[i];
            if(i > 0 && pos[c] == pos[s[i-1]]){
                vis.push_back('#');
                cliques += moves('#');
            }
            vis.push_back(c);
            cliques += moves(c);
        }
        double res = cliques * 0.2;
        for(int i = 0; i < 400; i++){
            for(int j = 0; j < 14; j++)
                for(int k = 0; k < 14; k++)
                    pd[i][j][k] = -1.0;
        }
        double r2 = solve(0, vis, quadrante('g'), quadrante('m'));
        res += r2;
        cout << fixed << setprecision(2) << res << '\n';

    }
    return 0;
}