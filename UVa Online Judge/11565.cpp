#include <iostream>
using namespace std;

int main(){
    int n; cin >> n;
    while(n--){
        bool ok = false;
        int a, b, c;
        cin >> a >> b >> c;
        for(int x = -100; x <= 100 && !ok; x++){
            for(int y = -100; y <= 100 && !ok; y++){
                for(int z = -100; z <= 100 && !ok; z++){
                    if(x != y && x != z && y != z){
                        if(x+y+z == a && x*y*z == b && (x*x)+(y*y)+(z*z) == c){
                            cout << x << " " << y << " " << z << "\n";
                            ok = true;
                        }
                    }
                }
            }
        }
        if(!ok) cout << "No solution.\n";
    }
    return 0;
}