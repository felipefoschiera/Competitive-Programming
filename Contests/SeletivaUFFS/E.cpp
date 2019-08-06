#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

ll dp[20][20][2][2];
int sz, d;

ll solve(int idx, int cnt, bool tight, bool is_zero, vector<int> &a){
	if(idx == sz) return cnt;
	if(dp[idx][cnt][tight][is_zero] != -1)
		return dp[idx][cnt][tight][is_zero];
	ll res = 0;
	int k = tight ? a[idx] : 9;
	for(int i = 0; i <= k; i++){
		int current_cnt = cnt;
		if(i == d){
			if(d != 0 || (d == 0 && is_zero)){
				current_cnt++;
			}
		}
		int new_tight = (a[idx] == i) ? tight : 0;
		res += solve(idx+1, current_cnt, new_tight, is_zero||(i != 0), a);
	}
	if(tight != 1)
		dp[idx][cnt][tight][is_zero] = res;
	return res;
}

ll query(ll x){
	vector<int> digits;
	while(x){
		digits.push_back(x%10);
		x /= 10;
	}
	reverse(digits.begin(), digits.end());
	memset(dp, -1, sizeof dp);
	d = 8, sz = digits.size();
	return solve(false, false, true, false, digits);
}

int main(){
    ll a, b;
    cin >> a >> b;
    ll res = query(b) - query(a);
    cout << res << '\n';
    return 0;
}