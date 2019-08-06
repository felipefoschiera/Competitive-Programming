// URI 2904 / Maratona SBC 2018 - Building a Field
// Felipe G. Foschiera
#include <cstdio>
#include <set>
using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	int v[n];
	for(int i = 0; i < n; i++)
		scanf("%d", &v[i]);
	set<int> st;
	st.insert(0);
	int acum = 0;
	for(int i = 0; i < n; i++){
		acum += v[i];
		if(i < n-1)	
			st.insert(acum);
	}
    if(acum % 2 == 1){
        printf("N\n");
    }else{
        int half = acum / 2, cnt = 0;
        for(auto v : st){
            cnt += (st.find(v + half) != st.end());
        }
        printf("%c\n", cnt > 1 ? 'Y' : 'N');
    }
    return 0;
}