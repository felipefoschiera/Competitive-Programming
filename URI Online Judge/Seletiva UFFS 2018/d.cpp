/**
 *  Seletiva UFFS 2018 - URI Online Judge
 *  Felipe G. Foschiera
 */
#include <iostream>
using namespace std;

int main(){
    string a, b;
    cin >> a >> b;
    cout << (a < b ? a : b) << endl << (a < b ? b : a) << endl;
    return 0;
}