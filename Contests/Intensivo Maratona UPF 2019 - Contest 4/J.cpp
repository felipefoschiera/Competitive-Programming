#include <bits/stdc++.h>
using namespace std;


struct pt {
	int x, y;
	pt() { x = y = 0;}
	pt(int _x, int _y) : x(_x), y(_y) {}
};

int main(){
	pt A, B, C, D;
	while(cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y >> D.x >> D.y){
		if((C.x > B.x || D.x < A.x) || (C.y > B.y || D.y < A.y)){
			cout << "0\n";
		}else{
			cout << "1\n";
		}
	}
	
	return 0;
}
	
	

