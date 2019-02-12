#include<bits/stdc++.h>

using namespace std;

#define FASTIO ios::sync_with_stdio(0);cin.tie(0);

int X;
int wind[1015][15];
int mem[1015][15];

int dp(int location, int altitude){
    if(location == X && altitude == 0) return 0;
    if(location >= X) return 1e9;
    if(altitude > 9 || altitude < 0) return 1e9;
    if(mem[location][altitude] != -1) return mem[location][altitude];
    int stay = 30-wind[location][altitude]+dp(location+1,altitude);
    int rise = 60-wind[location][altitude]+dp(location+1,altitude+1);
    int fall = 20-wind[location][altitude]+dp(location+1,altitude-1);
    return mem[location][altitude] = min(stay,(min(rise,fall)));
}

int main(){
    int test;
    cin >> test;
    while(test--){
        cin >> X;
        X /= 100;
        for(int i = 9; i >= 0; i--){
            for(int j = 0; j < X; j++){
                cin >> wind[j][i];
            }
        }
        memset(mem,-1,sizeof mem);
        int ans = dp(0,0);
        cout << ans << "\n\n";
    }
    return 0;
}
