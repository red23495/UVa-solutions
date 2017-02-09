#include<bits/stdc++.h>

using namespace std;

vector<int> v;
int n,test;
vector<bool> visited;
int ans,l;
int memo[50001];
int dfs(int i){
    if(visited[i]) return 0;
    //cout << i << endl;
    visited[i] = true;
    memo[i] = (1+dfs(v[i]));
    return memo[i];
}

int main(){
    cin >> test;
    for(int t = 1; t <= test; t++){
        cin >> n;
        v.clear();
        v.resize(n);
        for(int i = 0; i < n; i++) {
            int a , b;
            cin >> a >> b;
            a--; b--;
            v[a] = b;
        }
        l = -1;
        ans = INT_MAX;
        memset(memo,-1,sizeof memo);
        for(int i = 0; i < n; i++){
            if(memo[i] == -1){
                visited.clear();
                visited.resize(n);
                int p = dfs(i);
                if(p > l) {ans = i;l = p;}
                else if( p == l) if(ans > i) ans = i;
            }else if(memo[i] > l){
                ans = i;l = memo[i];
            }else if(memo[i] == l){
                if(ans > i) ans = i;
            }
        }
        cout << "Case " << t << ": " << ++ans << endl;
    }
    return 0;
}
