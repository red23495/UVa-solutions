#include<bits/stdc++.h>

using namespace std;

int board[105][105],memo[105][105],n;
int mod = 1000007;
int dp(int r, int c){
    if(r == 0) return 1;
    if(memo[r][c] != -1) return memo[r][c];
    int ans = 0;
    if(c + 1 < n){
        if(!board[r-1][c+1]) ans += dp(r-1,c+1);
        else if(c + 2 < n && !board[r-2][c+2]) ans += dp(r-2,c+2);
    }
    if(c - 1 >= 0){
        if(!board[r-1][c-1]) ans += dp(r-1,c-1);
        else if(c-2 >= 0 && !board[r-2][c-2]) ans += dp(r-2,c-2);
    }
    return memo[r][c] = ans%mod;
}

int main(){
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    int test;
    cin >> test;
    for(int t = 1; t <= test; t++){
        cin >> n;
        memset(board,0,sizeof board);
        string s;
        int start_row,start_column;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                char c;
                cin >> c;
                if(c == 'B') board[i][j] = 1;
                else if(c == 'W'){
                    start_row = i; start_column = j;
                }
            }
        }
        memset(memo,-1,sizeof memo);
        cout << "Case "<<t<<": "<<dp(start_row,start_column)<< endl;
    }
    return 0;
}
