// URI 1243 - O Quão Fácil é...
// Felipe G. Foschiera
#include <iostream>
using namespace std;

int main(){
    string s;
    while(getline(cin, s)){
        int words = 0, count = 0, cnt = 0;
        int sz = s.length();
        bool hasNum = false, hasPoint = false;
        for(int i = 0; i < sz; i++){
            if(isalpha(s[i])){
                if(!hasNum && !hasPoint) cnt++;
                if(i == sz-1 && cnt > 0) { words++, count += cnt;  }
            }else if(s[i] == '.'){
                if(cnt > 0 && (i == sz-1 || s[i+1] == ' ')) { words++, count += cnt; }
                cnt = 0, hasPoint = true;
            }else if(s[i] == ' '){
                if(cnt > 0) { words++, count += cnt;}
                cnt = 0, hasNum = false, hasPoint = false;
            }else if(isdigit(s[i])) cnt = 0, hasNum = true;
        }
        if(words == 0) cout << "250\n";
        else {
            int media = count / words;
            if(media <= 3) cout << "250\n";
            else if(media <= 5) cout << "500\n";
            else if(media >= 6) cout << "1000\n";
            else cout << "0\n";
        }
    }
    return 0;
}