#include <iostream>
using namespace std;

int main(){
    string line;
    int st = 0;
    while(getline(cin, line)){
        for(int i = 0; i < (int)line.length(); i++){
            if(line[i] == '"'){
                if(st == 0){
                    line[i] = '`';
                    line.insert(i+1, "`");
                    st = 1;
                }else{
                    line[i] = '\'';
                    line.insert(i+1, "'");
                    st = 0;
                }
            }
        }
        cout << line << '\n';
    }
    return 0;
}