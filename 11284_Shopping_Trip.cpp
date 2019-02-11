#include<bits/stdc++.h>

using namespace std;

#define FASTIO ios::sync_with_stdio(0);cin.tie(0);

int N,M,O;

struct Opera{
    int location;
    int profit;
};

int road[55][55];

vector<Opera> operas;

int mem[15][10000];
int flg[15][10000];

int dp(int store, int mask){
    //cout << store << ' ' << mask << ' ' << flg[store][mask] << endl;
    if(flg[store][mask]) return mem[store][mask];
    int cur_location = operas[store].location;
    int cur_profit = operas[store].profit;
    int ret = cur_profit-road[cur_location][0];
    for(int i = 1; i < O+1; i++){
        if(!(mask&(1<<i))){
            ret = max(ret,cur_profit-road[cur_location][operas[i].location]+dp(i,mask|(1<<i)));
        }
    }
    flg[store][mask] = 1;
    mem[store][mask] = ret;
    //cout << store << ' ' << mask << ' ' << ret << endl;
    return ret;
}

int main(){
    FASTIO
    int test;
    cin >> test;
    while(test--){
        cin >> N >> M;
        for(int i = 0; i < N+1; i++) for(int j = 0; j < N+1; j++){
                road[i][j] = 1e9;
                if(i == j) road[i][j] = 0;
        }
        for(int i = 0; i < M; i++) {
            int a,b; double n;
            cin >> a >> b >> n;
            road[a][b] = min(road[a][b],int((n+1e-6)*100));
            road[b][a] = min(road[b][a],int((n+1e-6)*100));
        }
        for(int k = 0; k < N+1; k++){
            for(int i = 0; i < N+1; i++){
                for(int j = 0; j < N+1; j++){
                    road[i][j] = min(road[i][j],road[i][k]+road[k][j]);
                }
            }
        }
        road[0][0] = 1e9;
        operas.clear();
        cin >> O;
        operas.push_back({0,0});
        for(int i = 0; i < O; i++){
            int a; double b;
            cin >> a >> b;
            operas.push_back({a,int((b+1e-6)*100)});
        }
        memset(flg,0,sizeof flg);
        int ans = dp(0,1);
        if(ans <= 0) cout << "Don't leave the house\n";
        else cout << "Daniel can save $" << fixed << setprecision(2) << (ans/100.00) << endl;
    }
    return 0;
}
