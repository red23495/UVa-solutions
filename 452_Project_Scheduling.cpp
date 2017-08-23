#include<bits/stdc++.h>

using namespace std;

#define HASH(I) (I-'A')

vector<vector<int>> v;
vector<int> parents,visited;
int memo[30];
int w[30];
int inDegree[30];

int dfs(int p){
    if(visited[p]) return memo[p];
    if(!v[p].size()) return w[p];
    visited[p] = 1;
    int c = v[p].size();
    int max_val = 0;
    for(int i = 0; i < c; i++){
        max_val = max(max_val,dfs(v[p][i]));
    }
    memo[p] = w[p]+max_val;
    return memo[p];
}

int main(){
    int test;
    cin >> test;
    while(cin.peek() == '\n') cin.ignore();
    while(test--){
        string s;
        v.clear();
        v.resize(26);
        parents.clear();
        parents.resize(26);
        memset(w,0,sizeof w);
        memset(memo,0,sizeof memo);
        memset(inDegree,0,sizeof inDegree);
        while(getline(cin,s,'\n') && s.size()){
            stringstream ss(s);
            char c;int n;
            ss >> c >> n;
            int p = HASH(c);
            w[p] = n;
            while(ss >> c){
                v[p].push_back(HASH(c));
                inDegree[HASH(c)]++;
            }
        }
        for(int i = 0; i < 26; i++){
            if(!inDegree[i]) parents.push_back(i);
        }
        int time = 0;
        for(int i = 0; i < parents.size(); i++){
            visited.clear();
            visited.resize(30);
            time = max(time,dfs(parents[i]));
        }
        cout << time << endl;
        if(test) cout << endl;
    }
    return 0;
}
