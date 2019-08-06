#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int A[n][n];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++){
            cin >> A[i][j];
            if(i > 0) A[i][j] += A[i-1][j];
            if(j > 0) A[i][j] += A[i][j-1];
            if(i > 0 && j > 0) A[i][j] -= A[i-1][j-1];
        }

    int maxSubrect = -127*100*100;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            for(int k = i; k < n; k++)
                for(int l = j; l < n; l++){
                    int subRect = A[k][l];
                    if(i > 0) subRect -= A[i-1][l];
                    if(j > 0) subRect -= A[k][j-1];
                    if(i > 0 && j > 0) subRect += A[i-1][j-1];
                    maxSubrect = max(maxSubrect, subRect);
                }
    cout << maxSubrect << '\n';
    return 0;
}