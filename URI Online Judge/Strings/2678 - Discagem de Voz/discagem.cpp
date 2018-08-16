#include <iostream>
using namespace std;

char equiv[] = {'2', '2', '2', '3', '3', '3', '4', '4', '4', '5', '5', '5', '6', '6', 
                '6', '7', '7', '7', '7', '8', '8', '8' ,'9', '9', '9', '9'};

int main(){
    string s;
    while(getline(cin, s)){
        string num = "";
        for(auto c : s){
            if(isdigit(c)) num += c;
            else {
                if(isalpha(c)) c = toupper(c);
                int ind = c - 'A';
                if(ind >= 0 && ind < 26) num += equiv[c - 'A'];
                else if(c == '*' || c == '#') num += c;
            }
        }
        cout << num << '\n';
    }
    return 0;   
}