#include <bits/stdc++.h>
using namespace std;

string um = "adgjmptw ";
string dois = "behknqux";
string tres = "cfilorvy";
string quatro = "sz";

bool inStr(char c, string &s){
    for(char x : s){
        if(c == x) return true;
    }
    return false;
}

int main(){
    int t;
    cin >> t;
    cin.ignore();
    for(int tc = 1; tc <= t; tc++){
        string s;
        getline(cin, s);
        int res = 0;
        for(auto c :s){
            if(inStr(c, um)) res++;
            else if(inStr(c, dois)) res += 2;
            else if(inStr(c, tres)) res += 3;
            else if(inStr(c, quatro)) res += 4;
        }
        cout << "Case #" << tc << ": " << res << '\n';
    }
    return 0;
}