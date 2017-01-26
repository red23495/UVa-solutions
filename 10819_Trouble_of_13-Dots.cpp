#include<bits/stdc++.h>

using namespace std;

int n,m;
int p[100],f[100];
int memo[105][10005];
int backtrack(int index,int money){
    if(money > m && m <= 1800) return INT_MIN;
    if(money > m+200) return INT_MIN;
    if(index == n) {
        if(money > m && money <= 2000)
            return INT_MIN;
        return 0;
    }
    if(memo[index][money] != -1) return memo[index][money];
    return memo[index][money] =  max(backtrack(index+1,money),f[index]+backtrack(index+1,money+p[index]));
}

int main(){
    while(cin >> m >> n){
        for(int i = 0; i < n; i++){
            cin >> p[i] >> f[i];
        }
        memset(memo,-1,sizeof memo);
        int ans = backtrack(0,0);
        cout << ans << endl;
    }
    return 0;
}
