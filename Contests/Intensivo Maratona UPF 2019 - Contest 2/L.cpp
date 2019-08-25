#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll A[101010], B[101010];

int main(){
    int s;
    cin >> s;
    
    for(int i = 0; i < s; i++)
        cin >> A[i];
    for(int i = 0; i < s; i++)
        cin >> B[i];
    sort(A, A+s);
    sort(B, B+s);
    int i = 0, j = 0, res = 0;
    while(i < s && j < s){
        if(B[j] > A[i]){
            i++; j++;
            res++;
        }else j++;
    }
    cout << res << '\n';

    return 0;
}