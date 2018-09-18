#include <iostream>
using namespace std;

int main(){
    int n;
    while(cin >> n){
        string s;
        while(n--){
            cin >> s;
            char c = stoi(s, nullptr, 2);
            cout << c;
        }
        cout << '\n';
    }
    return 0;
}