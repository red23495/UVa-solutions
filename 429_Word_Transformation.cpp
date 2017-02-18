#include<bits/stdc++.h>

using namespace std;

vector<string> dict;
map<string,int> m;
vector<vector<int>> v;

bool comp(string s1, string s2){
    if(s1.length() != s2.length()) return false;
    int cnt = 0;
    for(int i = 0; i < s1.length(); i++) if(s1[i] == s2[i]) cnt++;
    if(s1.length() - cnt == 1) return true;
    return false;
}

int main(){
    int test;
    cin >> test;
    while(test--){
        string s;
        dict.clear();
        m.clear();
        while(cin >> s && s[0] != '*'){
            m[s] = dict.size();
            dict.push_back(move(s));
        }
        v.clear();
        v.resize(dict.size());
        for(int i = 0; i < dict.size(); i++){
            for(int j = i+1; j < dict.size(); j++){
                if(comp(dict[i],dict[j])){
                    v[i].push_back(j);v[j].push_back(i);
                }
            }
        }
        /*for(int i = 0; i < dict.size(); i++){
            cout << dict[i] << ' ';
            for(int j = 0; j < v[i].size(); j++){
                cout << dict[v[i][j]] << ' ';
            }
            cout << endl;
        }*/
        if(cin.peek() == 10) cin.ignore();
        while(getline(cin,s) && s.size()){
            stringstream ss(s);
            string s1,s2;
            ss >> s1 >> s2;
            int x = m[s1], y = m[s2];
            //cout << x << ' ' <<y << endl;
            queue<int> q;
            q.push(x);
            vector<int> level(dict.size(),INT_MAX);
            level[x] = 0;
            int ans = 0;
            while(!q.empty()){
                int p = q.front();
                q.pop();
                if(p == y) break;
                //cout << level[p] << ' '<< v[p][0] << endl;
                for(int i = 0; i < v[p].size(); i++){
                    if(level[v[p][i]] == INT_MAX){
                        q.push(v[p][i]);
                        level[v[p][i]] = level[p]+1;
                    }
                }
            }
            cout << s1 << ' ' << s2 << ' ' << level[m[s2]] << endl;
        }
        if(test)cout << endl;
    }
    return 0;
}
