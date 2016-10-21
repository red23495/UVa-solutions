#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int c;
    while(cin >> c && c){
        vector<string> lst(c-1);
        for(auto& x : lst) cin >> x;
        char init = 'x';
        int sign = +1;
        for(auto x: lst){
            if(x == "No") continue;
            if(init == 'x'){
                init = x[1];
                char c_sign = (sign == 1)?'+':'-';
                if(c_sign == '-'){
                    sign = (x[0] == '+')? -1:1;
                }
                else sign = (x[0] == '+')? 1:-1;
            }else if(init == x[1]){
                init = 'x';
                char c_sign = (sign == 1)?'+':'-';
                sign = (x[0]==c_sign)?-1:+1;
            }
        }
        cout << (( sign == +1)? '+':'-') << init << endl;
    }
    return 0;
}
