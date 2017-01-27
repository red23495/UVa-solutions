#include <iostream>
#include <algorithm>
#include <cmath>
#include<cstring>
#include<iomanip>
using namespace std;

int n,x,t,k;
int p[105],f[105];
int memo[105][10005][25];
int backtrack(int index, int money, int c){
    int cost = money+(n+1)*t;
    cost = ceil(((double)cost*1.1));
    if(cost > (n+1)*x) return -999999;
    if(cost == x*(n+1)) return 0;
    if(c == 2*(n+1)) return 0;
    if(c > 2*(n+1)) return -999999;
    if(index < 0) return 0;
    if(memo[index][money][c] != -1) return memo[index][money][c];
    memo[index][money][c] =
            max(backtrack(index-1,money,c),
            max(f[index]+backtrack(index-1,money+p[index],c+1),
                2*f[index]+backtrack(index-1,money+2*p[index],c+2)));
    return memo[index][money][c];
}

int main(){
    while(cin >> n >> x >> t >> k && n){
        for(int i = 0;i < k; i++){
            cin >> p[i];
            int s = 0;
            for(int j = 0; j < n+1; j++){
                int x;
                cin >> x;
                s+=x;
            }
            f[i] = s;
        }
        memset(memo,-1,sizeof memo);
        int ans = backtrack(k-1,0,0);
        cout << fixed << setprecision(2) << double(double(ans)/(double)(n+1)) << endl;
    }
    return 0;
}
