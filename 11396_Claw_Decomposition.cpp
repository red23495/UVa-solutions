#include<bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> v;
vector<int> color;
bool bi(int p, int c){
    color[p] = c;
    bool ret = true;
    for(auto x: v[p]){
        if(!ret) break;
        if(color[x] == 0) ret &= bi(x,-c);
        else if(color[x] == c) ret = false;
    }
    return ret;
}

int main(){
    while(cin >> n && n){
        v.clear();
        v.resize(n);
        int a,b;
        while(cin >> a >> b && a){
            a--;b--;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        color.clear();
        color.resize(n);
        if(bi(0,1)) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
