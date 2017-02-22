#include<bits/stdc++.h>

using namespace std;

int l,u,r;
int v[10000];
vector<int> button;

int main(){
    int t = 1;
    while(cin >> l >> u >> r && r){
        memset(v,0,sizeof v);
        queue<int> q;
        button.clear();
        button.resize(r);
        for(int i = 0; i < r; i++){
            cin >> button[i];
        }
        q.push(l);
        v[l] = 1;
        int ans = -1;
        while(!q.empty()){
            int p = q.front();
            q.pop();
            if(p == u) {ans = v[p] -1;break;}
            for(int i = 0; i < r; i++){
                int c = button[i]+p;
                c %= 10000;
                if(!v[c]){
                    v[c] = v[p]+1;
                    q.push(c);
                }
            }
        }
        cout << "Case " << t++ << ": ";
        if(ans == -1) cout << "Permanently Locked\n";
        else cout << ans << endl;
    }
    return 0;
}
