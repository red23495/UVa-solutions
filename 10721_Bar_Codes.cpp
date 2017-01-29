#include<bits/stdc++.h>

using namespace std;

long long n,k,m;
long long memo[55][55];


long long backtrack(int index,long long sum){
    if(index == k && sum == n) return 1;
    if(index >= k || sum > n) return 0;
    if(memo[index][sum] != -1) return memo[index][sum];
    long long ans = 0;
    for(int i = 1 ; i <= m; i++)
        ans += backtrack(index+1,sum+i);
    memo[index][sum] = ans;
    return ans;
}

int main(){
    while(cin >> n >> k >> m){
        memset(memo,-1,sizeof memo);
        long long ans = backtrack(0,0);
        cout << ans << endl;
    }
    return 0;
}
