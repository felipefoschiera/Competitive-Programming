#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    while(getline(cin, s)){
        if(s == "esquerda") cout << "ingles";
        if(s == "direita") cout << "frances";
        if(s == "nenhuma") cout << "portugues";
        if(s == "as duas") cout << "caiu";
        cout << '\n';
    }
    return 0;
}