#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> v;
vector<string> id2name;
map<string,int> name2id;
int n,m;

int main(){
    int test = 1;
    while(cin >> n >> m && n){
        v.clear();
        name2id.clear();
        id2name.clear();
        v.resize(n,vector<int>(n,-1));
        while(m--){
            string s1,s2;
            cin >> s1 >> s2;
            int x,y;
            if(!name2id.count(s1)){
                name2id[s1] = id2name.size();
                id2name.push_back(s1);
            }
            if(!name2id.count(s2)){
                name2id[s2] = id2name.size();
                id2name.push_back(s2);
            }
            x = name2id[s1]; y = name2id[s2];
            v[x][y] = 1;
            v[y][x] = 1;
        }
        for(int i = 0; i < n; i++) v[i][i] = 0;
        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(v[i][k] != -1 && v[k][j] != -1){
                        if(v[i][j] != -1)v[i][j] = min(v[i][j],v[i][k]+v[k][j]);
                        else v[i][j] = v[i][k]+v[k][j];
                    }
                }
            }
        }
        int ans = -1;
        /*for(int i = 0; i < n && ans; i++){
            for(int j = 0; j < n && ans; j++){
                cout << v[i][j] << ' ';
            }
            cout << endl;
        }*/
        for(int i = 0; i < n && ans; i++){
            for(int j = 0; j < n && ans; j++){
                if(i!=j){
                    ans = max(ans,v[i][j]);
                    if(v[i][j] == -1) ans = 0;
                }
            }
        }
        cout << "Network " << test++ << ": ";
        if(ans) cout << ans << endl;
        else cout << "DISCONNECTED\n";
        cout << endl;
    }
    return 0;
}
