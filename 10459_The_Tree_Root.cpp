#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> v;
int memo[5002][5002];
int diameter(int node,int parent){
    if(memo[node][parent] != -1) return memo[node][parent];
    int ans = -1;
    for(int i = 0; i < v[node].size(); i++){
        if(v[node][i] != parent){
            ans = max(ans,diameter(v[node][i],node));
        }
    }
    return memo[node][parent] = ans+1;
}

int main(){
    int n;
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    while(cin >> n){
        v.clear();
        v.resize(n+1);
        for(int i = 1; i <= n; i++){
            int c;
            cin >> c;
            while(c--){
                int x;
                cin >> x;
                v[i].push_back(x);
            }
        }
        vector<int> result(n+1);
        memset(memo,-1,sizeof memo);
        int d_max = INT_MIN, d_min = INT_MAX;
        for(int i = 1; i <= n; i++){
            int temp = diameter(i,0);
            d_max = max(d_max,temp);
            d_min = min(d_min,temp);
            result[i] = temp;
        }
        cout <<"Best Roots  :";
        for(int i = 1; i <= n; i++){
            if(result[i] == d_min) cout << ' ' << i;
        }
        cout << endl;
        cout << "Worst Roots :";
        for(int i = 1; i <= n; i++){
            if(result[i] == d_max) cout << ' ' << i;
        }
        cout << endl;
    }
    return 0;
}
