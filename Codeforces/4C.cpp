// Codeforces 4C - Registration system
// Felipe G. Foschiera
#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int N;
    while(cin >> N){
        string s;
        unordered_map<string, int> hash;
        while(N--){
            cin >> s;
            if(hash.find(s) == hash.end()){
                cout << "OK\n";
                hash[s] = 0;
            }else{
                hash[s]++;
                string nova = s + to_string(hash[s]);
                cout << nova << '\n';
            }

        }
    }
    return 0;
}