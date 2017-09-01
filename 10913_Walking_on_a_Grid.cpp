#include<bits/stdc++.h>

using namespace std;

long long board[75][75],memo[75][75][3][6],n,k;

long long backtrack(int r, int c, int dir, int neg){
    //cout << r << ' ' << c << ' ' << dir << ' ' << neg << endl;
    if(r < 0 || r >= n || c < 0 || c >= n) return -10000;
    if(board[r][c] < 0) neg--;
    if(neg < 0) return -10000;
    if(r == n-1 && c == n-1) return memo[r][c][dir][neg] = board[n-1][n-1];
    if(memo[r][c][dir][neg] != -1) return memo[r][c][dir][neg];
    int ans = -10000;
    if(dir == 0) ans = max(backtrack(r+1,c,0,neg),max(backtrack(r,c-1,1,neg),backtrack(r,c+1,2,neg)));
    if(dir == 1) ans = max(backtrack(r,c-1,1,neg),backtrack(r+1,c,0,neg));
    if(dir == 2) ans = max(backtrack(r,c+1,2,neg),backtrack(r+1,c,0,neg));
    if(ans == -10000) return memo[r][c][dir][neg] = -10000;
    return memo[r][c][dir][neg] = board[r][c]+ans;
}

int main(){
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    int test = 1;
    while(cin >> n >> k && n){
        for(int i = 0; i < n ; i++){
            for(int j = 0; j < n; j++){
                cin >> board[i][j];
            }
        }
        memset(memo,-1,sizeof memo);
        long long ans = backtrack(0,0,0,k);
        cout << "Case " << test++ <<": ";
        if(ans == -10000) cout << "impossible\n";
        else cout << ans << endl;
    }
    return 0;
}
