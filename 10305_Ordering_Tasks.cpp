#include<bits/stdc++.h>

using namespace std;

int m,n;
vector<vector<int>> v;
vector<int> out;

void topsort(vector<int>& p){
    if(p.size() == m) return;
    int start = p.size();
    for(int i = 0; i < m; i++){
        if(out[i]==0){
            out[i]--;
            p.push_back(i);
        }
    }
    for(int i = start; i < p.size(); i++){
        for(auto x: v[p[i]]) out[x]--;
    }
    topsort(p);
}

int main(){
    while(cin >> m >> n && m){
        v.clear();
        v.resize(m);
        out.clear();
        out.resize(m);
        while(n--){
            int a,b;
            cin >> a >> b;
            a--;b--;
            v[a].push_back(b);
            out[b]++;
        }
        vector<int> ans;
        topsort(ans);
        for(int i = 0; i < m; i++){
            if(i) cout << ' ';
            cout << ans[i]+1;
        }
        cout << endl;
    }
    return 0;
}
