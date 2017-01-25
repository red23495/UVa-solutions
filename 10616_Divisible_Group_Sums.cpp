#include<bits/stdc++.h>

using namespace std;
//might contain some bugs
//still gets AC
int n,q,s,d,m;
int v[200];
long long memo[200][10][41];
long long backtrack(int index, int left, int sum){
    if(left == 0) {
        if(sum) return 0;
        else return 1;
    }
    if(index == n) return 0;
    if(memo[index][left][20+sum] != -1) return memo[index][left][20+sum];
    long long s = sum+v[index];
    s %= d;
    memo[index][left][20+sum] = backtrack(index+1,left-1,s)+backtrack(index+1,left,sum);
    return memo[index][left][20+sum];
}

int main(){
    while(cin >> n >> q && n){
        s++; cout << "SET " << s << ":\n";
        for(int i = 0; i < n; i++) cin >> v[i];
        for(int i = 1; i <= q; i++){
            cin >> d >> m;
            memset(memo,-1,sizeof (memo));
            long long a = backtrack(0,m,0);
            cout <<"QUERY "<< i << ": " << a << endl;
        }
    }
    return 0;
}
