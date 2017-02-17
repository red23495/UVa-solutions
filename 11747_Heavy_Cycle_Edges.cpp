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
        if(i == p[i]) return i;
        return p[i]=parent(p[i]);
    }
    void union_set(int i , int j){
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
        int x,y,z;
        e.clear();
        while(m--){
            cin >> x >> y >> z;
            e.push_back({{x,y},z});
        }
        union_find u(n);
        auto comp = [](pair<pair<int,int>,int> a,pair<pair<int,int>,int> b){
                            if(a.second < b.second) return true;
                            return false;
                        };
        sort(e.begin(),e.end(),comp);
        bool forest = true;
        for(int i = 0; i < e.size(); i++){
            int x = e[i].first.first, y = e[i].first.second;
            if(u.parent(x) != u.parent(y)){
                u.union_set(x,y);
            }else{
                if(forest){
                    forest = false;
                    cout << e[i].second;
                }else{
                    cout << ' ' <<e[i].second;
                }
            }
        }
        if(forest) cout << "forest";
        cout << endl;
    }
    return 0;
}
