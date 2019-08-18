#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;

int main(){
	int N;
	while(cin >> N){
		int M, L;
		cin >> M >> L;
		vector<vi> marcos(M, vi(N, 0));
		vector<vi> leo(L, vi(N, 0));
		for(int i = 0; i < M; i++)
			for(int j = 0; j < N; j++) cin >> marcos[i][j];
		
		for(int i = 0; i < L; i++)
			for(int j = 0; j < N; j++) cin >> leo[i][j];
		int cm, cl;
		cin >> cm >> cl;
		int A;
		cin >> A;
		cm--, cl--, A--;
		if(marcos[cm][A] > leo[cl][A]) cout << "Marcos\n";
		else if(marcos[cm][A] == leo[cl][A]) cout << "Empate\n";
		else cout << "Leonardo\n";


	}
	
	return 0;
}