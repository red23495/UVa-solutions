#include<bits/stdc++.h>

using namespace std;

int n,c,test;
vector<string> v;
map<string,int> m;
vector<vector<int>> g;
vector<int> out;

int main(){
    while(cin >> n){
        v.clear();
        v.resize(n);
        m.clear();
        for(int i = 0; i < n; i++){
            cin >> v[i];
            m[v[i]] = i;
        }
        cin >> c;
        g.clear();
        g.resize(n);
        out.clear();
        out.resize(n,0);
        while(c--){
            string s1,s2;
            cin >> s1 >> s2;
            int p1 = m[s1], p2 = m[s2];
            g[p1].push_back(p2);
            out[p2]++;
        }
        vector<int> ans;
        int count = 0;
        while(count < n){
            for(int i = 0; i < n; i++){
                if(out[i] == 0){
                    for(int j = 0; j < g[i].size(); j++){
                        out[g[i][j]]--;
                    }
                    out[i]--;
                    ans.push_back(i);
                    count++;
                    break;
                }
            }
        }
        cout << "Case #"<<++test<<": Dilbert should drink beverages in this order:";
        for(auto x: ans) cout << ' ' << v[x];
        cout << ".\n\n";
    }
    return 0;
}
