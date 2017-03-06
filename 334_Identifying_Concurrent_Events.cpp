#include<bits/stdc++.h>

using namespace std;

map<string,int> name2id;
vector<string> id2name;
vector<vector<int>> v,memo;
int n;

int main(){
    int test = 1;
    vector<pair<int,int>> ans;
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    while(cin >> n && n){
        name2id.clear();
        id2name.clear();
        v.clear();
        while(n--){
            int a;
            cin >> a;
            for(int i = 0; i < a; i++){
                string b;
                cin >> b;
                name2id[b] = v.size();
                id2name.push_back(b);
                v.push_back(vector<int>());
                if(i) v[name2id[b]-1].push_back(name2id[b]);
            }
        }
        cin >> n;
        while(n--){
            string a,b;
            cin >> a >> b;
            int x = name2id[a], y = name2id[b];
            v[x].push_back(y);
        }
        memo.clear();
        memo.resize(v.size(),vector<int>(v.size(),0));
        for(int i = 0; i < v.size(); i++){
            for(int j = 0; j < v[i].size();j++)
                memo[i][v[i][j]] = 1;
        }
        for(int k = 0; k < v.size(); k++){
            for(int i = 0; i < v.size(); i++){
                for(int j = 0; j < v.size(); j++){
                    memo[i][j] |= (memo[i][k] & memo[k][j]);
                }
            }
        }
        /*for(int i = 0; i < memo.size(); i++){
            for(int j = 0; j < memo.size(); j++){
                cout << memo[i][j] << ' ';
            }
            cout << endl;
        }*/
        ans.clear();
        int cnt = 0;
        for(int i = 0; i < v.size(); i++){
            for(int j = i+1; j < v.size(); j++){
                if(!memo[i][j] && !memo[j][i]){
                    cnt++;
                    if(ans.size() < 2) ans.push_back({i,j});
                }
            }
        }
        cout << "Case " << test++<<", ";
        if(cnt) cout << cnt <<" concurrent events:\n";
        else cout << "no concurrent events.\n";
        for(int i = 0; i < ans.size(); i++){
            cout << '(' << id2name[ans[i].first] << ',' << id2name[ans[i].second] << ") ";
            if(i == ans.size()-1) cout << endl;
        }
    }
    return 0;
}
