#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N;
    while(cin >> N){
            cin.ignore();
        while(N--){
            string s, nova = "";
            getline(cin, s);
            int sz = s.length();
            for(int i = 0; i < sz; i++){
                if(isalpha(s[i])){
                    int pos = s[i]+3;
                    s[i] = (char)pos;
                }
            }
            reverse(s.begin(), s.end());
            int mid = sz / 2;
            for(int i = mid; i < sz; i++){
                int pos = s[i]-1;
                s[i] = (char) pos;
            }
            cout << s << '\n';
        }
    }
    return 0;
}