#include<bits/stdc++.h>

using namespace std;

int n,m;
vector<pair<pair<int,int>,int>> e;

class union_find{
    vector<int> p,rank;
public:
    union_find(int n){
        p.resize(n);
        rank.resize(n);
        for(int i = 0; i < n; i++) p[i] = i;
    }
    int parent(int i){
        if(p[i] == i) return i;
        return p[i] = parent(p[i]);
    }
    void union_set(int i, int j){
        int x = parent(i), y = parent(j);
        if(rank[x] > rank[y]) p[y] = x;
        else{
            p[x] = y;
            if(rank[x] == rank[y]) rank[y]++;
        }
    }
};

int main(){
    while(cin >> n >> m && n){
        int sum = 0;
        e.clear();
        while(m--){
            int x,y,z;
            cin >> x >> y >> z;
            sum += z;
            e.push_back({{x,y},z});
        }
        int ans = 0,cnt = 0;
        auto comp = [](pair<pair<int,int>,int> a, pair<pair<int,int>,int> b){
                            if(a.second < b.second) return true;
                            return false;
                        };
        sort(e.begin(),e.end(),comp);
        union_find u(n);
        for(int i = 0; i < e.size() && cnt < n-1; i++){
            int x = e[i].first.first, y = e[i].first.second;
            if(u.parent(x) != u.parent(y)){
                ans += e[i].second;
                cnt++;
                u.union_set(x,y);
            }
        }
        cout << sum - ans << endl;
    }
    return 0;
}
