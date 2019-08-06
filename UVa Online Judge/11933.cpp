#include <iostream>
using namespace std;

int main(){
    int n;
    while(cin >> n, n){
        int a = 0,b = 0;
        int cnt = 0;

        for(int i = 0; i < 32; i++){
            if(n & (1 << i)){
                cnt++;
                if(cnt%2==1){
                    a |= (1 << i);
                }else{
                    b |= (1 << i);
                }
            }
        }
        cout << a << " " << b << "\n";

    }
    
    return 0;
}