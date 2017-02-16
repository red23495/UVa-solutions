#include<bits/stdc++.h>

using namespace std;

int n,r;
vector<pair<int,int>> v;
vector<pair<pair<int,int>,double>> e;

class union_find{
    vector<int> p,rank;
public:
    union_find(int n){
        p.resize(n);
        rank.resize(n);
        for(int i = 0; i < n; i++){
            p[i] = i;
        }
    }
    int parent(int i){
        if(p[i] == i) return i;
        p[i] = parent(p[i]);
        return p[i];
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

union_find* u;

int main(){
    int test;
    cin >> test;
    for(int t = 1; t <= test; t++){
        cin >> n >> r;
        v.clear();
        e.clear();
        for(int i = 0; i < n; i++){
            int x,y;
            cin >> x >> y;
            v.push_back({x,y});
        }
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                double x1 = v[i].first, y1 = v[i].second, x2 = v[j].first, y2 = v[j].second;
                double x = x1-x2, y = y1-y2;
                double dist = sqrt(x*x+y*y);
                e.push_back({{i,j},dist});
            }
        }
        int state = 1, cnt = 0;
        double sw = 0, hw = 0;
        auto comp = [](pair<pair<int,int>,double> a,pair<pair<int,int>,double> b){
                            if(a.second < b.second) return true;
                            return false;
                        };
        sort(e.begin(),e.end(),comp);
        u = new union_find(n);
        for(int i = 0; i < e.size() && cnt < n-1 ; i++){
            int x = e[i].first.first, y = e[i].first.second;
            if(u->parent(x) != u->parent(y)){
                double wght = e[i].second;
                //cout << x << ' ' << y << ' ' << wght << endl;
                if(wght > r){
                    state++;
                    sw += wght;
                }
                else hw += wght;
                cnt++;
                u->union_set(x,y);
            }
        }
        cout << "Case #" << t << ": " << state << " " << int(round(hw)) << " " << int(round(sw)) << endl;
        delete u;
    }
    return 0;
}
