#include<bits/stdc++.h>

using namespace std;

vector<string> v;
int test;
vector<vector<bool>> visited;
int dfs(int row, int col){
    visited[row][col] = true;
    int t = 1;
    for(int i = -1; i < 2; i++){
        for(int j = -1; j < 2; j++){
            int x = row+i; int y = col + j;
            if(x >= 0 && x < v.size() && y >= 0 && y < v[0].length() && !visited[x][y] && v[x][y] == 'W')
                t += dfs(x,y);
        }
    }
    return t;
}

int main(){
    cin >> test;
    while(test--){
        visited.clear();
        v.clear();
        while(cin.peek() == '\n') cin.ignore();
        while(cin.peek() == 'W' || cin.peek() == 'L'){
            string s;
            getline(cin,s);
            v.push_back(s);
        }
        string s;
        while(getline(cin,s) && !s.empty()){
            stringstream ss(s);
            int r,c;
            ss >> r >> c;
            r--;c--;
            visited.clear();
            visited.resize(v.size(),vector<bool>(v[0].length()));
            cout << dfs(r,c) << endl;
        }
        if(test) cout << endl;
    }
    return 0;
}
