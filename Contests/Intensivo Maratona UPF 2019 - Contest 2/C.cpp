#include <bits/stdc++.h>
using namespace std;

map<char, char> rel;

int main(){
    string str;
    rel['C'] = 'F';
    rel['F'] = 'C';
    rel['S'] = 'B';
    rel['B'] = 'S';
    while(cin >> str){
        stack<char> s; int res = 0;
        for(char x : str){
            if(!s.empty() && s.top() == rel[x]){
                res++;
                s.pop();
            }else{
                s.push(x);
            }
        }
        cout << res << '\n';
    }
    return 0;
}