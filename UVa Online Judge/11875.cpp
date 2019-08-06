#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int t; cin >> t;
    for(int tc = 1; tc <= t; tc++){
        int n; cin >> n;
        int arr[n];
        for(int i = 0; i < n; i++) cin >> arr[i];
        sort(arr, arr+n);
        int res = arr[n/2];
        cout << "Case " << tc << ": " << res << "\n";
    }
    return 0;
}