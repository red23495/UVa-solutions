#include<iostream>
#include<string>
#include<vector>
using namespace std;

int digit[10] = {63,6,91,79,102,109,125,7,127,111};
vector<int> v;
int n;

bool match(int x, int i, int damaged){
    //cout << x << ' ' << i<< ' ' << v[i] << ' ' << damaged << ((~digit[x] | damaged) & v[i]) <<endl;
    if(i == n) return true;
    if((~digit[x] | damaged) & v[i]) return false;
    damaged |= (v[i]^digit[x]);
    return match(x-1,i+1,damaged);
}

int main(){
    while(cin >> n && n){
        v.clear();
        v.resize(n);
        string s;
        for(int i = 0; i < n; i++){
            cin >> s;
            for(int c = 0;  c < s.length(); c++){
                if(s[c] == 'Y'){
                    v[i] |= (1 << c);
                }
            }
        }
        bool c = false;
        for(int i = n - 1; i < 10 && !c; i++){
            c = match(i,0,0);
        }
        if(c) cout << "MATCH\n";
        else cout << "MISMATCH\n";
    }
}
