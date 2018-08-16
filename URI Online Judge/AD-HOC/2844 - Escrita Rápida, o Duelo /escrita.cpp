#include <iostream>
using namespace std;

int main(){
    int am, rm, em, av, rv, ev;
    cin >> am >> rm >> em;
    cin >> av >> rv >> ev;
    string s;
    cin.ignore();
    getline(cin, s);
    int qt = s.length();
    int matheus = em*qt + rm + am*2;
    int vinicius = ev*qt + rv + av*2;
    cout << (matheus < vinicius ? "Matheus" : matheus == vinicius ? "Empate" : "Vinicius") << endl;

}