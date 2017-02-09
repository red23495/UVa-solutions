#include<bits/stdc++.h>

using namespace std;

int r,c,m,n,w;
vector<vector<int>> v,b;
vector<vector<bool>> ch;
bool check_bound(int x, int y){
    bool ans = (x >= 0 && x < r && y >= 0 && y < c && !v[x][y]);
    if(ans) {
        if(ch[x][y]) return false;
        ch[x][y] = true;
    }
    return ans;
}

stack<pair<int,int>> reachable(int x, int y){
    stack<pair<int,int>> s;
    ch.clear();
    ch.resize(r,vector<bool>(c));
    if(check_bound(x+m,y+n)) s.push({x+m,y+n});
    if(check_bound(x-m,y+n)) s.push({x-m,y+n});
    if(check_bound(x+m,y-n)) s.push({x+m,y-n});
    if(check_bound(x-m,y-n)) s.push({x-m,y-n});
    if(check_bound(x+n,y+m)) s.push({x+n,y+m});
    if(check_bound(x-n,y+m)) s.push({x-n,y+m});
    if(check_bound(x+n,y-m)) s.push({x+n,y-m});
    if(check_bound(x-n,y-m)) s.push({x-n,y-m});
    return s;
}

void dfs(int x, int y){
    auto track = reachable(x,y);
    if(track.size() & 1) b[x][y] = 1;
    else if(track.size()) b[x][y] = 2;
    while(!track.empty()){
        auto a = track.top();
        track.pop();
        if(!b[a.first][a.second]) dfs(a.first,a.second);
    }
}

int main(){
    int test;
    cin >> test;
    for(int t = 1; t <= test; t++){
        cin >> r >> c >> m >> n;
        v.clear();
        b.clear();
        v.resize(r,vector<int>(c));
        b.resize(r,vector<int>(c));
        cin >> w;
        while(w--){
            int x,y;
            cin >> x >> y;
            v[x][y] = -1;
        }
        int odd = 0, even = 0;
        dfs(0,0);
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(b[i][j] == 1) odd++;
                else if(b[i][j] == 2) even++;
                //cout << b[i][j] << ' ';
            }
            //cout << endl;
        }
        if(odd == 0 && even == 0) even++;
        cout << "Case " << t << ": " << even << ' ' << odd << endl;
    }
    return 0;
}
