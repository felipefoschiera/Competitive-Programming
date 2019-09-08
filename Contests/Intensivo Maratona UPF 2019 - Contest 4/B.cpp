#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	while(getline(cin, s)){
		int up = 1, m = s.size();
		for(int i = 0; i < m; i++){
			if(!isalpha(s[i])) continue;
			if(up) s[i] = toupper(s[i]);
			else s[i] = tolower(s[i]);
			up ^= 1;
		}
		cout << s << '\n';
	}
	return 0;
}