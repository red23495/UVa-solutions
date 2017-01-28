#include<bits/stdc++.h>
using namespace std;

int conv[50],info[50],memo[305][305],test,m,s;

int backtrack(int c,int i){
    int v = c*c + i*i;
    if(v == s*s) return 0;
    if(v > s*s) return INT_MAX-500;
    if(memo[c][i] != -1) return memo[c][i];
    int t = INT_MAX-500;
    for(int a = 0; a < m; a++){
        t = min(t,1+backtrack(c+conv[a],i+info[a]));
    }
    memo[c][i] = t;
    return t;
}

int main(){
    cin >> test;
    while(test--){
        cin >> m >> s;
        for(int i = 0; i < m; i++) cin >> conv[i] >> info[i];
        memset(memo,-1,sizeof memo);
        int ans = backtrack(0,0);
        if(ans >= INT_MAX-500) cout << "not possible\n";
        else cout << ans << endl;
    }
    return 0;
}
