    #include <bits/stdc++.h>
    using namespace std;

    string s = "123456789";

    set<string> solutions;

    void solve(int idx, string str){
        if(idx == 9){
            // check if generated string is valid
            int sum = 0, cursum = 0;
            bool sign = true;
            for(char x : str){
                if(x >= '0' && x <= '9'){
                    cursum = cursum * 10 + (x - '0');
                }else{
                    if(!sign) cursum = -cursum;
                    sum += cursum;
                    cursum = 0;
                    sign = (x == '+');
                }
            }
            if(cursum){
                if(!sign) cursum = -cursum;
                sum += cursum;
            }
            if(sum == 100){
                if(str[0] == '+')
                    str.erase(str.begin(), str.begin()+1);
                solutions.insert(str);
            }
            return;
        }

        solve(idx+1, str + s[idx]); // next number
        solve(idx+1, str + '+' + s[idx]); // add
        solve(idx+1, str + '-' + s[idx]); // subtract

    }

    int main(){
        solve(0, "");
        for(string s : solutions){
            cout << s << '\n';
        }
        return 0;
    }
