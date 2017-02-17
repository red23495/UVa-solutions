#include<bits/stdc++.h>

using namespace std;

using ii = pair<int,int>;

int s,n;
vector<ii> v;
vector<pair<ii,double>> e;
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
    int test;
    cin >> test;
    while(test--){
        cin >> s >> n;
        v.clear();
        v.resize(n);
        for(auto& x: v){
            int a,b;
            cin >> a >> b;
            x = {a,b};
        }
        e.clear();
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                double x1 = v[i].first, x2 = v[j].first, y1 = v[i].second, y2 = v[j].second;
                double x = x1 - x2, y = y1 - y2;
                double dist = sqrt(x*x+y*y);
                e.push_back({{i,j},dist});
            }
        }
        auto comp = [](pair<ii,double> a, pair<ii,double> b){
                            if(a.second < b.second) return true;
                            return false;
                        };
        sort(e.begin(),e.end(),comp);
        union_find u(n);
        int state = n;
        double ans = 0;
        for(int i = 0; i < e.size() && state > s; i++){
            int x = e[i].first.first, y = e[i].first.second;
            if(u.parent(x) != u.parent(y)){
                state--;
                u.union_set(x,y);
                ans = max(e[i].second,ans);
            }
        }
        cout << fixed << setprecision(2) << ans << endl;
    }
    return 0;
}
