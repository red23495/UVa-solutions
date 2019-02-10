#include<bits/stdc++.h>

using namespace std;

#define FASTIO ios::sync_with_stdio(0);cin.tie(0);

int coins[11] = {10000,5000,2000,1000,500,200,100,50,20,10,5};

long long mem[12][30005];

long long dp(int type, int val){
    //cout << type << ' ' << val << endl;
    if(type > 10) return 0;
    if(val < 0) return 0;
    if(val == 0) return 1;
    if(mem[type][val] != -1) return mem[type][val];
    return mem[type][val] = dp(type+1,val)+dp(type,val-coins[type]);
}

int main(){
    FASTIO
    memset(mem,-1,sizeof mem);
    double n;
    while(cin >> n && n != 0.00){
        int x = (n+1e-6)*100;
        long long ans = dp(0,x);
        cout << setw(6) << fixed << setprecision(2) << n << setw(17) << ans << endl;
    }
    return 0;
}
