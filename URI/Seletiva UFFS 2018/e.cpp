/**
 *  Seletiva UFFS 2018 - URI Online Judge
 *  Felipe G. Foschiera
 */
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    map<string, int> freq;
    string s;
    getline(cin, s);
    int sz = s.length();
    for(int i = 0; i < sz-1; i++){
        string token = "";
        token += tolower(s[i]);
        token += tolower(s[i+1]);
        freq[token]++;
    }
    string best;
    int best_freq = 0;
    for(auto v : freq){
        if(v.second > best_freq){
            best_freq = v.second;
            best = v.first;
        }else if(v.second == best_freq){
            if(v.first < best) best = v.first;
        }
    }
    cout << best << ":" << best_freq << endl;
    return 0;
}