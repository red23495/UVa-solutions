#include<iostream>
#include<vector>
using namespace std;

struct p{
    int first;
    int second;
};



int use;
bool check;
int n,m,l;
vector<int> v;
vector<p> d;

void backtrack(int i){
    //if(i < d.size() && !(use & (1 << i)) ) cout << d[i].first << ' ' << d[i].second << endl;
    //for(auto x : v) cout << x << ' '; cout << endl;
    if( l == n+1){
        cout << "YES\n";
        check = false;
        return;
    }
    if(i == d.size()) return;
    if(!check)return;
    if(use & (1 << i)){backtrack(i+1);return;}
    if(d[i].first == v[l-1] && (d[i].second == v[l+1] || v[l+1] == -1)){
        v[l] = d[i].second;
        l++;
        use |= (1 << i);
        backtrack(0);
        v[l] = -1;
        l--;
        use ^= (1 << i);
    }
    if(d[i].second == v[l-1] && (d[i].first == v[l+1] || v[l+1] == -1) && d[i].first != d[i].second){
        v[l] = d[i].first;
        l++;
        use |= (1 << i);
        backtrack(0);
        v[l] = -1;
        l--;
        use ^= (1 << i);
    }
    backtrack(i+1);
}

int main(){
    while(cin >> n >> m && (n||m)){
        check = true;
        v.assign(n+2,-1);
        d.clear();
        int a,b;
        cin >> a >> b;
        v[0] = b;
        cin >> a >> b;
        v[n+1] = a;
        while(m--){
            cin >> a >> b;
            d.push_back(p{a,b});
        }
        l = 1;
        use = 0;
        backtrack(0);
        if(check) cout << "NO\n";
    }
}
