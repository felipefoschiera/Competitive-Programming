#include <iostream>
using namespace std;

int cntzero, cntspace;

void mostraZeros(){
	if(cntzero > 2){
		if(cntzero > 255){
			while(cntzero > 255){
				cout << "#";
				cout << ((char)255);
				cntzero -= 255;
			}
		}
		if(cntzero > 0){
			cout << "#";
			cout << ((char)cntzero);
		}
	}else{
		if(cntzero == 1) cout << "0";
		if(cntzero == 2) cout << "00";
	}
	cntzero = 0;
}

void mostraEspaco(){
	if(cntspace > 2){
		if(cntspace > 255){
			while(cntspace > 255){
				cout << "$";
				cout << ((char)255);
				cntspace -= 255;
			}
		}
		if(cntspace){
			cout << "$";
			cout << ((char)cntspace);
		}
	}else{
		if(cntspace == 1) cout << " ";
		if(cntspace == 2) cout << "  ";
	}
	cntspace = 0;
}

int main(){
	int n;
	cin >> n;
	cin.ignore();
	while(n--){
		string s;
		getline(cin, s);
		cntzero = 0, cntspace = 0;
		int sz = s.length();
		for(int i = 0; i < sz; i++){
			if(s[i] == '0'){
				cntzero++;
				mostraEspaco();
				cntspace = 0;
				if(i == sz-1) mostraZeros();
			}else if(s[i] == ' '){
				cntspace++;
				mostraZeros();
				cntzero = 0;
				if(i == sz-1) mostraEspaco();
			}else{
				mostraZeros();
				mostraEspaco();
				cntspace = 0;
				cntzero = 0;
				cout << s[i];
			}
		}
		cout << '\n';
	}
	return 0;	
}