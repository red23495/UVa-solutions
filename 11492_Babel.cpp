#include<bits/stdc++.h>

using namespace std;
using ic = pair<int,char>;
int main(){
    int n;
    while(cin >> n && n){
        map<string,int> m;
        vector<vector<pair<ic,int>>> v;
        string s1,s2,s3;
        cin >> s1 >> s2;
        m[s1] = 0;
        m[s2] = 1;
        v.resize(2);
        while(n--){
            cin >> s1 >> s2 >> s3;
            if(!m.count(s1)){
                m[s1] = v.size();
                v.push_back(vector<pair<ic,int>>());
            }
            if(!m.count(s2)){
                m[s2] = v.size();
                v.push_back(vector<pair<ic,int>>());
            }
            int p1 = m[s1], p2 = m[s2];
            v[p1].push_back({{s3.length(),s3[0]},p2});
            v[p2].push_back({{s3.length(),s3[0]},p1});
        }
        priority_queue<pair<ic,int>,vector<pair<ic,int>>,greater<pair<ic,int>>> pq;
        pq.push({{0,'\0'},0});
        vector<vector<int>> cost(v.size(),vector<int>(256,INT_MAX));
        int ans = -1;
        while(!pq.empty()){
            auto p = pq.top();pq.pop();
            int x = p.second, w = p.first.first;char wc = p.first.second;
            //cout <<"c " <<x << ' ' << w << ' ' << wc << endl;
            if(x == 1) {ans = w; break;}
            if(cost[x][wc] > w){
                cost[x][wc] = w;
                for(int i = 0; i < v[x].size(); i++){
                    //cout << v[x][i].first.first << ' ' << v[x][i].first.second<< ' ' << v[x][i].second << endl;
                    if(v[x][i].first.second != wc){
                        //cout << "h\n";
                        int d = w+v[x][i].first.first;
                        pq.push({{d,v[x][i].first.second},v[x][i].second});
                    }
                }
            }
        }
        if(ans == -1) cout << "impossivel\n";
        else cout << ans << endl;
    }
    return 0;
}
