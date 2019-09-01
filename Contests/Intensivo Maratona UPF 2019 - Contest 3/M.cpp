#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    cin.ignore();
    for(int i = 0; i < t; i++){
        string s;
        int num1, num2, dado;
        char op, trash;
        cin >> num1 >> op >> num2 >> trash >> dado;
        int res;
        if(op == '+') res = num1 + num2;
        else if(op == '-') res = num1 - num2;
        else if(op == 'x') res = num1 * num2;
        int diff = abs(res - dado);
        cout << "E";
        for(int i = 0; i < diff; i++) cout << "r";
        cout << "ou!\n";
    }
    return 0;
}