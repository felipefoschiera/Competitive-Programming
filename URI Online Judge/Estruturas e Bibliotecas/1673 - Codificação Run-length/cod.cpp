#include <iostream>
using namespace std;

int main(){
    string s;
    while(getline(cin, s)){
        int cnt = 0, sz = s.length();
        bool open1 = false;
        for(int i = 0; i < sz; i++){
            if(i != 0 && (s[i] != s[i-1])){
                if(cnt > 1){
                    if(open1){ cout << 1; open1 = false; }
                    cout << cnt << s[i-1];
                }else if(cnt == 1){
                    if(!open1){ cout << cnt; open1 = true; }
                    cout << s[i-1];
                    if(s[i-1] == '1') cout << 1;
                }
                cnt = 0;
            }
            cnt++;
            if(cnt == 9){
                if(open1){ cout << 1; open1 = false; }
                cout << cnt << s[i];
                cnt = 0;
            }
            if(i == sz-1){
                if(cnt > 1){ 
                    if(open1) cout << 1;
                     cout << cnt << s[i];
                }
                else if(cnt == 1){
                    if(!open1){
                        cout << cnt << s[i];
                        if(s[i] == '1') cout << 1;
                        cout << 1;
                    }else{
                        cout << s[i];
                        if(s[i] == '1') cout << s[i];
                        cout << 1;
                    }
                }
            }
        }
        cout << '\n';
    }
    return 0;
}