#include<bits/stdc++.h>

using namespace std;

int n,k;
unsigned long long memo[105][105];

unsigned long long backtrack(int index, int sum){
    if(index == k && sum == n) return 1;
    if(index >= k || sum > n) return 0;
    if(memo[index][sum] != -1) return memo[index][sum];
    long long ans = 0;
    for(int i = 0; i <= (n - sum); i++)
        ans += backtrack(index+1,sum+i);
    memo[index][sum] = ans%1000000;
    return memo[index][sum];
}

int main(){
    while(cin >> n >> k  && n){
        memset(memo,-1,sizeof memo);
        unsigned long long ans = backtrack(0,0);
        cout << ans%1000000 << endl;
    }
    return 0;
}
