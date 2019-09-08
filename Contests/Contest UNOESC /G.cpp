#include <bits/stdc++.h>
using namespace std;

int main(){
	int q;
	cin >> q;
	while(q--){
		int a, b;
		cin >> a >> b;
		int interv = (b - a + 1);
		int x = interv / 2;
		if(a % 2 == 0 && interv % 2 == 1) x++;
		cout << x << '\n';
	}
	return 0; 
}