// URI 2906 / Maratona SBC 2018 - Database of Clients
// Felipe G. Foschiera
#include <iostream>
#include <map>
using namespace std;

map<string, bool> exists;

int main(){
	int n;
	cin >> n;
	int cnt = 0;
	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		string nova = "";
		bool plus = false, afterat = false;
		for(auto c : s){
			if(c == '+') { plus = true; continue; }
			if(c == '@') afterat = true;
			if(plus && !afterat) continue;
			if(c == '.' && !afterat) continue;
				nova.push_back(c);
		}
		if(exists.find(nova) == exists.end()){
			cnt++;
			exists[nova] = true;
		}
	}
	cout << cnt << '\n';
	return 0;
}