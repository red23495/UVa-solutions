#include<bits/stdc++.h>

using namespace std;
using ii = pair<int,int>;
int v[2001][2001];

bool process(int i, int j,int x, int y, queue<ii>& q){
    //cout << i << ' ' << j << ' ' << x << ' '  << y << endl;
    if(i<0 || i > 2000 || j < 0||j > 2000) return false;
    if(v[i][j] == -1) return true;
    if(!v[i][j]){
        v[i][j] = v[x][y]+1;
        q.push({i,j});
    }
    return false;
}

int main(){
    int p,x,y;
    while(cin >> p && p){
        queue<ii> q;
        memset(v, 0, sizeof v);
        while(p--){
            cin >> x >> y;
            v[x][y] = 1;
            q.push({x,y});
        }
        cin >> p;
        while(p--){
            cin >> x >> y;
            v[x][y] = -1;
        }
        int ans = 0;
        while(!q.empty() && !ans){
            ii p = q.front();
            q.pop();
            x = p.first; y = p.second;
            //cout << x << ' ' << y << endl;
            if(process(x-1,y,x,y,q) || process(x+1,y,x,y,q)||process(x,y-1,x,y,q)||process(x,y+1,x,y,q))
                ans = v[x][y];
            //cout << ans << endl;
            /*cout << q.size() << endl;
            for(int i = 0; i < 10; i++){
                for(int j = 0; j < 10; j++)
                    cout << v[i][j] << ' ';
                cout << endl;
            }*/
        }
        cout << ans << endl;
    }
    return 0;
}
