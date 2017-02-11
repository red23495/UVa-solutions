#include<bits/stdc++.h>

using namespace std;

int n;
vector<string> v;

int fill(int i, int j){
    int ret = 0;
    if(v[i][j] == 'x') ret = 1;
    v[i][j] = '.';
    if(i > 0 && v[i-1][j] != '.') ret |= fill(i-1,j);
    if(i < n-1 && v[i+1][j] != '.') ret |= fill(i+1,j);
    if(j > 0 && v[i][j-1] != '.') ret |= fill(i,j-1);
    if(j < n-1 && v[i][j+1] != '.') ret |= fill(i,j+1);
    return ret;
}

int main(){
    int test;
    cin >> test;
    for(int t = 1; t <= test; t++){
        cin >> n;
        v.resize(n);
        for(auto& x: v) cin >> x;
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(v[i][j] != '.')
                    ans += fill(i,j);
            }
        }
        cout << "Case " << t << ": " << ans << endl;
    }
    return 0;
}
