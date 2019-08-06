#include <iostream>
#include <queue>
using namespace std;

int main(){
    int n;
    while(cin >> n, n){
        priority_queue<int, vector<int>, greater<int> > pq;
        int v;
        for(int i = 0; i < n; i++){
            cin >> v;
            pq.push(v);
        }
        int res = 0;
        while(pq.size() > 1){
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            res += a+b;
            pq.push(a+b);
        }
        cout << res << '\n';
    }
    return 0;
}