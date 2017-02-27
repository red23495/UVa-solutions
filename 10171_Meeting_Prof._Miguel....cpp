#include<bits/stdc++.h>

using namespace std;

int vY[26][26],vM[26][26];
int n;

int main(){
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    while(cin >> n && n){
        for(int i = 0; i < 26; i++){
            for(int j = 0; j < 26; j++){
                if(i == j) {vY[i][j] = 0;vM[i][j] = 0;}
                else {vY[i][j] = INT_MAX;vM[i][j] = INT_MAX;}
            }
        }
        char a,d,f,t;int c;
        while(n--){
            cin >> a >> d >> f >> t >> c;
            if(a == 'Y'){
                int x = f-'A', y = t-'A';
                vY[x][y] = min(c,vY[x][y]);
                if(d == 'B') vY[y][x] = min(c,vY[y][x]);
            }
            else{
                int x = f-'A', y = t-'A';
                vM[x][y] = min(c,vM[x][y]);
                if(d == 'B') vM[y][x] = min(c,vM[y][x]);
            }
        }
        cin >> f >> t;
        for(int k = 0; k < 26; k++){
            for(int i = 0; i < 26; i++){
                for(int j = 0; j < 26; j++){
                    if(vY[i][k] == INT_MAX || vY[k][j] == INT_MAX) continue;
                    vY[i][j] = min(vY[i][j],vY[i][k]+vY[k][j]);
                }
            }
        }
        for(int k = 0; k < 26; k++){
            for(int i = 0; i < 26; i++){
                for(int j = 0; j < 26; j++){
                    if(vM[i][k] == INT_MAX || vM[k][j] == INT_MAX) continue;
                    vM[i][j] = min(vM[i][j],vM[i][k]+vM[k][j]);
                }
            }
        }
        int cost = INT_MAX, x = f-'A', y = t - 'A';
        vector<char> ans;
        for(int i = 0; i < 26; i++){
            if(vY[x][i] == INT_MAX || vM[y][i] == INT_MAX) continue;
            int sum = vY[x][i]+vM[y][i];
            if(sum < cost){
                cost = sum;
                ans.clear();
                ans.push_back(char(i+'A'));
            }else if(sum == cost) ans.push_back(char(i+'A'));
        }
        if(!ans.size()) cout << "You will never meet.\n";
        else{
            cout << cost;
            for(auto x: ans ) cout << ' ' << x;
            cout << endl;
        }
    }
    return 0;
}
