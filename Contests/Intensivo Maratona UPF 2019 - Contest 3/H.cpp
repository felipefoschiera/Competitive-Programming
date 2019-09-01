#include <bits/stdc++.h>
using namespace std;

int v[12];

vector<pair<int, string>> pont;

int main(){
    int t, tc = 1;
    while(cin >> t, t){
        pont.clear();
        string nome;
        for(int i = 0; i < t; i++){
            cin >> nome;
            for(int j = 0; j < 12; j++){
                cin >> v[j];
            }
            sort(v, v+12);
            int r = 0; for(int j = 1; j < 11; j++) r += v[j];
            pont.push_back({-r, nome});
        }
        sort(pont.begin(), pont.end());
        cout << "Teste " << tc++ << '\n';
        for(int i = 0; i < t; i++){
            int r = 1 + i;
            for(int j = 0; j < i; j++) if(pont[j].first == pont[i].first) r--;
            cout << r << " " << -pont[i].first << " " << pont[i].second << '\n';
        }
        cout << '\n'; 
    }
    return 0;
}