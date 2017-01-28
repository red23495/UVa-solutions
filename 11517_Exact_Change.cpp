#include<bits/stdc++.h>

using namespace std;

int test,m,n,coin[101],memo[30001];

int main(){
    cin >> test;
    while(test--){
        cin >> m >> n;
        for(int i = 0; i < n; i++){
            cin >> coin[i];
        }
        for(int i = 0; i < 30001; i++) memo[i] = INT_MAX;
        memo[0] = 0;
        for(int i = 0; i < n; i++){
            for(int j = m; j >= 0; j--){
                if(memo[j] < INT_MAX)
                    memo[j+coin[i]] = min(memo[j+coin[i]],memo[j]+1);
            }
        }
        int ans = m;
        while(memo[ans] == INT_MAX) ans++;
        cout << ans << ' ' << memo[ans] << endl;
    }
}
