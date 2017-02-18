#include<bits/stdc++.h>

using namespace std;
using ii = pair<int,int>;

int n,m;
vector<pair<ii,int>> e;

class union_find{
    vector<int> p,rank;
public:
    union_find(int n){
        p.resize(n);
        rank.resize(n);
        for(int i = 0; i < n; i++) p[i] = i;
    }
    int parent(int i){
        if(i == p[i]) return i;
        return p[i] = parent(p[i]);
    }
    void union_set(int i,int j){
        int x = parent(i), y = parent(j);
        if(rank[x] > rank[y]) p[y] = x;
        else {
            p[x] = y;
            if(rank[x] == rank[y]) rank[y]++;
        }
    }
};

int main(){
    int test;
    cin >> test;
    while(test--){
        e.clear();
        cin >> n >> m;
        while(m--){
            int x,y,z;
            cin >> x >> y >> z;
            x--;y--;
            e.push_back({{x,y},z});
        }
        auto comp = [](pair<ii,int> a, pair<ii,int> b){
                            if(a.second < b.second) return true;
                            return false;
                        };
        sort(e.begin(),e.end(),comp);
        vector<bool> taken(e.size());
        vector<int> mst;
        union_find u(n);
        int cnt = 0,cost1 = 0;
        for(int i = 0; i < e.size() && cnt < n-1; i++){
            int x = e[i].first.first, y = e[i].first.second;
            if(u.parent(x) != u.parent(y)){
                u.union_set(x,y);
                cost1 += e[i].second;
                cnt++;
                taken[i] = true;
                mst.push_back(i);
            }
        }
        int cost2 = INT_MAX;
        for(int i = 0; i < mst.size(); i++){
            union_find nu(n);
            for(int j = 0; j < mst.size(); j++){
                if(j != i) nu.union_set(e[mst[j]].first.first, e[mst[j]].first.second);
            }
            bool not_found = true;
            int t = cost1 - e[mst[i]].second;
            for(int j = 0; j < e.size() && not_found; j++){
                if(taken[j]) continue;
                int x = e[j].first.first, y = e[j].first.second;
                if(nu.parent(x) != nu.parent(y)){
                    not_found = false;
                    t += e[j].second;
                }
            }
            if(t >= cost1) cost2 = min(cost2,t);
        }
        cout << cost1 << ' ' << cost2 << endl;
    }
    return 0;
}
