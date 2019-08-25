#include <bits/stdc++.h>
using namespace std;

int main(){
    int d, vf, vg;
    while(cin >> d >> vf >> vg){
        int df = 12;
        int dg = sqrt(144 + d*d);
        double tempof = (double)df / vf;
        double tempog = (double)dg / vg;
        if(tempog <= tempof){
            cout << "S\n";
        }else cout << "N\n";
    }
    return 0;   
}   