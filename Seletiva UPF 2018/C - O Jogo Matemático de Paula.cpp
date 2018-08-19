#include <iostream>
using namespace std;

int main(){
	int N;
	cin >> N;
	while(N--){
		int a, b;
		char c;
		cin >> a >> c >> b;
		if(a == b) cout << a*b;
		else if(isupper(c)) cout << b-a;
		else if(islower(c)) cout << a + b;
		cout << '\n';
	}
	return 0;
}