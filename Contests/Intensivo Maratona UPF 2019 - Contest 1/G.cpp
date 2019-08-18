#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int cntN = 0, cntI = 0, cntT = 0, cntE = 0;
    for(char c : s){
        if(c == 'n') cntN++;
        if(c == 'i') cntI++;
        if(c == 't') cntT++;
        if(c == 'e') cntE++;
    }
 
    int n;
    if(cntN == 3 || cntN == 4) n = 1;
    else if(cntN < 3) n = 0;
    else {
        n = cntN/2;
        if(cntN % 2 == 0){
            n--;
        }
    }
    
    int best = min(n, cntE/3);
    best = min(best, cntI);
    best = min(best, cntT);
    cout << best << '\n';
    return 0;
}