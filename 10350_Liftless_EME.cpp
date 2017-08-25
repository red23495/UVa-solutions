#include<bits/stdc++.h>

using namespace std;

constexpr int MAX_CAPACITY = 125*16;
vector<vector<int>> v;
int w[MAX_CAPACITY][MAX_CAPACITY], memo[MAX_CAPACITY];

int dfs(int p){
    //cout << memo[p] << v[p].size() << endl;
    if(!v[p].size()) return 0;
    if(memo[p] != INT_MAX) return memo[p];
    for(int i = 0; i < v[p].size(); i++){
        //cout << v[p][i] << endl;
        memo[p] = min(memo[p],w[p][v[p][i]]+dfs(v[p][i]));
    }
    return memo[p];
}

int main(){
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    string s;
    int n,m;
    while(cin >> s >> n >> m){
        v.clear();
        v.resize(MAX_CAPACITY);
        memset(w,0,sizeof w);
        for(int i = 1; i < n; i++){
            for(int j = 0; j < m; j++){
                for(int k = 0; k < m; k++){
                    int x;
                    cin >> x;
                    v[i*m+j].push_back((i+1)*m+k);
                    w[i*m+j][(i+1)*m+k] = x+2;
                }
            }
        }
        for(int i = 0; i < m; i++) v[0].push_back(m+i);
        for(int i = 0; i < MAX_CAPACITY; i++) memo[i] = INT_MAX;
        int ans = dfs(0);
        cout << s << '\n' << ans << endl;
    }
    return 0;
}
