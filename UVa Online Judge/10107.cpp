#include <iostream>
#include <set>
using namespace std;

int main(){    
    multiset<int> ms;
    int x;
    while(cin >> x){
        ms.insert(x);
        int size = ms.size();
        int res = 0;
        auto it = ms.begin();
        advance(it, size/2);
        res += (*it);
        if(size%2==0){
            it--;
            res += (*it);
            res /= 2;
        }
        cout << res << '\n';

    }
    return 0;
    
}