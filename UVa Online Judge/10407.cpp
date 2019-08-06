#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

int main(){
    
    string s;
    while(getline(cin, s), s != "0"){
        stringstream ss(s);
        
        vector<int> v; int x;   
        while(ss >> x){
            if(x != 0)
                v.push_back(x);
        }
        int res = abs(v[1]-v[0]);
        for(int i = 2; i < v.size(); i++)
            res = gcd(res, abs(v[i]-v[0]));
        cout << res << '\n';
    }
    return 0;
}