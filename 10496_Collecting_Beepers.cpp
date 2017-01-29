#include<bits/stdc++.h>

using namespace std;

int test,t1,t2,n;
int x[11],y[11];
int memo[11][2050];
int dist(int i , int j){
    return abs(x[i]-x[j])+abs(y[i]-y[j]);
}

int backtrack(int pos, int mask){
    if(__builtin_popcount(mask) == n+1) return dist(pos,0);
    if(memo[pos][mask] != -1) return memo[pos][mask];
    int m = INT_MAX;
    for(int i = 0; i <= n; i++){
        if(!(mask & (1 << i))){
            m = min(m,dist(pos,i)+backtrack(i,mask | (1 << i)));
        }
    }
    memo[pos][mask] = m;
    return m;
}

int main(){
    cin >> test;
    while(test--){
        cin >> t1 >> t2;
        cin >> x[0] >> y[0];
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> x[i] >> y[i];
        }
        memset(memo, -1, sizeof memo);
        int ans = backtrack(0,1);
        cout << "The shortest path has length "<<ans<<endl;
    }
    return 0;
}
