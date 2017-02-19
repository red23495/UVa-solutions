#include<bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> v;

int main(){
    cin >> n;
    v.resize(n);
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        while(x--){
            int t;
            cin >> t;
            v[i].push_back(t);
        }
    }
    int test;
    cin >> test;
    while(test--){
        int a;
        cin >> a;
        vector<int> level(n,-1);
        vector<int> day(n);
        queue<int> q;
        q.push(a);
        level[a] = 0;
        day[a] = 0;
        bool spread = false;
        while(!q.empty()){
            int p = q.front(); q.pop();
            for(int i = 0; i < v[p].size(); i++){
                if(level[v[p][i]] == -1){
                    spread = true;
                    level[v[p][i]] = level[p]+1;
                    day[level[v[p][i]]]++;
                    q.push(v[p][i]);
                }
            }
        }
        int m = 0;
        for(int i = 0; i < n; i++){
            if(day[m] < day[i]) m = i;
        }
        if(spread) cout << day[m] << ' ' << m << endl;
        else cout << "0\n";
    }
    return 0;
}
