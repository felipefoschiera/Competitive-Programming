#include <iostream>
using namespace std;

int main(){	
	string s, crib;
	while(cin >> s >> crib){
		int cnt = 0;
		int szS = s.length(), szCrib = crib.length();
		for(int i = 0; i <= szS - szCrib; i++){
			bool ok = true;
			for(int j = 0; j < szCrib; j++){
				if(s[i+j] == crib[j]) { ok = false; break; }
			}
			if(ok) cnt++;
		}
		cout << cnt << '\n';
	}	
	return 0;
}