#include <stdio.h>
#include <string.h>
#include <string>
#include <algorithm>
using namespace std;
#define MAX 112

string rev(string s){
    reverse(s.begin(), s.end());
    return s;
}

bool magical(string s){
    for(int sz = 2; sz <= (int)s.size(); sz++){
        for(int st = 0; st <= (int)s.size()-sz; st++){
            string sub = s.substr(st, st+sz);
            if(s.find(rev(sub)) == string::npos)
                return false;
        }
    }
    return true;
}

int main(){
    int T;
    char s[MAX];
    scanf("%d", &T);
    while(T--){
        scanf(" %s", s);
        printf("%s\n", magical(s) ? "YES" : "NO");
    }
    return 0;
}