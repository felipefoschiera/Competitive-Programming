#include <iostream>
using namespace std;

int main(){
    int n, m;
    double down, loan;
    while(cin >> n >> down >> loan >> m){
        if(n < 0) break;
        int month;
        double x;

        double v[112];
        for(int i = 0; i < 112; i++) v[i] = -1;
        for(int i = 0; i < m; i++){
            cin >> month >> x;
            v[month] = x;
        }
        int it = 0;
        double mes = loan / n;        
        double car = loan + down;
        car -= car * v[0];
        double last = v[0];
        while(car < loan){
            it++;
            loan -= mes;
            double x = v[it];
            if(x == -1) x = last;
            car -= car * x;
            last = x;
        }

        if(it == 1){
            cout << "1 month\n";
        }else{
            cout << it << " months\n";
        }
    }
    return 0;
}