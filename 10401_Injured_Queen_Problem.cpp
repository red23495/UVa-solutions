#include<bits/stdc++.h>

using namespace std;

int n;
long long board[16],memo[16][16];

int char2num(char c){
    if(c >= '0' && c <= '9') return (c-'0');
    return 10+(c-'A');
}

long long dp(int r, int c){
    if(r <= 0 || r > n || c <= 0 && c > n) return 0;
    //cout << r << ' ' << c << endl;
    if(memo[r][c] != -1) return memo[r][c];
    long long ans = 0;
    if(board[c+1] != -1){
        if(board[c+1] == r-1 || board[c+1] == r+1 || board[c+1] == r) return 0;
        ans += dp(board[c+1],c+1);
    }
    else{
        for(int i = 1; i <= n; i++){
            if(i == r-1 || i == r+1 || i == r) continue;
            ans += dp(i,c+1);
        }
    }
    return memo[r][c] = ans;
}

int main(){
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    string s;
    while(cin >> s){
        n = s.length();
        memset(board,-1,sizeof board);
        for(int i = 0; i < n; i++){
            if(s[i] != '?'){
                board[i+1] = char2num(s[i]);
            }
        }
        memset(memo,-1,sizeof memo);
        for(int i = 1; i <= n; i++) memo[i][n] = 1;
        long long ans = 0;
        for(int i = 1; i <= n; i++){
            if(board[1] == -1 || board[1] == i)
            ans += dp(i,1);
        }
        cout << ans << endl;
    }
    return 0;
}
