#include <bits/stdc++.h>
using namespace std;

int main(){
	int a;
	string m,fin;
	cin >> a;
	for(int i=0;i<a;i++){
		fin.clear();
		cin >> m;
		for(int j=m.size()-1;j>=0;j--){
			if(islower(m[j])){
				fin.push_back(m[j]);
			}
		}
		cout << fin << "\n";
	}
	return 0;
}