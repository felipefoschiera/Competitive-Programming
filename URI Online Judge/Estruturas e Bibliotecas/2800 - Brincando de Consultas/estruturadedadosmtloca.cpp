#include <cstdio>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#define MAX 112345
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

int main(){
    int N, Q;
    while(scanf("%d %d", &N, &Q) != EOF){
        ordered_set<int> sets[MAX];
        int arr[N+1];
        for(int i = 1; i <= N; i++){
            scanf("%d", &arr[i]);
            sets[arr[i]].insert(i);
        }
        int op, x, y, w;
        while(Q--){
            scanf("%d", &op);
            if(op == 1){
                scanf("%d %d", &x, &w);
                sets[arr[x]].erase(x);
                arr[x] = w;
                sets[w].insert(x);
            }else if(op == 2){
                scanf("%d %d %d", &x, &y, &w);
                int intervSize = (y - x + 1);
                int menoresY = sets[w].order_of_key(y+1);
                int menoresX = sets[w].order_of_key(x);
                int diff = menoresY - menoresX;
                printf("%d\n", intervSize - diff);

            }
            
        }
    }
    return 0;
}