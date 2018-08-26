// URI 2538 - Ginásio
// Felipe G. Foschiera
#include <cstdio>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef pair<int, int> ii;
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main(){
    int IP, M;
    while(scanf("%d %d", &IP, &M) != EOF){
        ordered_set ginasio;
        for(int i = 0; i < M; i++){
            int pc, na;
            scanf("%d %d", &pc, &na);
            int lo = pc - IP, hi = pc + IP;
            int upper = ginasio.order_of_key({hi+1, 0});
            int lower = ginasio.order_of_key({lo, 0});
            int between = upper - lower;
            if(between <= na) ginasio.insert({pc, i});
            
        }
        printf("%d\n", (int)ginasio.size());
    }
    return 0;
}