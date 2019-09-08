#include <bits/stdc++.h>
using namespace std;

int main(){
	int init,num,value;
	char a,target;
	int D,E,F;
	cin >> init >> num;
	D=init;
	E=init;
	F=init;
	for(int i=0;i<num;i++){
		cin >> a;
		if(a=='C'){
			cin >> a >> value;
			if(a=='D'){
				D-=value;
			}
			if(a=='E'){
				E-=value;
			}
			if(a=='F'){
				F-=value;
			}
		}
		if(a=='V'){
			cin >> a >> value;
			if(a=='D'){
				D+=value;
			}
			if(a=='E'){
				E+=value;
			}
			if(a=='F'){
				F+=value;
			}
		}
		if(a=='A'){
			cin >> a;
			cin >> target >> value;
			if(target=='D'){
				D-=value;
			}
			if(target=='E'){
				E-=value;
			}
			if(target=='F'){
				F-=value;
			}
			if(a=='D'){
				D+=value;
			}
			if(a=='E'){
				E+=value;
			}
			if(a=='F'){
				F+=value;
			}
		}
	}
	cout << D << " " << E << " " << F << "\n";
	return 0;
}