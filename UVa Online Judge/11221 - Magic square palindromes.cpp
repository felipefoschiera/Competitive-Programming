// UvA 11221 - Magic square palindromes.
// Felipe G. Foschiera
#include <iostream>
#include <math.h>
using namespace std;

bool isPerfectSquare(int n){
    int raiz = sqrt(n);
    return raiz*raiz == n;
}

int main(){
    int T;
    cin >> T;
    cin.ignore();
    for(int t = 1; t <= T; t++){
        string s;
        getline(cin, s);
        string nova = "";
        for(auto c : s) if(isalpha(c)) nova += c;
        int sz = nova.length();
        bool palindrome = true;
        int st = 0, end = sz - 1;
        while(end >= st)
            if(nova[st++] != nova[end--]) palindrome = false;
        int raiz = sqrt(sz);

        cout << "Case #" << t << ":\n";
        if(palindrome && isPerfectSquare(sz)) cout << raiz << '\n';
        else cout << "No magic :(\n";
    }
    return 0;
}