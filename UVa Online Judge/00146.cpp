#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    string s;
    while(cin >> s, s != "#"){
        bool nxt = next_permutation(s.begin(), s.end());
        if(nxt) cout << s << "\n";
        else cout << "No Successor\n";
    }
    return 0;
}