#include<bits/stdc++.h>

using namespace std;
int m,n;
vector<vector<int>> v;
vector<int> color;

int bi(int p,int c){
    color[p] = c;
    int ret = 1;
    for(auto x: v[p]){
        if(ret == -1) break;
        if(color[x] == 0){
            int t = bi(x,-c);
            if(t == -1) return -1;
            ret = ret+t;
        }
        else if(color[x] == c) ret = -1;
    }
    return ret;
}

int main(){
    int test;
    cin >> test;
    while(test--){
        cin >> m >> n;
        v.clear();
        v.resize(m);
        color.clear();
        color.resize(m);
        while(n--){
            int a,b;
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        int ans = 0;
        for(int i = 0; i < m; i++){
            if(color[i] == 0){
                int a=0,b=0,t;
                t = bi(i,1);
                if(t == -1) {ans = -1; break;}
                for(auto& x : color){
                    if(x == 1 || x == -1){
                        if(x == 1) a++;
                        if(x == -1) b++;
                        x = 2;
                    }
                }
                if(!(a && b)) ans++;
                else ans += min(a,b);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
