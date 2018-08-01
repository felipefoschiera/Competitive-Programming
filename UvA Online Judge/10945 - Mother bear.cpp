// UvA 10945 - Mother bear
// Felipe G. Foschiera
#include <iostream>
using namespace std;

int main(){
    string s;
    while(getline(cin, s)){
        if(s == "DONE") break;    
        string nova = "";
        for(auto c : s) if(isalpha(c)) nova += tolower(c);
        int sz = nova.length();
        int st = 0, end = sz - 1;
        bool ok = true;
        while(end >= st)
            if(nova[st++] != nova[end--]) ok = false;

        cout << (ok ? "You won't be eaten!" : "Uh oh..") << '\n';

    }
    return 0;
}