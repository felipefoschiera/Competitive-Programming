/**
 *  Seletiva UFFS 2018 - URI Online Judge
 *  Felipe G. Foschiera
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<string, int> si;
vector<string> lowers;

bool compare(si a, si b){
    if(lowers[a.second] < lowers[b.second]){
        return 1;
    }else if(lowers[a.second] == lowers[b.second]){
        return a.first < b.first;
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    string s;
    vector<si> strs;
    for(int i = 0; i < n; i++){
        cin >> s;
        string low = "";
        for(int i = 0; i < s.length(); i++) low += tolower(s[i]);
        lowers.push_back(low);
        strs.push_back(si(s, i));
    }
    sort(strs.begin(), strs.end(), compare);
    for(auto s : strs){
        cout << s.first << endl;
    }

    return 0;
}