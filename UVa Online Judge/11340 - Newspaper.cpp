// UvA 11340 - Newspaper
// Felipe G. Foschiera
#include <iostream>
#include <iomanip>
#include <unordered_map>
using namespace std;


int main(){
    int T;
    cin >> T;
    while(T--){
        unordered_map<char, int> preco;
        int n;
        cin >> n;
        while(n--){
            char c;
            int v;
            cin >> c >> v;
            preco[c] = v;
        }
        cin >> n;
        int cost = 0;
        cin.ignore();
        while(n--){
            string s;
            getline(cin, s);
            for(int i = 0; i < (int)s.length(); i++)
                if(preco[s[i]]) cost += preco[s[i]];
        }
        double prec = (double) cost / 100.0;
        cout << fixed << setprecision(2) << prec << "$\n";
            }
    return 0;
}