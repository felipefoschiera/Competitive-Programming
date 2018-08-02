// UvA 00195 - Anagram
// Felipe G. Foschiera
#include <iostream>
#include <algorithm>
using namespace std;

bool comp(char a, char b){
    return tolower(a) == tolower(b) ? a < b : tolower(a) < tolower(b);
}

int main(){
    int T;
    cin >> T;
    while(T--){
        string s;
        cin >> s;
        sort(s.begin(), s.end(), comp);
        do {
            cout << s << '\n';
        }while(next_permutation(s.begin(), s.end(), comp));
    }
    return 0;
}