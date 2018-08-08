#include <iostream>
using namespace std;

int main(){
    string s;
    while(getline(cin, s)){
        bool up = true;
        for(auto c : s){
            if(!isalpha(c)){
                cout << (char)c;
            }else{
                if(up)
                    cout << (char)toupper(c);
                else cout << (char)tolower(c);
                up ^= 1;
            }
        }
        cout << '\n';

    }
    return 0;
}