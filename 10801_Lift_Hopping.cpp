#include<bits/stdc++.h>

using namespace std;
using ii = pair<int,int>;
using iii = pair<int,ii>;

int n,k;
int t[5];
vector<vector<vector<int>>> v;

int abs(int a){return ((a < 0)?-a:a);}

int main(){
    while(cin >> n >> k){
        v.clear();
        v.resize(100,vector<vector<int>>(n));
        for(int i = 0; i < n; i++) cin >> t[i];
        while(cin.peek() == 10) cin.ignore();
        string s;
        for(int i = 0; i < n; i++){
            getline(cin,s);
            stringstream ss(s);
            int x,y;
            ss >> x;
            while(ss>>y){
                v[x][i].push_back(y);
                v[y][i].push_back(x);
                x = y;
            }
        }
        vector<vector<int>> cost(100,vector<int>(n,INT_MAX));
        priority_queue<iii,vector<iii>,greater<iii>> pq;
        for(int i = 0; i < n; i++){
            if(v[0][i].size()) pq.push({0,{0,i}});
        }
        int ans = -1;
        //cout << pq.size() << endl;
        while(!pq.empty()){
            iii p = pq.top();pq.pop();
            int f = p.second.first, l = p.second.second, w = p.first;
            //cout << f << ' ' << l << ' ' << w << endl;
            if(f == k) {ans = w; break;}
            if(cost[f][l] > w){
                cost[f][l] = w;
                for(int i = 0; i < n; i++){
                    for(int j = 0; j < v[f][i].size(); j++){
                        int b = w+abs(v[f][i][j]-f)*t[i];
                        if(i != l) b+=60;
                        pq.push({b,{v[f][i][j],i}});
                    }
                }
            }
        }
        if(ans == -1) cout << "IMPOSSIBLE\n";
        else cout << ans << endl;
    }
    return 0;
}
